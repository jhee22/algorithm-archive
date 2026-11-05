#include <string>
#include <vector>
#include <algorithm> 


using namespace std;

// cards : 각 상자에 들어있는 카드 번호 
/*
    (To-Do List) 아직 열지 않은 상자 하나 선택 
    -> 연결된 상자를 계속 열기 
    -> 그룹 크기 저장 
    -> 또 안 연 상자가 있으면 새로운 그룹 만들기 
*/
int solution(vector<int> cards) {
    int answer = 0;
    // 해당 상자의 방문 여부를 기록할 visited 
    vector<bool> visited(cards.size(), false); 
    
    // 각 그룹의 크기 
    vector<int> groups; 
    
    // 모든 상자를 한 번씩 확인 
    // 새로운 그룹을 찾는 역할 
    for (int i = 0; i < cards.size(); i++) {
        
        // 이미 어떤 그룹에서 열었던 상자라면 
        if (visited[i]) {
            continue; 
        }
        
        // 새로운 그룹 하나 만들기 
        // 지금 내가 열고 있는 상자 
        int cur = i; 
        // 이번 그룹에서 내가 몇 개의 상자를 열었나? 
        int cnt = 0; 
        
        // 하나의 그룹 안에서 상자를 계속 따라가는 역할 
        while (!visited[cur]) {
            // 현재 상자를 연다 
            visited[cur] = true; 
            
            // 그룹의 크기 증가 
            cnt++; 
            
            // 다음 상자로 이동 
            cur = cards[cur] -1;
        }
        // 그룹의 크기 저장 
        groups.push_back(cnt); 
    }
    // 그룹의 크기를 내림차순으로 정렬 
    sort(groups.rbegin(), groups.rend()); 
    // 남은 상자가 없는 경우 고려하지 않음 
    if(groups.size() == 1) {
        return 0; 
    } else {
        answer = groups[0] * groups[1];
    }
    
    return answer;
}