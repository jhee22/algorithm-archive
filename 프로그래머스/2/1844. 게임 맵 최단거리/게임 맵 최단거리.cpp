#include<vector>
#include<string> 
#include<queue> 

using namespace std;

int solution(vector<vector<int> > maps)
{
    // 1. 행의 개수, 열의 개수 
    int n = maps.size(); 
    int m = maps[0].size(); 
    
    // 2. 상, 하, 좌, 우 
    int dr[4] = {-1, 1, 0, 0}; 
    int dc[4] = {0,0, -1, 1}; 
    
    // 3. 거리배열
    // n x m : -1 로 채운 2차원 배열 생성 (방문여부를 확인)
    vector<vector<int>> dist(n, vector<int>(m, -1)); 
    
    // 4. 좌표를 닫는 큐 
    queue<pair<int, int>> q;
    
    // 5. 시작점 : 처음 캐릭터는 맵의 좌측 상단(1,1) 에 위치 
    // C++ 인덱스 시작 기준으로 맞춰서 첫 행, 열에다가 0,0 
    q.push({0, 0}); 
    // 첫번째 칸(1칸 지난거 포함) 
    dist[0][0] = 1; 
    
    // 6. 뀨가 빌 때 까지 
    while(!q.empty()) {
        // 행, 열 꺼내우왁 
        int row = q.front().first; 
        int col = q.front().second; 
        q.pop(); 
        
        // 4방향 탐색 (4방향이니까)
        for (int i = 0; i < 4; i++) {
            // next row, col 
            int nr = row + dr[i]; 
            int nc = col + dc[i]; 
            
            // 맵 경계 조건 (3)
            // 1. 맵 밖이면 빼수 
            if (nr < 0 || nr >= n || nc <0 || nc >=m ) continue; 
            // 2. 벽이면 빼수 
            if (maps[nr][nc] == 0) continue; 
            // 3. 이미 방문했으면 패스 
            if (dist[nr][nc] != -1) continue; 
            
            //방문하면, 거리 갱신 
            // dist[0][0] = 1, 지나온 칸의 개수를 세는 것임!!! 
            dist[nr][nc] = dist[row][col] + 1; 
            
            // 다음 좌표를 큐에 삽입
            q.push({nr, nc}); 
        }
                     
    }
    // 리턴 : 지나가야하는 칸의 개수 
    return dist[n - 1][m - 1]; 
}