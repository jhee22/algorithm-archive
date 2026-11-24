"""백준 14940 · 쉬운 최단거리
https://www.acmicpc.net/problem/14940
"""
# import 
from collections import deque 


#input 
""" n개의 줄에 m개의 숫자, 0은 갈수 없는 땅 1은 갈 수 있는 땅, 2는 목표 지점""" 
n, m = map(int, input().split()) 
matrix = [list(map(int, input().split())) for _ in range(n)]
trg_r, trg_c = 0, 0 
for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        if matrix[i][j] == 2: 
            trg_r, trg_c = i, j 

# 큐의 선언 및 시작좌표 넣기 
q = deque() 
q.append((trg_r, trg_c)) 

# 상우하좌 탐색  
dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

# 각 좌표의 거리를 저장: 아직 방문하지 않은 칸은 -1  
""" 1은 갈 수 있는 길, 0은 벽 """
distance = [[ 0 if elem == 0 else -1 for elem in row] for row in matrix]

""" 목표 지점 """
distance[trg_r][trg_c] = 0

while q:
    sr, sc = q.popleft()
        
    # 4분면 탐색
    for dir in range(4): 
        nr, nc = sr + dr[dir], sc + dc[dir] 
        # 범위 확인
        if (nr < 0 or nr >= n or nc < 0 or nc >= m):
            continue
        """ 벽 여부 확인 """
        if distance[nr][nc] != -1:
            continue 

        """ 큐에 넣기 직전의 칸만 기록 """ 
        distance[nr][nc] = distance[sr][sc] + 1
        q.append((nr, nc))


""" 각 지점에서 목표 지점까지의 거리 출력 """ 
for row in distance:
    """ 리스트 언패킹 """
    print(*row)
