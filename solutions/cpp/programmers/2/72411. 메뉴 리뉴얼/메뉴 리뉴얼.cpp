#include <string>
#include <vector>
#include <algorithm> 
#include <unordered_map> 

using namespace std;

void comb(const string& order,
         int start, 
         int len, 
         string& selected, 
         unordered_map<string, int>& count) {
    // len 개를 골랐으면 하나의 조합 완성
    if (selected.size() == len) {
        count[selected]++; 
        return;
    }
    
    // start 위치부터 메뉴 하나씩 선택
    for (int i = start; i < order.size(); i++) {
        // 선택
        selected.push_back(order[i]); 
        
        // 다음 위치 탐색 
        comb(order, i + 1, len, selected, count); 
        // 선택 복구 
        selected.pop_back(); 
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    // 각 주문 문자열 정렬 
    for (string& order : orders) {
        sort(order.begin(), order.end()); 
    }
    
    // 원하는 코스 길이 하나씩 확인 
    for (int len : course) {
        // 현재 len짜리 조합들의 등장 횟수 
        unordered_map<string, int> count; 
        
        // 모든 손님의 주문 확인 
        for (const string& order : orders) {
            
            // 주문 메뉴 수가 len 보다 작으면 조합X
            if (order.size() < len) {
                continue; 
            }
            
            // 현재까지 선택한 메뉴 
            string selected = ""; 
            
            // order에서 len개짜리의 모든 조합 생성 
            comb(order, 0, len, selected, count);
        }
        // 현재 len 에서 가장 많이 등장한 횟수 찾기 
        int maxCount = 0; 
        
        for (const auto&p : count) {
            maxCount = max(maxCount, p.second); 
        }
        
        // 최소 2번 이상 주문된 조합 중 
        // 최대 등장 횟수인 조합들을 answer에 저장 
        if (maxCount >= 2) {
            for (const auto& p : count) {
                if (p.second == maxCount) {
                    answer.push_back(p.first); 
                }
            }
        }
        
    }
    sort(answer.begin(), answer.end()); 
    return answer;
}