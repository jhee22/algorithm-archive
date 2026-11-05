#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int n;
int grid[25][25];
int dr[4] = {-1, 1, 0, 0}; 
int dc[4] = {0, 0, -1, 1}; 
bool visited[25][25];  
int people = 0; 
vector<int> pv; 
int town = 0; 

void dfs(int row, int col) {
    // dfs 함수에서 이미 row, col 전달해서 나 이 지점에 있으니까 여기에 연결된 곳만 뒤지셈 이라고 한정한 것임 
    // 현재 위치 방문 처리 
    visited[row][col] = true; 
    // 사람 수 증가 
    people++; 
    //  상하좌우 탐색 
    for (int dir = 0; dir < 4; dir++) {
        int nr = row + dr[dir]; 
        int nc = col + dc[dir]; 

        // 범위 체크 
        if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
            continue;  
        }

        // 벽 만나는 경우 
        if (grid[nr][nc] == 0 ) {
            continue; 
        }

        // 이미 방문한 칸의 경우 
        if (visited[nr][nc]) {
            continue; 
        }

        // 새 위치 
        dfs(nr, nc); 
    }
    return;
}


// 출력 : 마을 개수/ 그 마을의 각 인원 수들 (오름차순)
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    
    /*
        dfs 탐색 시 넘겨야할 값 
        (1-2) 시작 위치 (행, 열)
    */
    
    // 모든 칸을 본다
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 사람이 있는데 아직 방문을 하지 않은 경우 
            if (!visited[i][j] && grid[i][j]) {
                // 새로운 마을이다 ~ 
                town++; 
                people = 0; 
                // dfs 호출 
                dfs(i, j); 
                // 사람수 저장 
                pv.push_back(people); 
            } 
        }
    }

    // 정답 출력 
    // vector 오름차순 정렬
    sort(pv.begin(), pv.end()); 
    cout << town << "\n"; 
    for (int elem: pv) {
        cout << elem << "\n";
    }

    return 0;
}
