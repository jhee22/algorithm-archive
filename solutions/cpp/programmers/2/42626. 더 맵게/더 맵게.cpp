#include <string>
#include <vector>
#include <queue> 
#include <functional> 

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq; 
    
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]); 
    }
    
    // 모든 음식의 스코빌 지수가 K이상될 때까지
    // 섞을 수 있다는 건, 음식이 2개 이상이란 것
    // 없으면 -1 !
    while(pq.size() >=2 && pq.top() < K) {
        int first = pq.top(); 
        pq.pop(); 
        
        int second = pq.top();
        pq.pop(); 
        
        int mixed = first + (second * 2); 
        pq.push(mixed); 
        answer++;
    }
    
    if (pq.top() < K) {
        return -1; 
    }
    
    
    return answer;
}