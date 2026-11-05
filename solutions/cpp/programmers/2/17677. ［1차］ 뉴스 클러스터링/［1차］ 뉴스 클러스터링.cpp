#include <string>
#include <vector> 
#include <iostream>
#include <algorithm> 
#include <cctype> 
using namespace std;

int solution(string str1, string str2) {
    // 소대문자 처치
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower); 
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower); 
    
    // str1, str2의 부분집합 생성하기 
    vector<string> v1; 
    for (int i = 0; i < str1.size()- 1; i++) {
        char a = str1[i]; 
        char b = str1[i + 1]; 
        
        // 문자 여부 확인 
        if (isalpha(a) && isalpha(b)) {
            // substr(i, 2) : i 번째 인덱스부터 2글자 자르시오 
            v1.push_back(str1.substr(i, 2)); 
        }
        
    } 
    
    vector<string> v2; 
    for (int i = 0; i < str2.size()-1; i++) {
        char a = str2[i]; 
        char b = str2[i + 1]; 
                         
        if (isalpha(a) && isalpha(b)) {
            v2.push_back(str2.substr(i,2)); 
        }
    }    
                         
    // v1과 이미 매칭한 v2원소 기록 
    vector<bool> used(v2.size(), false); 
    
    // 합집합 개수 
    int inter = 0; 
    
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            // 이미 방문했으면 패스 
            if (used[j]) {
                continue; 
            }
            
            // v2에는 한개 있는데, v1에 여러개 있는거 매칭 X 
            if (v1[i] == v2[j]) {
                inter++; 
                used[j] = true;
                break; 
            }
                 
        }
    }
    // 합집합 : n(A) + n(B) - n(A&&B) -- 중1 솩 
    int uni = v1.size() + v2.size() - inter; 
    if (uni == 0) return 65536; 
    int answer =  (int) ((double) inter / uni * 65536);
    return answer;
}