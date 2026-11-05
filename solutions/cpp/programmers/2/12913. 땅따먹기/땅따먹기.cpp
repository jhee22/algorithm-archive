#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int solution(vector<vector<int> > land)
{
    // land :  x 4 
    int n = land.size(); 
    
    // dp[i][j] : i행 j열을 밟았을 때까지의 최고점수 
    int maxValue = -1; 
    vector<vector<int>> dp (n, vector<int>(4)); 
    
    // 첫 행은 이전 행을 더할 수 없음 
    for (int j = 0; j < 4; j++) {
        dp[0][j] = land[0][j]; 
    }
    
    // dp 값 갱신 
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            // (조건) 이전 열과 같은 열 탐색은 불가
            for (int prev = 0; prev < 4; prev++) {
                if (j == prev) continue; 
                // dp 값 갱신 
                dp[i][j] = max(
                    dp[i][j], 
                    dp[i-1][prev] + land[i][j]
                );
            }
        }
    }
    // (1-based) to (0-based)
    return *max_element(dp[n-1].begin(), dp[n-1].end());
}