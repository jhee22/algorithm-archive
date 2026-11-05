#include <string>
#include <vector>
#include <queue> 
using namespace std;

int dr[4] = {-1, 1, 0, 0}; 
int dc[4] = {0, 0, -1, 1}; 

// 2. bfs 구현
bool bfs(int sr, int sc, const vector<string>& place){
    // 1. queue 
    queue<pair<int, int>> q; 
    
    // 2. dist 
    vector<vector<int>> dist(5, vector<int>(5, -1)); 
    
    // 3. 시작점 
    q.push({sr, sc}); 
    dist[sr][sc] = 0; 
    
    // 4. BFS
    while (!q.empty()) {
        // 1. 현재 좌표 
        int row = q.front().first; 
        int col = q.front().second; 
        q.pop(); 
        
        // 2. 거리가 2면 더 안가유  >? 
        if (dist[row][col] == 2) {
            continue; 
        }
        
        // 3. 상하 좌우 
        for (int dir = 0; dir < 4; dir++) {
            int nr = row + dr[dir]; 
            int nc = col + dc[dir]; 
            
            // 범위 확인 
            if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) {
                continue; 
            }
            
            // 방문 확인 (0 이상은 이미 간 것 )
            if (dist[nr][nc] != -1) {
                continue;
            }
            
            // X 확인 > ? 
            if (place[nr][nc] == 'X') {
                continue; 
            }
            
            // 거리갱신 
            dist[nr][nc] = dist[row][col] + 1; 
            
            // P 발견
            if (place[nr][nc] == 'P') {
                return false; 
            }
            
            q.push({nr,nc});
        }
        
    }
    return true; 
}

vector<int> solution(vector<vector<string>> places) {  
    vector<int> answer; 
    
    // 1. 대기실 하나씩 보기 
    for (int room = 0; room < 5; room++) {
        // 방은 안전수칙을 지킴을 가정
        bool safe = true; 
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                
                // P를 발견하면 검사 
                if (places[room][r][c] == 'P') {
                    // P 하나 찾았는데 얘 기준으로 맨허튼 거리 확인 
                    if (!bfs(r, c, places[room])) {
                        safe = false; 
                    }
                }

            }
        }
        if (safe) {
            answer.push_back(1); 
        } else {
            answer.push_back(0);
        }
    }
    return answer;
}