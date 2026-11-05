#include <string>
#include <vector>
#include <algorithm> 
#include <queue> 
#include <iostream> 

using namespace std;
// 상하좌우
int dx[4] = {-1, 1, 0, 0}; 
int dy[4] = {0, 0, -1, 1};

// 테두리 : 최대 좌표 * 2 의 인덱스까지 접근이 가능할 수 있도록 
// 좌표를 x2 하는 이유 : 테두리 사이의 빈 칸을 만들어 BFS 의 가짜 지름길 막기 
vector<vector<int>> board (102, vector<int>(102, 0)); 


/*
    문제 조건 
    characterX, characterY : 캐릭터의 시작 위치 
    itemX, itemY : 아이템 위치 
    직사각형 테두리 따라가서 아이템까지 가는 "최소거리" -> 이거 완저니 BFS
    recentangleY : 1 <= 직사각형 개수  <= 4  (직사각형이 최대 4개 들어올 수 있단 뜻) 
    직사각형을 나타내는 모든 좌표 값은 : 1 <= x <= 50 
    
*/ 
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    // 모든 좌표를 2배씩 -> 테두리만 가기 위해서 
    characterX *= 2; 
    characterY *= 2; 
    itemX *= 2; 
    itemY *= 2; 
        
    // 방문 여부를 저장할 붹터 
    vector<vector<int>> dist (102, vector<int>(102, -1)); 
    // 시작점
    queue<pair<int, int>> q; 
    q.push({characterX, characterY}); 
    // 시작점은 방문함 
    dist[characterX][characterY] = 0; 
    
    // 칠하기 : board[r][c] 에 주어진 직사각형 범위를 포함 
    for (int c = 0; c < rectangle.size(); c++) {
        // 네모네모 
        int x1 = rectangle[c][0] * 2; 
        int y1 = rectangle[c][1] * 2; 
        int x2 = rectangle[c][2] * 2;
        int y2 = rectangle[c][3] * 2; 
        
        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                board[x][y] = 1; 
            }
        } 
    }
    
    // 지우기 : x1, x2, y1, y2 제외의 내부 점들 지우기 
    for (int c = 0; c < rectangle.size(); c++) {
        // 네모네모 
        int x1 = rectangle[c][0] * 2; 
        int y1 = rectangle[c][1] * 2; 
        int x2 = rectangle[c][2] * 2;
        int y2 = rectangle[c][3] * 2; 
        
        for (int x = x1 + 1; x < x2; x++) {
            for (int y = y1 + 1; y < y2; y++) {
                board[x][y] = 0; 
            }
        }
    }
    
    // check 
    // cout << board[1][1] << " "; 
    // cout << board[2][2] << " "; 
    
    // BFS 탐색 두과자 
    while (!q.empty()) {
        // 1. 꺼내 
        int x = q.front().first; 
        int y = q.front().second; 
        q.pop(); 
        
        // 2. 상하좌우 탐색
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir]; 
            
            // board의 범위 제약 : 
            if (nx < 0 || nx >= 102 || ny < 0 || ny >= 102) {
                continue; 
            }
            
            // 테두리를 지나야할 것   
            if (board[nx][ny] == 0) {
                continue; 
            }
            
            // 방문 제약 : 이미 방문했음 나!가! 
            if (dist[nx][ny] > -1) {
                continue; 
            }
            
            // 거리 갱신 
            dist[nx][ny] = dist[x][y] + 1; 
            
            // 뀨 삽입
            q.push({nx, ny}); 
        }
        
        // 3. item 에 도착하면 탐색 끝! 
        if (x == itemX && y == itemY) {
            return dist[x][y] / 2; 
        }
        
    }
    
    
    
    
    return answer;
}