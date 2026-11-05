#include <vector>
#include <iostream> 
#include <algorithm> 
#include <queue> 
using namespace std;

// 상하좌우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1}; 

/*
    Solution : 최대한 빠르게 미로를 빠져나가는데 걸리는 시간 출구 (E!!) 
    Condition : 
    - 미로를 빠져나가는 문이 있는데 레버를 당겨서만 열 수 있음! 
    - S > L (BFS), L > E (BFS) ... 반복 함수를 쓰자 
*/

int bfs(int row, int col, const vector<string>& maps, pair<int, int> target) {
    
    int n = maps.size(); 
    int m = maps[0].size(); 
    queue<pair<int, int>> q; 
    vector<vector<int>> dist (n, vector<int>(m, -1));
    
    // BFS 탐색의 시작점 
    q.push({row, col}); 
    dist[row][col] = 0; 
    
    // queue 탐색 
    while (!q.empty()) {
        int sr = q.front().first; 
        int sc = q.front().second; 
        q.pop(); 
        
        // 꺼낸 좌표가 target 의 좌표와 일치하다면 dist 리턴
        if (sr == target.first && sc == target.second) {
            return dist[sr][sc]; 
        }
        
    
        // 4방향 탐색 
        for (int dir = 0; dir < 4; dir++) {
            int nr = sr + dr[dir]; 
            int nc = sc + dc[dir]; 
            
            // 범위 확인 
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue; 
            }
                
            // 이미 지나간 지점인지 확인 
            if (dist[nr][nc] > -1) {
                continue; 
            }
                
            // X 확인 
            if (maps[nr][nc] == 'X') {
                continue;
            }
            
            // 방문 
            dist[nr][nc] = dist[sr][sc] + 1; 
            q.push({nr, nc}); 
        }
        
    }
    
    // dist debug 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << " "; 
        }
        cout << "\n"; 
    }   
    return -1; 
}
 


int solution(vector<string> maps) {
    int time = 0; 
    int n = maps.size(); 
    int m = maps[0].size(); 
    
    pair<int, int> start; 
    pair<int, int> exit;
    pair<int, int> lever; 

    // 시작점 받기 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] == 'S') {
                start = {i, j}; 
            }
            
            if (maps[i][j] == 'L') {
                lever = {i, j}; 
            }
            
            if (maps[i][j] == 'E') {
                exit = {i, j}; 
            }
        }
    }
    
    // (1) S -> L 까지 걸린 시간 
    int t1 = 0; 
    t1 = bfs(start.first, start.second, maps, lever); 
    if (t1 == -1) return -1; 
  
    
    // (2) L -> E 까지 걸린 시간 
    int t2 = 0; 
    t2 =  bfs(lever.first, lever.second, maps, exit); 
    if (t2 == -1) return -1; 
    
    time = t1 + t2; 
    return time;
}