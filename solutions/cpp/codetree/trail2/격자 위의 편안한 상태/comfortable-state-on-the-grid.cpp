#include <iostream>
#include <vector> 
using namespace std;

int N, M;
int r[10000], c[10000];

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> r[i] >> c[i];
    }

    // 2차원 matrix 선언 : N x N 크기의 격자 
    vector<vector<int>> matrix(N+1, vector<int>(N+1, 0)); 
    
    // N, S,W,E 탐색을 위한 방향 좌표 
    int dr[4] = {-1, 1, 0, 0}; 
    int dc[4] = {0, 0, -1, 1}; 

    // 2차원 배열 탐색 
    // M번을 걸쳐서 색을 칠함 
    for (int i = 0; i < M; i++) {
        // 색칠한 칸 
        matrix[r[i]][c[i]] = 1; 

        // 색칠한 칸의 개수 
        int cnt = 0;     

        // 4방향 검사니까 
        for (int dir = 0; dir < 4; dir++) {
            // nr, nc
            int nr = r[i] + dr[dir]; 
            int nc = c[i] + dc[dir]; 

            // 범위 체크 
            if (nr < 1 || nr > N || nc < 1 || nc > N) {
                continue; 
            } else {
                if (matrix[nr][nc] == 1) cnt++; 
            }
    
        } 

        if (cnt == 3) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }

    }




    return 0;
}