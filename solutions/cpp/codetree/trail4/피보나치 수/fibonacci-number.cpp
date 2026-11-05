#include <iostream>
#include <vector> 
using namespace std;

int N;

int main() {
    cin >> N;

    // Please write your code here.
    // 1. dp 선언 및 초기값 
    vector<int> dp(N+1); 
    dp[0] = 0; 
    dp[1] = 1; 

    // 점화식 
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i -2] + dp[i -1]; 
    }
    cout << dp[N];
    return 0;
}
