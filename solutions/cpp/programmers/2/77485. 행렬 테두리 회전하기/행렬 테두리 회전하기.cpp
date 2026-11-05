#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    // 1. matrix 생성 (1 ~ n * m)
    vector<vector<int>> board(rows, vector<int>(columns)); 
    
    int num = 1; 
    
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            board[r][c] = num++; 
        }
    }
    
    // 2. query 하나씩 처리 
    for (vector<int> q : queries) {
        
        // 1-based -> 0-based 
        int r1 = q[0] - 1; 
        int c1 = q[1] - 1; 
        int r2 = q[2] - 1; 
        int c2 = q[3] - 1;  
        
        // 왼쪽 위 좌표값을 들고 시작 (r1,c1) 
        int prev = board[r1][c1]; 
        int minValue = prev; 
    
        // 오른쪽 칸으로 이동 
        for (int c = c1 + 1; c <= c2; c++) {
            // 현재 칸의 원래의 칸을 잠깐 저장 
            int cur = board[r1][c];   
            // 내가 들고온 값을 현재 칸에 넣기 
            board[r1][c] = prev; 
            // 밀려난 값을 다시 손에 넣기 
            prev = cur; 
            minValue = min(minValue, cur);
        }

        // 아래 칸으로 이동 
        for (int r = r1 + 1; r <= r2; r++) {
            int cur = board[r][c2]; 
            board[r][c2] = prev; 
            prev = cur; 
            minValue = min(minValue, cur); 
        }
        
        // 왼쪽 칸으로 이동 
        for (int c = c2 -1; c >= c1; c--) {
            int cur = board[r2][c]; 
            board[r2][c] = prev; 
            prev = cur; 
            minValue = min(minValue, cur); 
        }
        
        // 위쪽 칸으로 이동 
        for (int r = r2 -1; r >= r1; r--) {
            int cur = board[r][c1]; 
            board[r][c1] = prev; 
            prev = cur; 
            minValue = min(minValue, cur); 
        }
        // 이번 query의 최소값 answer에 넣기 
        answer.push_back(minValue); 
    }

    return answer;
}