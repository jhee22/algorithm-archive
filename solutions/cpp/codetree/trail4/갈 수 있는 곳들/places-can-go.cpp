#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm> 

using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];
bool visited[100][100];

queue<pair<int, int>> q; 
int answer = 0; 
int dr[4] = {-1, 1, 0, 0}; 
int dc[4] = {0,0, -1, 1};

int main() {
    // n : 격자의 크기
    // k : 시작점의 수 
    cin >> n >> k;

    // n * n의 grid 입력
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    // 시작점 r행 c열  (k개만큼줌)
    for (int i = 0; i < k; i++) cin >> r[i] >> c[i];

    // Please write your code here.
    // 1. 시작점을 queue에 넣기 
    for (int i = 0; i < k; i++) {
        // 1-based > 0-based
        int row = r[i] - 1; 
        int col = c[i] - 1; 
        
        if (!visited[row][col]) {
            visited[row][col] = true;
            q.push({row, col});
            answer++; 
        }
    }
    
    // 2. BFS
    while (!q.empty()) {

        int row = q.front().first; 
        int col = q.front().second; 
        q.pop(); 

        for (int dir = 0; dir < 4; dir++) {
            int nr = row + dr[dir]; 
            int nc = col + dc[dir]; 

            // 범위 구간 
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                continue; 
            }

            // 벽 
            if (grid[nr][nc] == 1) {
                continue; 
            }

            // 방문 여부 검사
            if (visited[nr][nc]) {
                continue; 
            }
            visited[nr][nc] = true; 
            q.push({nr, nc});
            answer++; 
        }
    }
    cout << answer;
    return 0;
}
