#include <string>
#include <vector>
#include <iostream> 
#include <cctype> 

using namespace std;
/*
    3 <= 아이디 길이 <= 15
    아이디 : 소문자, 숫자, -, _, . 만 사용 가능
    . 는 처음과 끝에 사용할 수 없음 
*/
string solution(string new_id) {
    // 프로그램이 추천하는 새로운 아이디 return 
    string s = ""; 
    
    for (char c : new_id) {
        // 소문자 변환 
        c = (char)(tolower)((unsigned char)c); 
        
        // 조건 나열 
        bool allowed = 
            // 소문자
            ('a' <= c && c <= 'z') ||
            // 숫자
            ('0' <= c && c <= '9') ||
            // 허용하는 특수문자 
            c == '-' || c == '_' || c == '.'; 
        
        if (!allowed) continue; 
        
        // 점이 연속 .. 인걸 막음 
        if (c == '.' && !s.empty() && s.back() == '.') {
            continue; 
        } 
        
        s += c; 
    }
    
    // 4. 양끝점 제거 
    if (!s.empty() && s.front() == '.') s.erase(0, 1); 
    if (!s.empty() && s.back() == '.') s.pop_back();  
    
    // 5. 빈문자 처리 
    if (s.empty()) s = "a"; 
    
    // 6. 길이가 16자 이상이라면, 첫 15개 제외하고 다 없애 
    if (s.size() >= 16) s.resize(15);     
    
    // 7. 마침표 처리
    if (s.back() == '.') s.pop_back(); 
    
    // 8. 
    if (s.size() <= 2) {
        // s 의 길이가 3이 될 때까지 
        while (s.size() < 3) s += s.back(); 
    }
    
    return s;
}