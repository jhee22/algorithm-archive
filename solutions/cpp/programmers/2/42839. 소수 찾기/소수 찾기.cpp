#include <string>
#include <vector>
#include <set> 
using namespace std;

// dfs 에서 공통으로 쓸 변수 
string digits; 
vector<bool> used; 
set<int> made; 

void dfs(string curr) {
    // 빈 문자열이면 만들 수 없음 
    if (!curr.empty()) {
        made.insert(stoi(curr)); 
    }
    
    // 탐색 시작 
    for (int i = 0; i < digits.size(); i++) {
        // 이미 탐색한 경우 
        if (used[i]) continue; 
        used[i] = true;  
        dfs(curr + digits[i]); 
        used[i] = false; 
    }
}

bool isPrime(int num) {
    // 2미만은 소수가 아님 
    if (num < 2) return false; 
    
    for (int d = 2; d * d <= num; d++) {
        if (num % d == 0) return false; 
    }
    
    return true; 
}

int solution(string numbers) {
    // 호출할 때마다 공유 데이터 초기화 
    digits = numbers; 
    used.assign(numbers.size(), false); 
    made.clear(); 
    
    // 빈 문자열부터 탐색 시작 
    dfs(""); 
    
    // 소수 판별 
    int answer = 0;
    for (int num : made) {
        if (isPrime(num)) {
            answer++; 
        }
    }
    
    return answer;
}