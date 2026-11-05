#include <vector>
#include <queue> 
#include <algorithm> 
#include <functional> 

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    int n = jobs.size(); 
    
    // 정렬하면 원래 위치가 바뀌므로, 작업 번호를 먼저 보존
    // {소요시간, 요청시간, 작업의 번호}
    for (int i = 0; i < n; i++) {
        jobs[i].push_back(i); 
    }
    
    // 요청시각 순으로 정렬 
    sort(jobs.begin(), jobs.end()); 
    
    // 최소힙 : 대기 작업은 소요시간 -> 요청 시각 -> 번호 순
    priority_queue<
        vector<int>, 
        vector<vector<int>>, 
        greater<vector<int>>
    > pq; 
    
    int time = 0; 
    int idx = 0; // 아직 큐에 넣지 않은 첫 작업 
    int total = 0; // 각 작업의 반환 시간 합계 
    
    // 아직 도착하지 않은 작업 내지 대기 작업이 있으면 계속
    while (idx < n || !pq.empty()) {
        // 처리할 작업이 없으면 다음 요청까지 기다림 
        // 이미 그 요청 시간이 지났으면 시간을 되돌리지 X
        if (pq.empty() && idx < n) {
            time = max(time, jobs[idx][0]); 
        }
        
        // 선택 전 현재까지 도착한 작업을 전부 후보에 넣는다
        while (idx < n && jobs[idx][0] <= time) {
            pq.push({
                // 소요시간
                jobs[idx][1], 
                // 요청시간
                jobs[idx][0], 
                // 번호순서
                jobs[idx][2]
            });
            
            // 다음 작업으로 이동 
            idx++; 
        }
        
        // 제거 후에도 정보를 사용헤야 하므로 값 복사 
        auto job = pq.top(); 
        pq.pop(); 
        
        // 시작한 작업은 중단하지 않고 끝까지 작업 
        time += job[0]; 
        
        // 반환시간 : 작업 시간 + 대기 시간(시간 - 요청시간) 
        total += time - job[1]; 
        
    }
    
    
    return total / n;
}