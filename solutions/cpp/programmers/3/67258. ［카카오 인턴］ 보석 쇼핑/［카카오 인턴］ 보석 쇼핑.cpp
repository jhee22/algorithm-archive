#include <string>
#include <vector>
#include <map> 
#include <algorithm> 
#include <iostream> 
#include <set> 

using namespace std;

vector<int> solution(vector<string> gems) {
    // (return) 모든 종류의 보석을 적어도 1개 이상 포함하는 가장 짧은 구간 
    vector<int> answer;
    
    // (1-based) 진열대 번호 
    int left = 0; 
    int interval = 0;
    
    // 보석함 set / map 
    set<string> s; 
    for (int i = 0; i < gems.size(); i++) {
        s.insert(gems[i]); 
    }
    map<string, int> m; 
    
    int minValue = gems.size() + 1; 
    for (int right = 0; right < gems.size(); right++) {
        // 오른쪽 보석 증가  
        m[gems[right]]++; 
        
        // 모든 종류의 보석이 있는 상태에서 
        while (m.size() == s.size()) {
            // 1. 모든 보석이 있으므로 현재 구간도 정답 후보
            int len = right - left + 1; 
            if (len < minValue) {
                minValue = len; 
                // .push_back() 하면 모든 후보 left, right이 추가
                answer = {left + 1, right + 1}; 
            }
            
            
            // 2. 더 짧은 구간을 찾을 수 있는 지 확인 
            // 왼쪽 보석을 지워봄 
            m[gems[left]]--; 
            // 종류가 사라지면 
            if (m[gems[left]] == 0) {
                // 업는 종류이므로 명단에서 지움 
                m.erase(gems[left]); 
            }
            // 구간의 시작 위치를 옮김 
            left++;    
        }
        
    }
    return answer;
}