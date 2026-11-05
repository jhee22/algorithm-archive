#include <string>
#include <vector>
#include <queue> 
#include <algorithm> 

using namespace std;

int dr[4] = {-1, 1, 0, 0}; 
int dc[4] = {0, 0, -1, 1}; 


// shape {{1, 1}, {1, 2}}
vector<pair<int,int>> normalize(vector<pair<int, int>> shape) {
    // 1. 최소 r, c 찾기 
    int min_r = shape[0].first; 
    int min_c = shape[0].second; 
    for (int i = 0; i < shape.size(); i++) {
        min_r = min(min_r, shape[i].first); 
        min_c = min(min_c, shape[i].second); 
    }
    
    // 2. 정규화 
    vector<pair<int, int>> normalize_shape; 
    for (int i = 0; i < shape.size(); i++) {
        int r = shape[i].first; 
        int c = shape[i].second; 
        normalize_shape.push_back({r - min_r, c - min_c});     
    }
    
    // 3. 정렬
    sort(normalize_shape.begin(), normalize_shape.end()); 
    return normalize_shape; 
}

vector<pair<int, int>> rotate_90(vector<pair<int, int>> shape) {
    vector<pair<int, int>> rotate_shape; 
    // 90도만 돌리고 넘기는겨 
    for (int i = 0; i < shape.size(); i++) {
        int r = shape[i].first; 
        int c = shape[i].second; 
        rotate_shape.push_back({c, -r});

    }
    return rotate_shape; 
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    
    // 1. 변수 선언 및 초기화 
    int N = game_board.size(); 
    // game_board, table 방문 기록 
    vector<vector<bool>> visited_game(N,vector<bool>(N, false)); 
    vector<vector<bool>> visited_tbl(N, vector<bool>(N, false)); 
    // 빈칸 및 퍼즐 기록 
    vector<vector<pair<int, int>>> blanks; 
    vector<vector<pair<int, int>>> puzzles; 
    
    // 2. game_board 전체 순회, 새로운 빈칸 덩어리 시작점 찾기 
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (game_board[r][c] == 0 && !visited_game[r][c]) {
                
                // BFS 탐색 시작 
                // shape : 덩어리 한 개 
                vector<pair<int, int>> shape;
                queue<pair<int, int>> q; 
                
                // 시작점을 덩어리에 넣음 
                q.push({r,c}); 
                visited_game[r][c] = true; 
                shape.push_back({r,c}); 
                
                // BFS 탐색 시작 
                while (!q.empty()) {
                    // 현재 좌표 꺼내기 
                    int row = q.front().first; 
                    int col = q.front().second; 
                    q.pop(); 
                    
                    // 상하좌우 탐색 
                    for (int dir = 0; dir < 4; dir++) {
                        int nr = row + dr[dir]; 
                        int nc = col + dc[dir]; 
                        
                        // 1. 범위 조건 
                        if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                            continue; 
                        }                        
                        // 2. 덩어리 조건 (0인가) 
                        if (game_board[nr][nc] == 1) {
                            continue; 
                        }
                        
                        // 3. 방문 조건 
                        if (visited_game[nr][nc]) {
                            continue; 
                        }
                        
                        // 4. 방문처리 및 덩어리 및 큐 추가 
                        visited_game[nr][nc] = true; 
                        shape.push_back({nr, nc}); 
                        q.push({nr, nc}); 
    
                    }
 
                }
                // 덩어리 하나 다 찾음
                blanks.push_back(shape);  
 
            }
  
        }    
    
    }
    
    // 3. table 순회해서 퍼즐 담기
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (table[r][c] == 1 && !visited_tbl[r][c]){
                // 한 조각, 조각 덩어리  
                vector<pair<int, int>> shape; 
                queue<pair<int, int>> q; 
                
                // 시작점 
                q.push({r, c}); 
                visited_tbl[r][c] = true; 
                shape.push_back({r,c}); 
                
                // Queue 순회 
                while(!q.empty()) {
                    // 시작 좌표 
                    int row = q.front().first; 
                    int col = q.front().second; 
                    q.pop(); 
                    
                    // 상하좌우 탐색 
                    for (int dir = 0; dir < 4; dir++) {
                        int nr = row + dr[dir]; 
                        int nc = col + dc[dir]; 
                        
                        // 1. 범위 체크 
                        if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                            continue; 
                        }
                        
                        // 2. 방문 체크 
                        if (visited_tbl[nr][nc]) {
                            continue; 
                        }
                        
                        // 3. 조각 덩어리가 아닌 경우 
                        if (table[nr][nc] == 0) {
                            continue; 
                        }
                        
                        // 4. 방문처리 및 큐에 새로운 좌표 추가 
                        visited_tbl[nr][nc] = true; 
                        q.push({nr, nc}); 
                        shape.push_back({nr, nc}); 
                    }
                    
                } // while 
                puzzles.push_back(shape); 
            
            }// if 
            
            
        }
        
    }// for 
    
    // 3. blanks <> puzzles 비교 
    // blanks 하나 당 모든 puzzle 후보를 비교는거임 
    // 퍼즐 사용하고, 해당 퍼즐을 사용했는가? 기록해야하는게 필요 
    // 해당 빈칸의 조각 개수와 해당 퍼즐의 조각개수가 안맞으면 애초에 빼버려
    vector<bool> visited_puzzle(puzzles.size(), false); 
    for (int i = 0; i < blanks.size(); i++) {
        vector<pair<int, int>> blank_shape = normalize(blanks[i]); 
        for (int j = 0; j < puzzles.size(); j++) {
            // 1. 퍼즐을 사용했으면, 해당 퍼즐 순회 X 
            if(visited_puzzle[j]) continue; 
            
            // 2 개수가 다르면 순회 x 
            if (blanks[i].size() != puzzles[j].size()) continue; 
            
            // 비교시 해야할 것 
            // 1. 정규화 및 오름차순 정렬   
            vector<pair<int, int>> puzzle_shape = normalize(puzzles[j]);
            
            // 2. 회전 
            bool match = false; 
            for (int rot = 0; rot < 4; rot++) {
                // 현재 방향 비교 
                if (puzzle_shape == blank_shape) {
                    answer += puzzle_shape.size(); 
                    visited_puzzle[j] = true;
                    match = true; 
                    break; 
                }
                
                // 다음방향 준비 
                puzzle_shape = rotate_90(puzzle_shape); 
                puzzle_shape = normalize(puzzle_shape); 
    
            }
            
            // 다 회전하고 맞은 경우 
            if (match) {
                break; 
            }
            
        }
        
    }
    
    return answer;
    
}