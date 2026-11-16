# 문제 URL: https://swexpertacademy.com/main/code/problem/problemList.do?problemTitle=1989
"""SWEA 1989 · 초심자의 회문 검사"""
import sys

# 회문이면  1 출력, 아니면 0 출력 
def solution(): 
    T = int(input())
    for test_case in range(1, T+1):
        words = input()
        answer = -1
        if words == words[::-1]:
            answer = 1 
        else:
            answer = 0 
        print(f"#{test_case} {answer}")
        


def main():
    if "--sample" in sys.argv:
        from io import StringIO
        from textwrap import dedent

        sample_input = dedent("""\
            3
            level
            abc
            aba
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
