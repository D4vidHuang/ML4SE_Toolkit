#!/usr/bin/env python3
import re
import sys

# --- Token 定义 ---
class Token:
    def __init__(self, type, value):
        self.type = type  # 如: ASSIGN, ARROW, NUMBER, REGEX, STRING, IDENTIFIER, SYMBOL, SKIP
        self.value = value
    def __repr__(self):
        return f"Token({self.type!r}, {self.value!r})"

def tokenize(text):
    token_specification = [
        ('ASSIGN',    r'::=|:='),                           # 赋值运算符
        ('ARROW',     r'=>'),                               # 箭头
        ('NUMBER',    r'-?\d+'),                            # 整数（包括负数）
        ('REGEX',     r'/([^/\\]|\\.)*/'),                  # /.../ 正则表达式
        ('STRING',    r'"(?:\\.|[^"\\])*"'),                # 双引号字符串（支持转义）
        ('IDENTIFIER',r'[a-zA-Z_$][a-zA-Z0-9_$]*'),          # 标识符（允许 $）
        ('SYMBOL',    r'[;{}()\[\]|,*\+\?\-<>:\.@#]'),        # 其他符号
        ('SKIP',      r'[ \t\n\r]+'),                       # 空白字符
    ]
    tok_regex = '|'.join(f"(?P<{name}>{pattern})" for name, pattern in token_specification)
    for mo in re.finditer(tok_regex, text):
        kind = mo.lastgroup
        value = mo.group()
        if kind == 'SKIP':
            continue
        yield Token(kind, value)

# --- Parser ---
# AST 节点示例：
#   production: ('production', 规则名, expr)
#   alternation: ('alternation', [expr1, expr2, ...])
#   sequence: ('sequence', [expr1, expr2, ...])
#   repetition: ('repetition', expr)   -> ZeroOrMore
#   one_or_more: ('one_or_more', expr)  -> OneOrMore
#   optional: ('optional', expr)        -> Optional
#   terminal: ('terminal', text)
#   nonterminal: ('nonterminal', name)
#   empty: ('empty',)

class Parser:
    def __init__(self, tokens):
        self.tokens = list(tokens)
        self.pos = 0

    def current(self):
        if self.pos < len(self.tokens):
            return self.tokens[self.pos]
        return None

    def eat(self, token_type=None, token_value=None):
        token = self.current()
        if token is None:
            raise Exception("Unexpected end of input")
        if token_type and token.type != token_type:
            raise Exception(f"Expected token type {token_type} but got {token.type}")
        if token_value and token.value != token_value:
            raise Exception(f"Expected token value {token_value} but got {token.value}")
        self.pos += 1
        return token

    def parse(self):
        productions = []
        while self.current() is not None:
            # 跳过章节标头（例如 "rules:" ）
            if self.current().type == 'IDENTIFIER':
                next_tok = self.tokens[self.pos+1] if self.pos+1 < len(self.tokens) else None
                if next_tok and next_tok.type == 'SYMBOL' and next_tok.value == ':':
                    self.eat('IDENTIFIER')
                    self.eat('SYMBOL', ':')
                    continue
            # 跳过孤立的分号
            if self.current().type == 'SYMBOL' and self.current().value == ';':
                self.eat('SYMBOL', ';')
                continue
            # 如果当前标识符后面跟着 ASSIGN，则认为是一个生产式
            if self.current().type == 'IDENTIFIER':
                next_tok = self.tokens[self.pos+1] if self.pos+1 < len(self.tokens) else None
                if next_tok and next_tok.type == 'ASSIGN':
                    prod = self.parse_production()
                    productions.append(prod)
                    continue
            # 否则跳过当前 token
            self.pos += 1
        return productions

    def parse_production(self):
        # production: IDENTIFIER ASSIGN expression (可选 ';')
        name = self.eat('IDENTIFIER').value
        self.eat('ASSIGN')
        expr = self.parse_expression()  # 顶层表达式无结束符限制
        if self.current() and self.current().type == 'SYMBOL' and self.current().value == ';':
            self.eat('SYMBOL', ';')
        return ('production', name, expr)

    def parse_expression(self, end_symbols=None):
        if end_symbols is None:
            end_symbols = set()
        seq = self.parse_sequence(end_symbols)
        alternatives = [seq]
        while self.current() and self.current().type == 'SYMBOL' and self.current().value == '|':
            self.eat('SYMBOL', '|')
            seq = self.parse_sequence(end_symbols)
            alternatives.append(seq)
        if len(alternatives) == 1:
            return alternatives[0]
        else:
            return ('alternation', alternatives)

    def parse_sequence(self, end_symbols):
        terms = []
        # 直到遇到指定的结束符或 '|' 分隔符
        while self.current() and self.current().value not in end_symbols and self.current().value != '|':
            term = self.parse_term()
            if term is not None:
                terms.append(term)
        if len(terms) == 0:
            return ('empty',)
        elif len(terms) == 1:
            return terms[0]
        else:
            return ('sequence', terms)

    def parse_term(self):
        token = self.current()
        if token is None:
            return None
        if token.type == 'SYMBOL':
            if token.value == '{':
                # 重复: { expression }
                self.eat('SYMBOL', '{')
                expr = self.parse_expression(end_symbols={'}'})
                if self.current() and self.current().value == '}':
                    self.eat('SYMBOL', '}')
                node = ('repetition', expr)
            elif token.value == '[':
                # 可选: [ expression ]
                self.eat('SYMBOL', '[')
                expr = self.parse_expression(end_symbols={']'})
                if self.current() and self.current().value == ']':
                    self.eat('SYMBOL', ']')
                node = ('optional', expr)
            elif token.value == '(':
                # 分组: ( expression )
                self.eat('SYMBOL', '(')
                expr = self.parse_expression(end_symbols={')'})
                if self.current() and self.current().value == ')':
                    self.eat('SYMBOL', ')')
                node = expr
            else:
                # 其他符号作为字面量终结符
                token = self.eat('SYMBOL')
                node = ('terminal', token.value)
        elif token.type == 'STRING':
            token = self.eat('STRING')
            node = ('terminal', token.value[1:-1])
        elif token.type == 'REGEX':
            token = self.eat('REGEX')
            node = ('terminal', token.value)
        elif token.type == 'NUMBER':
            token = self.eat('NUMBER')
            node = ('terminal', token.value)
        elif token.type == 'IDENTIFIER':
            token = self.eat('IDENTIFIER')
            node = ('nonterminal', token.value)
        else:
            self.pos += 1
            return None

        # 处理后缀操作符 *、+、?
        while self.current() and self.current().type == 'SYMBOL' and self.current().value in ('*', '+', '?'):
            op = self.eat('SYMBOL').value
            if op == '*':
                node = ('repetition', node)  # ZeroOrMore
            elif op == '+':
                node = ('one_or_more', node)  # OneOrMore
            elif op == '?':
                node = ('optional', node)
        return node

# --- AST 转换为 railroad 代码 ---
def convert_node(node):
    if isinstance(node, tuple):
        ntype = node[0]
        if ntype == 'production':
            _, name, expr = node
            return convert_node(expr)
        elif ntype == 'alternation':
            alternatives = node[1]
            converted_alts = [convert_node(alt) for alt in alternatives]
            return f"Choice(0, {', '.join(converted_alts)})"
        elif ntype == 'sequence':
            terms = node[1]
            converted_terms = [convert_node(term) for term in terms]
            return f"Sequence({', '.join(converted_terms)})"
        elif ntype == 'repetition':
            expr = node[1]
            return f"ZeroOrMore({convert_node(expr)})"
        elif ntype == 'one_or_more':
            expr = node[1]
            return f"OneOrMore({convert_node(expr)})"
        elif ntype == 'optional':
            expr = node[1]
            return f"Optional({convert_node(expr)})"
        elif ntype == 'terminal':
            text = node[1]
            return f"Terminal({repr(text)})"
        elif ntype == 'nonterminal':
            text = node[1]
            return f"NonTerminal({repr(text)})"
        elif ntype == 'empty':
            return "Skip()"
        else:
            raise Exception("Unknown node type: " + ntype)
    else:
        return str(node)

# --- 主转换函数 ---
def convert_ebnf_to_python(ebnf_text):
    tokens = list(tokenize(ebnf_text))
    parser = Parser(tokens)
    productions = parser.parse()
    code_lines = []
    code_lines.append("from railroad import Diagram, Sequence, Choice, Terminal, NonTerminal, ZeroOrMore, OneOrMore, Optional, Skip")
    code_lines.append("")
    for prod in productions:
        _, name, expr = prod
        diagram_expr = convert_node(expr)
        code_lines.append(f"# Diagram for production: {name}")
        code_lines.append(f"{name}_diagram = Diagram({repr(name)}, {diagram_expr})")
        code_lines.append(f"with open({repr(name + '.svg')}, 'w', encoding='utf-8') as f:")
        code_lines.append(f"    {name}_diagram.writeSvg(f.write)")
        code_lines.append("")
    return "\n".join(code_lines)

# --- 程序入口 ---
if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Usage: python test.py <ebnf_file>")
        sys.exit(1)
    with open(sys.argv[1], 'r', encoding='utf-8') as f:
        ebnf_text = f.read()
    python_code = convert_ebnf_to_python(ebnf_text)
    with open("generated_diagrams.py", "w", encoding='utf-8') as out:
        out.write(python_code)
    print("生成的 Python 代码已保存到 generated_diagrams.py")
