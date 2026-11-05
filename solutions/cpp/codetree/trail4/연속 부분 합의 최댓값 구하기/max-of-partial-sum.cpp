#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    vector<int> dp(n);
    dp[0] = arr[0];
    int maxValue = dp[0]; 
    
    // dp[i] 가 뭔질 생각해보자
    for (int i = 1; i < n; i++){
        // i 번째까지의 누적합 or 합계 시작
        dp[i] = max(arr[i], dp[i-1] + arr[i]);
        maxValue = max(dp[i], maxValue);
    }
    cout << maxValue;

    return 0;
}
