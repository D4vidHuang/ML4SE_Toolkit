from RRD.railroad import Diagram, Choice, Sequence, OptionalSequence, HorizontalChoice, OneOrMore, ZeroOrMore, Optional
from IPython.display import SVG, display
import io
import re
import os
import uuid

# 全局计数器，用于记录终端节点的出现次数
global_counts = {}

def count_terminal_nodes(diagram):
    # 局部计数器
    local_counts = {}
    
    def traverse(node):
        if isinstance(node, str):
            # 对于字符串节点（终端节点），增加计数
            if node not in local_counts:
                local_counts[node] = 0
            if node not in global_counts:
                global_counts[node] = 0
            local_counts[node] += 1
            global_counts[node] += 1
        elif hasattr(node, 'items'):
            for item in node.items:
                traverse(item)
        elif hasattr(node, 'item'):
            traverse(node.item)
        elif hasattr(node, 'text'):
            # 处理可能的文本属性
            text = node.text
            if text not in local_counts:
                local_counts[text] = 0
            if text not in global_counts:
                global_counts[text] = 0
            local_counts[text] += 1
            global_counts[text] += 1
    
    traverse(diagram)
    return local_counts, global_counts

def get_color_for_terminal(text, local_count, global_count):
    # 根据终端节点的出现次数生成颜色
    if global_count > 0:
        # 颜色深浅基于该终端节点在当前图中的数量占总体的比例
        ratio = local_count / global_count
        # 使用HSL颜色空间，保持色相120（绿色），饱和度100%，亮度根据比例变化
        lightness = 90 - (ratio * 40)  # 亮度范围从90%到50%
        return f"hsl(120, 100%, {lightness}%)"
    return "hsl(120, 100%, 90%)"  # 默认浅绿色

def visualize_ebnf(diagram):
    # 生成唯一的文件名前缀
    file_prefix = str(uuid.uuid4())[:8]
    
    # 确保输出目录存在
    os.makedirs('svg_output', exist_ok=True)
    
    # 统计终端节点
    local_counts, global_counts = count_terminal_nodes(diagram)
    
    # 将图表转换为SVG字符串
    output_stream = io.StringIO()
    diagram.writeStandalone(output_stream.write)
    svg_content = output_stream.getvalue()
    
    # 保存原始SVG
    original_svg_path = f"svg_output/{file_prefix}_original.svg"
    with open(original_svg_path, "w", encoding='utf-8') as f:
        f.write(svg_content)
    
    # 找到所有terminal-rect类的rect元素并修改颜色
    def replace_color(match):
        full_match = match.group(0)
        text_match = re.search(r'data-text="([^"]*)"', full_match)
        if not text_match:
            return full_match
            
        text = text_match.group(1)
        if text in local_counts:
            color = get_color_for_terminal(text, local_counts[text], global_counts[text])
            # 如果已经有fill属性，替换它
            if 'fill="' in full_match:
                full_match = re.sub(r'fill="[^"]*"', f'fill="{color}"', full_match)
            else:
                # 如果没有fill属性，在结尾的>前添加
                full_match = full_match[:-1] + f' fill="{color}">'
            
            # 打印调试信息
            print(f"Node '{text}': local_count={local_counts[text]}, global_count={global_counts[text]}, color={color}")
        return full_match
    
    # 使用更精确的正则表达式来匹配terminal-rect类的rect元素
    svg_content = re.sub(
        r'<rect[^>]*class="terminal-rect"[^>]*>',
        replace_color,
        svg_content
    )
    
    # 保存修改后的SVG
    final_svg_path = f"svg_output/{file_prefix}_final.svg"
    with open(final_svg_path, "w", encoding='utf-8') as f:
        f.write(svg_content)
    
    print(f"\nSVG files saved in svg_output directory:")
    print(f"1. Original SVG: {file_prefix}_original.svg")
    print(f"2. Final SVG: {file_prefix}_final.svg")
    
    return SVG(data=svg_content)

def reset_global_counts():
    """重置全局计数器"""
    global global_counts
    global_counts = {} 