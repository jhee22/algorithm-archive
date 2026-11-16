# 문제 URL: https://swexpertacademy.com/main/code/problem/problemList.do?problemTitle=2001
"""SWEA 2001 · 파리 퇴치"""
import sys


def solution():
    T = int(input())
    for test_case in range(1, T+1):
        n,m = map(int, input().split()) 
        matrix = [list(map(int, input().split())) for _ in range(n)] 
        max_v = -1 

        # 왼쪽 위 시작 위치 
        for start_row in range(n - m + 1):
            for start_col in range(n - m + 1):
                sum = 0
                # 시작 위치에서 m x m 영역 탐색 
                for row in range(start_row, start_row + m): 
                    for col in range(start_col, start_col + m): 
                        # print(matrix[row][col])
                        sum += matrix[row][col] 
                # print(sum) 
                max_v = max(sum, max_v) 
        print(f"#{test_case} {max_v}")
              
    return 


def main():
    if "--sample" in sys.argv:
        from io import StringIO
        from textwrap import dedent

        sample_input = dedent("""\
            2
            5 2
            1 1 1 1 1
            1 2 2 1 1
            1 2 2 1 1
            1 1 1 1 1
            1 1 1 1 1
            5 5
            1 1 1 1 1
            1 1 1 1 1
            1 1 1 1 1
            1 1 1 1 1
            1 1 1 1 1
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
