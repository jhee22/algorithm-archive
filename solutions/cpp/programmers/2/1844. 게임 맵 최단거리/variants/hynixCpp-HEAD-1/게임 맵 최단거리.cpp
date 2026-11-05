#include<vector>
#include<queue> 
using namespace std;

// 상하좌우 
int dr[4] = {-1, 1, 0, 0}; 
int dc[4] = {0, 0, -1, 1}; 

/*
    문제 : 캐릭터 위치 1-based 
    정답 : 상대 팀 진영에 도착하기 위해서 지나가야 하는 칸의 개수
*/

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    // grid : n x m, 1 : 이동 가능, 0 : 벽 
    int n = maps.size();
    int m = maps[0].size(); 
    
    // 상대방 진영 n-1,m-1 에위치 -> dist[n-1][m-1]
    
    // queue, dist 
    queue<pair<int, int>> q; 
    vector<vector<int>> dist(n, vector<int>(m, -1)); 
    
    // start : 1-based(1,1) -> 0-based (0,0)
    q.push({0, 0}); 
    dist[0][0] = 1; 
    
    // BFS 
    while (!q.empty()) {
        int row = q.front().first; 
        int col = q.front().second; 
        q.pop(); 
        
        // 4방향 탐색 
        for (int dir = 0; dir < 4; dir++) {
            int nr = row + dr[dir]; 
            int nc = col + dc[dir]; 
            
            // 범위 제약 
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue;
            }
            
            // 벽을 만나는 경우 
            if (maps[nr][nc] == 0) {
                continue; 
            }
            
            // 이미 탐색을 완료한 경우 
            if (dist[nr][nc] > -1) {
                continue; 
            }
            
            // 방문 
            dist[nr][nc] = dist[row][col] + 1; 
            q.push({nr, nc}); 
        }
        
    }
    
    return dist[n-1][m-1];
}