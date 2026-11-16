"""프로그래머스 · 네트워크 (그래프 DFS)
https://school.programmers.co.kr/learn/courses/30/lessons/43162
컴퓨터의 연결 정보가 주어질 때 서로 연결된 네트워크의 수를 반환하세요.
힌트: 방문하지 않은 컴퓨터에서 탐색을 시작하고 연결된 컴퓨터를 모두 방문합니다.
"""
def solution(n, computers):
    # TODO: 직접 구현하세요.
    raise NotImplementedError


if __name__ == "__main__":
    cases = [((3, [[1, 1, 0], [1, 1, 0], [0, 0, 1]]), 2),
             ((3, [[1, 1, 0], [1, 1, 1], [0, 1, 1]]), 1),
             ((2, [[1, 0], [0, 1]]), 2)]
    for args, expected in cases:
        try:
            actual = solution(*args)
            print(f"입력={args} | 예상={expected} | 실제={actual} | {'PASS' if actual == expected else 'FAIL'}")
        except NotImplementedError:
            print(f"입력={args} | 예상={expected} | 미구현")
