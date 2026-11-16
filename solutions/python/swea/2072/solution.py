# 문제 URL: https://swexpertacademy.com/main/code/problem/problemList.do?problemTitle=2072
"""SWEA 2072 · 홀수만 더하기"""
import sys


def solution():
    T = int(input()) 
    for test_case in range(1, T+1): 
        number_list = list(map(int, input().split()))
        result = 0 
        for num in number_list: 
            if num % 2 == 1:
                result += num 
        print(f"#{test_case} {result}")
            

def main():
    if "--sample" in sys.argv:
        from io import StringIO
        from textwrap import dedent

        sample_input = dedent("""\
            2
            1 2 3 4 5 6 7 8 9 10
            2 4 6 8 10 12 14 16 18 20
        """)
        original_stdin = sys.stdin
        try:
            sys.stdin = StringIO(sample_input)
            solution()
        finally:
            sys.stdin = original_stdin
    else:
        solution()


if __name__ == "__main__":
    main()
