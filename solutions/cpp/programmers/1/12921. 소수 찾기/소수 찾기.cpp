#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    // 0, 1은 소수가 아님 
    vector<bool> prime(n + 1, true); 
    prime[0] = prime[1] = false; 
    
    
    for (int i = 2; i * i <= n; i++) {
        if (!prime[i]) continue; 
        
        // i의 배수를 소수 후보에서 제거 
        for (int j = i * i; j <= n; j+=i) {
            prime[j] = false; 
        }
    }
    
    for (int i = 2; i <=n; i++) {
        if (prime[i]) answer++; 
    } 
    
    return answer;
}