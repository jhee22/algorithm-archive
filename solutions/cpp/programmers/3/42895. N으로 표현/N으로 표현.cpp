#include <string>
#include <vector>
using namespace std;
/*
    N을 사용해서 number을 만들되 최소한의 개수를 사용
    // N을 1번 사용했을 때 만들 수 있는 숫자 
    dp[1] = {5} 
    
    // N을 2번 사용했을 때 만들 수 있는 숫자 
    dp[2] = {55, 10, 25, 1}
    
    // 문제에서 최소값이 8보다 크면 -1을 리턴 -> 최대 공간 1 ~ 9 야르 
    
    // dp[4] = dp[1] + dp[3]
             = dp[2] + dp[2]
             = dp[3] + dp[1]
    // N을 i번 쓴 결과를 만드려면, i를 두 덩이로 나눈 모든 경우의 수를 봐야함 i = j + (i-j)
    

*/

int solution(int N, int number) {
    int answer = 1e9;
    // N이 1이상 9이하니까 
    vector<vector<int>> dp(9); 
    
    // 최대 9번/ j < i 
    // dp[i] = dp[j] 와 dp[i-j] 를 조합해서 만듦 
    int num = 0; 
    for (int i = 1; i < 9; i++) {
        // N번 반복해서 만들 수 있는 숫자 
        num = num * 10 + N; 
        dp[i].push_back(num); 
        
        for (int j = 1; j < i; j++) {
            for (int e1 : dp[j]) {
                for (int e2 : dp[i-j]) {
                    // 사칙 연산 
                    dp[i].push_back(e1 + e2); 
                    dp[i].push_back(e1 - e2); 
                    dp[i].push_back(e1 * e2); 
                    
                    // zero-divided 
                    if (e2 != 0) {
                        dp[i].push_back(e1 / e2); 
                    }
                }
            }
            
        }
        // dp[i] = N 을 i번 사용해서 만들 수 있는 숫자 조합 저장
        // i가 1부터 증가하니까 당연히 제일 적게 만들 수 있는 조합을 뱉음 
        for (int elem : dp[i]) {
            if (elem == number) {
                return i; 
            }
        }
    }
    
    // 위에서 리턴 못뱉으면 예외
    return -1;
}