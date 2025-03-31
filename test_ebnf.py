from RRD.railroad import Terminal, Sequence, Choice, Diagram
from ebnf_visualizer import visualize_ebnf, reset_global_counts

def test_visualization():
    # 重置计数器
    reset_global_counts()
    
    # 创建一个简单的测试图表
    # a ::= b | b | b;  这样b会出现3次
    terminal_b = Terminal("b")
    choice = Choice(0, terminal_b, terminal_b, terminal_b)
    terminal_a = Terminal("a")
    sequence = Sequence(terminal_a, Terminal("::="), choice)
    
    # 第一次可视化
    print("First visualization:")
    visualize_ebnf(sequence)
    
    # 第二次可视化相同的图表
    print("\nSecond visualization:")
    visualize_ebnf(sequence)

if __name__ == "__main__":
    test_visualization() 