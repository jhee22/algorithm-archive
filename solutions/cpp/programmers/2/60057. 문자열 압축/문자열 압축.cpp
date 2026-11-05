#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

/*
    unit : 몇 글자씩 자를지 
    prev : 현재 반복 횟수를 세고 있는 조각 
    curr : 이번에 읽은 조각 
    cnt : prev가 연속해서 나온 횟수 
    compressed : 지금까지 완성한 압축 문자열 
*/

int solution(string s) {
    int n = s.size(); 
    int answer = n; // 압축하지 않은 원래 길이 
    
    // 1글자, 2글자, 3글자씩 잘라보기 
    for (int unit = 1; unit <= n / 2; unit++) {
        string  compressed = ""; 
        
        string prev = s.substr(0, unit); 
        int cnt =1; 
        
        // 첫 조각은 prev에 넣었으므로 다음 조각부터 
        for (int pos = unit; pos < n; pos += unit) {
            string curr = s.substr(pos, unit); 
            
            if (curr == prev) {
                cnt++; 
            } else {
                if (cnt > 1) {
                    compressed += to_string(cnt); 
                }
                compressed += prev; 
                
                // 새로운 조각의 횟수를 세기 
                prev = curr; 
                cnt = 1; 
            }
        }
        
        // 반복문이 끝났을 때 남아있는 마지막 묶음 저장 
        if (cnt > 1) {
            compressed += to_string(cnt); 
        }
        compressed += prev; 
        
        answer = min(answer, (int)compressed.size()); 
    }

    return answer;
}