#include <string> 
#include <algorithm> 
#include <vector>
#include <queue> 
#include <functional> 

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    // 1. '입실순서'기준 정렬
    sort(book_time.begin(), book_time.end()); 
    
    // 2. 최소힙 구현 : 청소까지 끝나는 시간을 넣음  
    priority_queue<
        int, 
        vector<int>, 
        greater<int>
    > pq;
    
    // 3. book_time 순회
    for (int i = 0; i < book_time.size(); i++) {
        // Time convert
        // substr(시작 인덱스, 길이)
        int start = stoi(book_time[i][0].substr(0, 2)) * 60 + 
                    stoi(book_time[i][0].substr(3,2));
        
        int end = stoi(book_time[i][1].substr(0, 2)) * 60 + 
                  stoi(book_time[i][1].substr(3,2));
        
        // pq 가 비어있지 않고, 방을 재사용할 수 있으면 
        if (!pq.empty() && pq.top() <= start) {
            pq.pop(); 
        } 
        
        // 2. 이번 손님이 사용할 새 완료 시간 
        pq.push(end + 10); 
    }
    
    answer = pq.size(); 
    
    return answer;
}