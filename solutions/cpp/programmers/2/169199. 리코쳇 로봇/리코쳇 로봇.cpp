#include <string>
#include <vector>
#include <algorithm> 
#include <cmath> 
#include <queue> 
#include <iostream> 

using namespace std;
int dr[4] = {-1, 1, 0, 0}; 
int dc[4] = {0, 0, -1, 1}; 

/*
    . : 빈 공간 
    R : 로봇의 처음 위치 
    D : 장애물의 위치 
    G : 목표 지점 
*/
int solution(vector<string> board) {
    // *** 방문 기록하는 2차원 배열 vector ***
    int n = board.size(); 
    int m = board[0].size(); 
    vector<vector<int>> dist(n, vector<int>(m, -1)); 
    
    // 로봇의 시작/도착지 
    pair<int, int> start; 
    pair<int, int> goal; 

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'R') {
                start.first = i; 
                start.second = j;
            }
            
            else if (board[i][j] == 'G') {
                goal.first = i; 
                goal.second = j; 
            }
        }
    }
    
    // 3. 뀨 
    // BFS 의 심장 : "앞으로 탐색해야 할 좌표를 줄 세워놓는 대기열" 
    // 상/하/좌/우 로 미끄러져 갈 수 있는 모든 위치를 뀨에 넣음 
    // 뀨에서 하나 꺼내서 상/하/좌/우 탐색 
    queue<pair<int, int>> q; 
    q.push(start); 
    
    // dist = - 1 : 아직 방문 안함
    // dist = 0 이상 : 방문함 + 몇 번 이동해왔는지 저장 
    dist[start.first][start.second] = 0;  
    
    // 방문할 수 있는 모든 좌표를 탐색할 수 있을 때 까지 
    while (!q.empty()) {
        // 뀨로부터 꺼낸 현재 위치 
        int row = q.front().first; 
        int col = q.front().second; 
        q.pop();
        
        // 미끄러짐 
        for (int dir = 0; dir < 4; dir++) {
            // 움직이면서 바뀌는 임시좌표
            // 한 방향 탐색 후, 다시 다른 방향 탐색 시작시 원래 위치 부터 
            int nr = row;
            int nc = col; 
            
            // 다음 칸 컴사
            while (true) {
                // 다음칸으로 갈 수 있는지 검사하는 후보 위치
                int next_r = nr + dr[dir]; 
                int next_c = nc + dc[dir]; 
                
                // 유효성 검사
                if (next_r < 0 || next_r >= n ||
                    next_c < 0 || next_c>= m) {
                    break; 
                }
                
                // 장애물 만났는지 여부 
                if (board[next_r][next_c] == 'D') {
                    break; 
                }
                
                // 이-동
                nr = next_r; 
                nc = next_c; 
            }
            
            // 방문 기록 
            // 시작점으로 부터 몇 번 이동했는지 기록 
            if (dist[nr][nc] == -1) {
                dist[nr][nc] = dist[row][col] + 1; 
                q.push({nr, nc});
            }          
        }
        
        // 찾았다! 
        if (row == goal.first && col == goal.second) {
            return dist[row][col]; 
        }
        
    }
    
    
    return -1;
}