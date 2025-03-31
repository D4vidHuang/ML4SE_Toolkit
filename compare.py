#!/usr/bin/env python3
import difflib
import sys

def read_file(filename):
    """读取文件内容，并按行返回列表"""
    try:
        with open(filename, 'r', encoding='utf-8') as f:
            return f.readlines()
    except Exception as e:
        print(f"读取文件 {filename} 时出错: {e}")
        sys.exit(1)

def compare_ebnf(file1, file2):
    """对比两个 EBNF 文件内容，并输出差异"""
    lines1 = read_file(file1)
    lines2 = read_file(file2)

    diff = difflib.unified_diff(
        lines1, lines2,
        fromfile=file1,
        tofile=file2,
        lineterm=''
    )
    diff_output = list(diff)
    if diff_output:
        print("发现差异：\n")
        for line in diff_output:
            print(line)
    else:
        print("两个 EBNF 文件内容完全相同。")

def main():
    if len(sys.argv) != 3:
        print("用法: python compare_ebnf.py <ebnf_file1> <ebnf_file2>")
        sys.exit(1)
    file1 = sys.argv[1]
    file2 = sys.argv[2]
    compare_ebnf(file1, file2)

if __name__ == '__main__':
    main()
