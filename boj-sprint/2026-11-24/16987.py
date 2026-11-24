""" 
백준 16987 · 계란으로 계란치기
https://www.acmicpc.net/problem/16987
"""

""" 
각 계란에는 내구도와 무게가 정해져있음 
계란으로 계란을 치게 되면 각 계란의 내구도는 상대 계란의 무게만큼 깎임 

계란 1: 내구도 7, 무게 5 
계란 2: 내구도 3, 무게 4 
계란1 으로 계란 2를 치게되면 
계란1의 내구도 : 7 - 4 = 3 
계란2의 내구도 : 3  -5 = -2 
계란 1은 깨지지 않았고 계란 2는 깨짐 

일렬로 놓인 계란에 대해 왼쪽부터 차례로 들어서 한 번씩만 다른 계란을 쳐 
최대한 많은 계란을 깨는 문제 

1. 가장 왼쪽의 계란을 든다 

2. 손에 들고 있는 계란으로 깨지지 않은 다른 계란 중에서 하나를 침 
손에 든 계란이 깨졌거나 깨지지 않은 다른 계란이 없으면 치지 않고 넘어감 
손에 든 계란을 원래 자리에 내려놓고 3번 과정을 진행 

3. 가장 최근에 든 계란의 한 칸 오른쪽 계란을 손에 들고 2번 과정을 진행.
가장 최근에 든 계란이 가장 오른쪽에 위치한 계란일 경우 계란을 치는 과정을 종료 

최대한 많은 계란을 깨는 것이 목표 
"""

""" 계란의 수 """
n = int(input()) 

""" n개의 계란의 내구도와 무게에 대한 정보 """
arr = [list(map(int, input().split())) for _ in range(n)]

""" 깨진 계란의 수"""
cnt = 0 

""" idx번 차례부터 탐색하는 DFS 함수 """
def dfs(idx, broken_cnt):            
    global cnt 
    if broken_cnt > cnt: 
        cnt = broken_cnt

    """ 종료 조건 """
    if idx == n: 
        return  

    """(내구도가 0이하) 깨진 계란인지 확인 """
    if arr[idx][0] <= 0: 
        return dfs(idx + 1, broken_cnt) 

    for i in range(n): 
        """ 지금 든 계란이 자기 자신인 경우 """ 
        if i == idx: 
            continue 

        """ 이미 깨진 계란인 경우 """
        if arr[i][0] <= 0:
            continue 

        """ 백트래킹 """ 
        arr[idx][0] -= arr[i][1]
        arr[i][0] -= arr[idx][1] 

        next_broken = broken_cnt + (arr[idx][0] <= 0) + (arr[i][0] <= 0)
        dfs(idx + 1, next_broken) 
        
        arr[idx][0] += arr[i][1]
        arr[i][0] += arr[idx][1]

    return 

""" dfs 함수 호출 """
dfs(0, 0)

""" output """
print(cnt)