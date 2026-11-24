"""백준 14891 · 톱니바퀴
https://www.acmicpc.net/problem/14891
"""

# input 
""" 1번 ~ 4번 톱니바퀴 상태 """
gears = [list(map(int, input())) for _ in range(4)] 

""" 회전 횟수 """ 
n = int(input()) 

""" 회전시킨 방법 : 회전시킨 톱니바퀴의 번호, 정수의 방향 (1 : 시계, -1 :  반시계)""" 
""" 맞닿은 면이 반대면 회전 방향과 반대 방향으로 회전, 아님 stay"""


for _ in range(n):
    """ 방향 """
    vectors = [0, 0, 0, 0]
    
    num, way = map(int, input().split()) 
    start = num -1
    vectors[start] = way 

    # 오른쪽으로 한 쌍씩 확인 
    for i in range(start, 3): 
        # 같으면 회전 stop 
        if gears[i][2] == gears[i + 1][6]:
            break 
        vectors[i + 1] = -vectors[i] 

    # 왼쪽으로 한 쌍씩 확인
    for j in range(start, 0, -1):
        if gears[j][6] == gears[j - 1][2]:
            break 
        vectors[j - 1] = -vectors[j]


    for i in range(len(vectors)): 
        gear = gears[i]
        # 시계 방향 회전 
        if (vectors[i] == 1): 
            gears[i] = gear[-1: ] + gear[: -1]
        elif (vectors[i] == -1):
            gears[i] = gear[1: ] + [gear[0]]

# output
""" 1번 촙니바퀴가 N극이면 0, S극이면 1점"""  
result = 0
for i in range(len(gears)):
    if (gears[i][0] == 1):
        if i == 0:
            result += 1 
        elif i == 1:
            result += 2 
        elif i == 2: 
            result += 4 
        else:
            result += 8

print(result)
        




# output : 네 톱니바퀴의 정수의 합 