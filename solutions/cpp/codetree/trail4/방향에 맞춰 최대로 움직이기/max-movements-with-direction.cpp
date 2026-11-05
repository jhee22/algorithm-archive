#include <iostream>
#include <algorithm> 

using namespace std;

// 0. 전역변수 선언 
int n;
int num[4][4];
int move_dir[4][4];
int r, c;
int maxValue = 0; 

// 1. 방향 정보 
int dr[8] = {-1, -1, 0, 1, +1, 1, 0, -1}; 
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

// 2. dfs 정의 
void dfs(int curr_r, int curr_c, int cnt) {
    // 현재까지의 최대 이동 횟수 갱신 
    maxValue = max(maxValue, cnt); 

    // 현재 칸에 적혀 있는 방향 
    // 1-based -> 0-based 
    int d = move_dir[curr_r][curr_c] - 1; 

    // 해당 방향으로 n칸 범위 탐색 
    for (int dist = 1; dist < n; dist++) {
        int nr = curr_r + dr[d] * dist; 
        int nc = curr_c + dc[d] * dist; 

        // 범위 확인
        if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
            break;
        }

        // 적힌 수보다 커야됨 
        if (num[nr][nc] > num[curr_r][curr_c]) {
            dfs(nr, nc, cnt+1);
        }

    }
    
    return; 
}

int main() {
    cin >> n;
    // 숫자 matrix 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> num[i][j];
    
    // 방향 matrix 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> move_dir[i][j];

    // 시작 위치 
    cin >> r >> c;

    // Please write your code here.
    // 1-based > 0-based
    r--;
    c--;

    // DFS 파라미터 = 재귀를 한 단계 내려갈 때마다 바뀌는 현재 상태 
    // 이동하면서 바뀌는 것 r 현재 행, c 현재 열, 0이동횟수
    dfs(r, c, 0); 
    cout << maxValue; 
    return 0;
}
