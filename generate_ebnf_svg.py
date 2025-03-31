from tree_sitter import Language, Parser
from RRD.railroad import Diagram, Choice, Sequence, OptionalSequence, HorizontalChoice, OneOrMore, ZeroOrMore, Optional
import io
import csv
import os
from IPython.display import SVG, display

# 构建语言
Language.build_library(
    './build/my-ebnf2.so',  
    ['./tree-sitter-ebnf'] 
)
MY_LANGUAGE = Language('./build/my-ebnf3.so', 'EBNF')

parser = Parser()
parser.set_language(MY_LANGUAGE)

def visit(node, diagrams = {}):
    match(node.type):
        case 'source_file':
            for i in range(len(node.children)):
                diagrams = visit(node.children[i], diagrams)
            return diagrams
        case 'rule':
            name = node.children[0].text.decode()
            diagrams[name] = Diagram(visit(node.children[2]))
            return diagrams
        case 'rhs':
            return visit(node.children[0])
        case 'sequence':
            blocks = []
            for child in node.children:
                blocks.append(visit(child))
            return Sequence(*blocks)
        case 'statements':
            return visit(node.children[0])
        case 'parenthesizedStatement':
            return visit(node.children[1])
        case 'quantifiedStatement':
            return visit(node.children[0])
        case 'selectionStatement':
            blocks = []
            for child in node.children:
                if child.type == 'sequenceNoSelection':
                    blocks.append(visit(child))
            return Choice(len(blocks)//2, *blocks)
        case 'sequenceNoSelection':
            blocks = []
            for child in node.children:
                blocks.append(visit(child))
            return Sequence(*blocks)
        case 'statementsNoSelection':
            return visit(node.children[0])
        case 'optional':
            return Optional(visit(node.children[0]))
        case 'oneOrMore':
            return OneOrMore(visit(node.children[0]))
        case 'zeroOrMore':
            return ZeroOrMore(visit(node.children[0]))
        case 'quantifierBase':
            return visit(node.children[0])
        case 'identifier':
            return node.text.decode()
        case _:
            if len(node.children) > 0:
                print('Not implemented: ' + str(node.type))
                for i in range(len(node.children)):
                    return visit(node.children[i])

def generate_ebnf_svg(input_file, output_dir="svg_output"):
    # 确保输出目录存在
    os.makedirs(output_dir, exist_ok=True)
    
    report = []
    
    with open(input_file, "r", encoding="utf-8") as f:
        lines = f.readlines()
    
    for line_num, line in enumerate(lines):
        line = line.strip()
        
        if not line or '::=' not in line:
            continue
    
        try:
            left, right = map(str.strip, line.split("::=", 1))
    
            source_code = (left + ' ::= ' + right + ';').encode("utf-8")
            node = parser.parse(source_code).root_node
            diagrams = visit(node)
    
            d = diagrams[left]
    
            # 生成SVG内容
            outputStream = io.StringIO()
            d.writeStandalone(outputStream.write)
            svg_content = outputStream.getvalue()
    
            # 保存SVG文件
            svg_filename = os.path.join(output_dir, f"{left.replace(' ', '_')}.svg")
            with open(svg_filename, "w", encoding="utf-8") as f:
                f.write(svg_content)
    
            report.append({
                "line": line_num + 1,
                "rule": line,
                "status": "Success",
                "error": "",
                "svg_file": svg_filename
            })
    
        except Exception as e:
            report.append({
                "line": line_num + 1,
                "rule": line,
                "status": "Failed",
                "error": str(e),
                "svg_file": ""
            })
    
    failed = [r for r in report if r['status'] == 'Failed']
    
    # 保存失败报告
    csv_filename = os.path.join(output_dir, "ebnf_failed_rules.csv")
    with open(csv_filename, "w", newline="", encoding="utf-8") as csvfile:
        writer = csv.DictWriter(csvfile, fieldnames=["line", "rule", "error", "svg_file"])
        writer.writeheader()
        for row in failed:
            writer.writerow({"line": row["line"], "rule": row["rule"], "error": row["error"], "svg_file": row["svg_file"]})
    
    print(f"In total {len(report)} rules, and {len(failed)} failed, saved to {csv_filename}")
    return report

if __name__ == "__main__":
    input_file = "tree-sitter-ebnf-generator/examples/lua/lua.ebnf"
    report = generate_ebnf_svg(input_file) 