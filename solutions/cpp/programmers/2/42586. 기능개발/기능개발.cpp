#include <string>
#include <vector>
#include <queue> 
#include <cmath> 

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    // 정답 vector
    vector<int> result; 
    // 완료 날짜를 넣을 Queue 
    queue<int> q; 
    
    // (1) 완료 날짜 계산, ceil() 올림 연산 yarr 
    for (int i = 0; i < progresses.size(); i++){
        int days = ceil((100.0 - progresses[i]) / speeds[i]); 
        q.push(days); 
    }
    
    // (2) FIFO : 맨 앞 기능을 기준으로 배포 그룹 만들기 
    // 언제까지? 큐가 빌 때까지 
    while (!q.empty()) {
        int deploy = q.front(); 
        q.pop(); 
        
        // 
        int cnt = 1; 
        
        // 큐가 안비고, 다음날보다 이전 날의 완료일이 크다면 한 개 더 배포
        while(!q.empty() && q.front() <= deploy) {
            q.pop(); 
            cnt++; 
        }
        
        result.push_back(cnt);
         
    }
    
    return result;
}