"""백준 14940 · 쉬운 최단거리
https://www.acmicpc.net/problem/14940
"""

import sys


def solve(rows, cols, grid):
    # TODO: 출력할 rows × cols 정수 표를 구해 반환한다.
    pass


def main():
    read = sys.stdin.readline
    rows, cols = map(int, read().split())
    grid = [list(map(int, read().split())) for _ in range(rows)]
    result = solve(rows, cols, grid)
    if result is not None:
        for row in result:
            print(*row)


if __name__ == "__main__":
    main()
