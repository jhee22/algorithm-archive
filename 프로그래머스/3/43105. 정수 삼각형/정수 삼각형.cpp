#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

// 삼각형의 (i, j) 위치까지 내려왔을 떄 얻을 수 있는 최대합 
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    // dp 정의 : 왼쪽 사이드 + 중앙 + 오른쪽 사이드로 분리해서 생각 
    int n = triangle.size(); 
    vector<vector<int>> dp (n, vector<int>(n, 0)); 
    dp[0][0] = triangle[0][0]; 
    
    // triangle 순회할 때 왼 사 / 중 / 오 사 나눠서 생각을 해보자 
    for (int i = 1; i < n; i++) {
        // 왼사
        dp[i][0] = triangle[i][0] + dp[i-1][0];
        for (int j = 1; j < i; j++) {
            // 중앙     
            dp[i][j] = triangle[i][j] + max(dp[i-1][j-1], dp[i-1][j]); 
        }
        // 오사
        dp[i][i] = dp[i-1][i-1] + triangle[i][i]; 
    } 
    
    // 정답 dp 마지막 행에서 가장 큰 값, 마지막 행은 n-1 
    for (int i = 0; i < dp[n-1].size(); i++) {
        answer = max(answer, dp[n-1][i]);
    }
    return answer;
}