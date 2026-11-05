#include <iostream>
#include <algorithm> 

using namespace std;

int n, m;
int grid[200][200];
int answer = 0; 

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    // 모든 시작 위치를 본다 
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            // 1. 가로 일자 
            // 가로는 열이 움직이겠쮜 
            // e.g : 3칸 - c, c + 1, c + 2 (k-1) 칸까지 
            if (c + 2 < m) {
                int sum = grid[r][c]
                + grid[r][c + 1] 
                + grid[r][c + 2]; 

                answer = max(answer, sum); 
            }

            // 2. 세로 일자 
            if (r + 2 < n) {
                int sum = grid[r][c]
                + grid[r + 1][c]
                + grid[r + 2][c]; 

                answer = max(answer, sum); 
            }

            // 3. ㄴ 자 모양 
            if (r + 1 < n && c + 1 < m) {
                int sum = grid[r][c]
                + grid[r + 1][c] 
                + grid[r + 1][c + 1]; 

                answer = max(answer, sum); 
            }

            // 4. ㄴ 자 모양 회전 
            if (r + 1 < n && c + 1 < m) {
                int sum = grid[r][c] 
                + grid[r][c + 1]
                + grid[r + 1][c +1];

                answer = max(answer, sum); 
            }

            // 5. ㄴ 자 모양 회전 
            if (r + 1 < n && c + 1 < m) {
                int sum = grid[r][c] 
                + grid[r][c + 1]
                + grid[r + 1][c]; 

                answer = max(answer, sum); 
            }

            // 6. ㄴ 자 모양 회전 
            if (r + 1 < n && c + 1 < m) {
                int sum = grid[r][c + 1]
                + grid[r + 1][c +1]
                + grid[r + 1][c];

                answer = max(answer, sum); 
            }            

        }
    }
    cout << answer << "\n";
    return 0;
}
