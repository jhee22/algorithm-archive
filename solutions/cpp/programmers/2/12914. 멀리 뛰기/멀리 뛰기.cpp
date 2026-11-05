#include <string>
#include <vector>

using namespace std;
/*
    solution : 방법 가지 수 % 1234567 
    멀리 뛰기에 사용되는 칸 수 : n개 
    n개의 칸 : 1칸 or 2칸을 뛸 수 있음 
    (e.g) n = 3, 
    (1, 1, 1)
    (1, 2)
    (2, 1)
    현재 위치가 동일하다면 ,앞으로 갈 수 있는 경우의 수는 항상 같기 때문에 DP
    dp[i] = i 칸 까지 오기 위한 경우의 수 
*/
long long solution(int n) {
    vector<long long> dp(n + 1, 0); 
    dp[1] = 1; 
    // n = 1인 경우를 유의
    if (n >= 2) {
        dp[2] = 2; 
    }

    for (int i = 3; i <= n; i++) {
        // i칸으로 올 수 있는 이전 위치 
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567 ; 
    }
    
    
    return dp[n]   ;
}