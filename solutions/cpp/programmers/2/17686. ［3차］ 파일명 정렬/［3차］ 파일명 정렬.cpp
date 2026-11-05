#include <string>
#include <vector>
#include <algorithm> 
#include <cctype> 

using namespace std;

/*
    (e.g) foo9.txt
        - HEAD : foo
        - NUMBER : 9
        - TAIL : .txt 
*/

/*
    (1) HEAD 부분 기준 사전순 정렬, 대소문자 비교 X 
    (2) NUMBER 숫자 순으로 정렬, 숫자 앞 0 은 무시 
    (3) 원래 입력에 주어진 순서를 유지 
    
*/

struct File {
    string original; 
    string head; 
    int number;
    int index;  
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<File> parsed; 
    for (int i = 0; i < files.size(); i++) {
        // 숫자를 경계로 
        string s = files[i]; 
        int idx = 0; 
        
        // 1. 첫 숫자가 나올 때까지 이동 (숫자가 아닐 때동안 이동)
        while (idx < s.size() && !(s[idx] >= '0' && s[idx] <= '9')) {
            idx++; 
        }
        
        // 2. 숫자가 시작한 위치부터 5자리 읽기 
        // 00000 ~ 99999 사이의 숫자니까 
        int startIdx = idx; 
        while (idx < s.size() 
               && s[idx] >= '0' 
               && s[idx] <= '9'
               && idx - startIdx < 5) {
            idx++; 
        }
        
        // 3. head, number, tail 
        string head = s.substr(0, startIdx); 
        int number = stoi(s.substr(startIdx, idx-startIdx)); 
        string tail = s.substr(idx); 
        
        // 4. head -> 소문자 
        for (char& c : head) {
            c = tolower(static_cast<unsigned char>(c)); 
        }
        parsed.push_back({s, head, number, i}); 
     }
    
    // 5. 정렬 
    sort(parsed.begin(), parsed.end(),
    [] (const File& a, const File& b) {
        if (a.head != b.head) {
            return a.head < b.head; 
        }
        
        if (a.number != b.number) {
            return a.number < b.number; 
        }
        
        return a.index < b.index; 
    }); 
    
    for (const File& file : parsed) {
        answer.push_back(file.original); 
    } 
    return answer;
}