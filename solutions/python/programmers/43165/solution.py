"""프로그래머스 · 타겟 넘버 (재귀 / DFS)
https://school.programmers.co.kr/learn/courses/30/lessons/43165
각 수에 + 또는 -를 붙여 target을 만드는 방법의 수를 반환하세요.
힌트: 다음 인덱스와 현재 합을 상태로 두고 두 선택의 결과를 합칩니다.
"""

""" 처음 숫자를 더하고 빼는 걸 고려하지 않고 그 다음 수부터 더하고 뺐음"""


def dfs(idx, value, numbers, target):
    """탐색 종료 조건"""
    if idx == len(numbers):
        if value == target:
            return 1 
        return 0 
    
    """(1) 더하는 경우"""
    case1 = dfs(idx + 1, value + numbers[idx], numbers, target)

    """(2) 빼는 경우"""
    case2 = dfs(idx + 1, value - numbers[idx], numbers, target)

    return case1 + case2 


def solution(numbers, target):
    # TODO: 직접 구현하세요.
    # raise NotImplementedError
    result = 0
    result += dfs(0, 0, numbers, target)
    
    return result



if __name__ == "__main__":
    cases = [(([1, 1, 1, 1, 1], 3), 5), (([4, 1, 2, 1], 4), 2), (([1, 1], 3), 0)] 
    for args, expected in cases:
        try:
            actual = solution(*args)
            print(f"입력={args} | 예상={expected} | 실제={actual} | {'PASS' if actual == expected else 'FAIL'}")
        except NotImplementedError:
            print(f"입력={args} | 예상={expected} | 미구현")
