#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    // dp 정의, 시작점 
    vector<vector<int>> dp(n, vector<int>(m, 0)); 
    dp[0][0] = 1; 
    
    // 물 웅덩이 막힘 표시 -> 웅덩이 찾으면 웅덩이 반복문 탈출 
    // puddles : 1-based 유의 
    vector<vector<bool>> blocked(n, vector<bool>(m, false)); 
    for (int i = 0; i < puddles.size(); i++) {
        int pudd_r = puddles[i][1] - 1; 
        int pudd_c = puddles[i][0] - 1; 

        blocked[pudd_r][pudd_c] = true; 
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            // 시작점 
            if (r == 0 && c == 0) {
                continue;
            }
                    
            // 웅덩이로 막힌 곳이면 패스 
            if (blocked[r][c]) {
                continue; 
            }
            
            // 위쪽  
            if (r > 0) {
                dp[r][c] += dp[r-1][c]; 
            }
            
            // 왼쪽 
            if (c > 0) {
               dp[r][c] += dp[r][c-1];
            }
            
            // mod 처리 
            dp[r][c] %=  1000000007;
            
        }
    }
    //  학교까지 갈 수 있는 최단경로의 개수를 1,000,000,007로 나눈 나머지를 return 하 
    answer = dp[n-1][m-1]; 
    return answer;
}