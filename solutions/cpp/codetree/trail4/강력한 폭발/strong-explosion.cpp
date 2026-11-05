#include <iostream>
#include <vector> 
#include <algorithm> 

using namespace std;

int n;
int grid[20][20];

// 1. 선택한 폭탄을 담은 vector 
vector<int> selected; 

 // 2. grid 를 순회하면서 폭탄 위치 저장 
vector<pair<int, int>> bombs; 

// 4. 방향 배열 : 폭탄 터지는 거에 따른 상대좌표 
int dr[3][5] = {
    // 0번 폭탄 
    {-2, -1, 0, 1, 2}, 
    // 1번 폭탄 
    {-1, 0, 0, 0, 1}, 
    // 2번 폭탄 
    {-1, -1, 0, 1, 1}
}; 

int dc[3][5] = {
    // 0번 폭탄 
    {0, 0, 0, 0, 0}, 
    // 1번 폭탄 
    {0, -1, 0, 1, 0}, 
    // 2번 폭탄 
    {-1, 1, 0, -1, 1}
};

int maxValue = 0; 

// 3-2. dfs() : 몇 번 째 폭탄의 종류를 정하는 중인가? 
// 파라미터 : 보통 어디까지 결정했는지 
void dfs(int depth) {
    // 종료 조건 : 모든 폭탄의 종류를 다 정한 경우 
    // 폭탄의 개수 : up to input 
    if (depth == bombs.size()) {
        // 4. 실제로 폭탄의 종류를 다 정한 다음에 카운트 
        // 폭발한 칸 기록 
        bool exploded[20][20] = {}; 

        // bombs[i] 랑 selected[i] 랑 엮어서 생각 
        for (int i = 0; i < selected.size(); i++) {
            // 폭탄 위치 
            int r = bombs[i].first; 
            int c = bombs[i].second; 

            // i 번째 폭탄 종류 
            int type = selected[i]; 

            // 헤당 폭탄이 터트리는 5개의 위치 
            for (int d = 0; d < 5; d++) {
                int nr = r + dr[type][d]; 
                int nc = c + dc[type][d]; 

                // 범위 확인이요 
                if (nr < 0 || nr >= n ||
                    nc < 0 || nc >= n
                ) continue; 

                // 폭발한 칸의 표시 
                exploded[nr][nc] = true; 
            }
        } 
        // 폭발한 칸 세고, 최고값 갱신해가기 
        int cnt = 0; 
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (exploded[r][c]) {
                    cnt++; 
                }
            }
        }
        maxValue = max(maxValue, cnt); 
        return; 
    }

    // 폭탄의 type 순회하기 
    for (int b = 0; b < 3; b++) {
        // 선택 -> 다음 type 호출 ->  선택 해제 
        selected.push_back(b); 
        dfs(depth + 1); 
        selected.pop_back(); 

    }
  
}


int main() {
    // grid의 크기 
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                bombs.push_back({i, j}); 
            }
        }
    } 

    // 3-1. dfs 호출 
    dfs(0); 
    cout << maxValue; 

    return 0;
}
