"""프로그래머스 · 피로도 (완전탐색 / 백트래킹)
https://school.programmers.co.kr/learn/courses/30/lessons/87946
현재 피로도 k와 던전별 [최소 필요 피로도, 소모 피로도]가 주어질 때
탐험할 수 있는 최대 던전 수를 반환하세요. 같은 던전은 한 번만 방문합니다.
힌트: 방문 표시 → 재귀 탐색 → 방문 해제 순서로 가능한 방문 순서를 살펴봅니다.
"""

max_count = 0
count = 0 

def dfs(visited, k, dungeons):
    global max_count, count 

    max_count = max(max_count, count)

    # 던전 방문 시작  
    for i in range(len(dungeons)): 
        require, damage = dungeons[i]
        # 이미 방문한 던전이거나 체력이 안되는 경우  
        if (visited[i]) or (k < require):
            continue

        # 방문 
        visited[i] = True 
        count += 1 
        dfs(visited, k - damage, dungeons)

        # Back 
        count -= 1
        visited[i] = False 
    return

def solution(k, dungeons):
    # TODO: 직접 구현하세요.
    # raise NotImplementedError
    
    # k : 현재 피로도 
    # dungeons : ["최소 필요 피로도", "소모 피로도"] 
    # return : 최대 던전 수 
    
    global max_count, count  
    max_count = 0 
    count = 0

    """ (1) 방문 배열 """ 
    visited = [False] * (len(dungeons)) 

    """ (2) 방문 시작 """
    # 0번째 던전부터 방문 시작 
    dfs(visited, k, dungeons)

    return  max_count


if __name__ == "__main__":
    cases = [((80, [[80, 20], [50, 40], [30, 10]]), 3),
             ((10, [[20, 10]]), 0), ((10, [[10, 10]]), 1),
             ((20, [[10, 10], [10, 10]]), 2)]
    for args, expected in cases:
        try:
            actual = solution(*args)
            print(f"입력={args} | 예상={expected} | 실제={actual} | {'PASS' if actual == expected else 'FAIL'}")
        except NotImplementedError:
            print(f"입력={args} | 예상={expected} | 미구현")
