#include <string>
#include <vector>
#include <unordered_set> 
#include <algorithm> 
#include <cctype> 

using namespace std;

// {} 안의 원소의 개수가 작은 elem부터

vector<int> solution(string s) {
    vector<int> answer;
    // 문자열로 들어온 튜플 집합 파싱 
    vector<vector<int>> groups; 
    
    // 현재 {} 안의 숫자들 
    vector<int> group; 
    
    // 숫자 조립 
    int num = 0; 
    bool readingNum = false; 

    // 1. 문자열 파싱 
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            readingNum = true; 
        }
        
        else {
            if (readingNum) {
                group.push_back(num); 
                num = 0; 
                readingNum = false; 
            }
            // 하나의 집합 끝
            if (s[i] == '}' && !group.empty()) {
                groups.push_back(group); 
                group.clear(); 
            }
        }
    }
    // 2. 원소의 개수가 적은 집합 부터 정렬 
    sort(groups.begin(), groups.end(), 
        [] (const vector<int>& a, const vector<int>& b) {
            return a.size() < b.size(); 
        }
    ); 
    
    // 3. 동일 숫자 체크 
    unordered_set<int> used; 
    
    // 4. 작은 집합 부터 새 숫자 찾기 
    for (const vector<int>& g : groups) {
        for (int num : g) {
            if (used.find(num) == used.end()) {
                answer.push_back(num); 
                used.insert(num); 
            }
        }
    }
    return answer;
}