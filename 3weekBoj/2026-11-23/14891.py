"""백준 14891 · 톱니바퀴
https://www.acmicpc.net/problem/14891
"""

import sys


def solve(gears, commands):
    # TODO: 모든 명령이 끝난 뒤의 점수를 구해 반환한다.
    pass


def main():
    read = sys.stdin.readline
    gears = [read().strip() for _ in range(4)]
    count = int(read())
    commands = [tuple(map(int, read().split())) for _ in range(count)]
    result = solve(gears, commands)
    if result is not None:
        print(result)


if __name__ == "__main__":
    main()
