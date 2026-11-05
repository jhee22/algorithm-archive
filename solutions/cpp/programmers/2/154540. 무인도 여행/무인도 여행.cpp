#include <vector>
#include <iostream> 
#include <queue> 
#include <algorithm> 
using namespace std;

// 상, 하, 좌, 우 탐색 
int dr[4] = {-1, 1, 0, 0}; 
int dc[4] = {0, 0, -1, 1}; 

/*
    'X' or 1 ~ 9 사이의 자연수, 지도의 각 칸에 적힌 숫자는 식량을 나타냄 
     각 섬에서 최대 며칠씩 머물 수 있는지 배열에 오름차순으로 담아 return
*/

vector<int> solution(vector<string> maps) {
    vector<int> result;
    
    int n = maps.size(); 
    int m = maps[0].size(); 
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false)); 
    
    // 전체 지도를 순회해야함
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 바다와 이미 방문한 칸은 뛰어넘기기 
            if (maps[i][j] == 'X' || visited[i][j]) {
                continue; 
            }
            
            q.push({i, j}); 
            visited[i][j] = true; 
            int total = 0; 
            
            // 탐색 
            while (!q.empty()) {
                int row = q.front().first; 
                int col = q.front().second; 
                q.pop(); 
                total += maps[row][col] - '0'; 
                
                for (int dir = 0; dir < 4; dir++) {
                    int nr = row + dr[dir]; 
                    int nc = col + dc[dir]; 

                    // 범위 확인 
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                        continue;
                    } 
                    
                    // 방문 여부 확인
                    if (visited[nr][nc]) {
                        continue; 
                    }


                    // 'X' 
                    if (maps[nr][nc] == 'X') {
                        continue; 
                    }

                    // 방문
                    // 문자열 숫자 : - '0'
                    visited[nr][nc] = true; 
                    q.push({nr, nc});

                }

            } // while 
            result.push_back(total);
        }
    }
    // 예외처리 
    if (result.empty()) return {-1};
    
    // 오름차순 정렬 
    sort(result.begin(), result.end()); 
    return result;
}