/*
    핵심 규칙 
    1. 더 높은 중요도가 뒤에 있으면 : 현재 프로세스를 뒤로 보냄
    2. 현재 프로세스가 가장 높은 중요도 : 실행 
    
    자료 구조와의 연결 
    queue : 누가 맨 앞인가 
    priority_queue :  현재 가장 높은 중요도는 무엇인가? 
*/


#include <string>
#include <vector>
#include <queue> 

using namespace std;

int solution(vector<int> priorities, int location) {
    // priority, index 저장할 자료형 queue 선언 
    queue<pair<int, int>> q; 
    priority_queue<int> pq; 
    
    // 1. q, pq 채우기 
    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
        pq.push(priorities[i]); 
    }
    
    int answer = 0; 
    
    // 2. 프로세스가 남아있는 동안 반복 
    while (!q.empty()) {
        // 현재 queue 의 맨 앞의 프로세스와 인덱스 
        int priority = q.front().first;  
        int idx = q.front().second; 
        q.pop(); 
        
        // 현재 프로세스보다 더 큰 중요도가 있으면 뒤로 
        if (priority < pq.top()) {
            q.push({priority, idx}); 
        } 
        
        // 제일 중요한 거면 실행 
        else {
            answer++; 
            pq.pop();
            
            // 우리가 찾는 location 과 일치하다면 
            if (idx == location) {
                return answer; 
            }
        }
    }
    

    return answer;
}