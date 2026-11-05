#include <string>
#include <vector>
#include <queue> 
#include <functional> 
#include <iostream> 
#include <algorithm> 
using namespace std;
/*
    costs : 다리를 건설 하는 비용 
    solution : 최소의 비용으로 모든 섬이 서로 통행 가능하도록 하는 최소 비용 
    조건 
        (1) 다리를 여러번 건너더라도 도달할 수 있으면 통행 가능 
            e.g. : A <> B, B <> C ->  A <> C (O)
        (2) 1 <= n <= 100 
        (3) costs.size() <= ((n -1) * n) / 2 
        (4) i -> cost[i][0] 와 cost[i][1] 다리가 연결되는 두 섬의 번호, cost[i][2] 비용 
        (5) 같은 연결 중복 X, 순서가 바뀌더라고 같은 연결 
        (6) 섬 사이의 다리 건설 비용 X -> 두 섬 사이의 건설이 불가능한 경우 
*/
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    // 1. graph[0] = {{1, 1}, {2, 2}}; 
    vector<vector<pair<int, int>>> graph(n); 
    for (int i = 0; i < costs.size(); i++) {
        int a = costs[i][0]; 
        int b = costs[i][1]; 
        int c = costs[i][2]; 
        
        // graph에 연결해야할 것 {연결될 섬, 연결비용}
        graph[a].push_back({c,b}); 
        graph[b].push_back({c,a}); 
           
    }
    
    // 2. 갈 수 있는 다리 후보 : 비용이 가장 작은 섬을 방문, 이제 방문하지 않은 -> 우선순위큐 
    // pair<int, int> 를 queue 에 입력하는 경우, {first, second} 순으로 비교하기 때문에 참고
    priority_queue<
        pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>  
    > pq;
    vector<bool> visited (n, false); 
    
    // 시작점 : 결국 모든 섬을 연결하기 때문에 
    int start = 0; 
    visited[start] = true; 
    // pq 연결 : 가장 비용이 싼 다리를 알아서 top 으로 올려줌 
    for (int i = 0; i < graph[start].size(); i++){
        // pair<int, int> 자체를 넣어버릴 수도 있음 
        pq.push(graph[start][i]);
    }
    // pq 탐색 
    while (!pq.empty()) {
        auto [cost, curr]  = pq.top(); 
        pq.pop(); 
        
        // 이미 방문했으면 pass 
        if (visited[curr]) {
            continue; 
        }
        
        // 현재 섬 방문 처리 및 비용 증가 
        visited[curr] = true; 
        answer += cost; 
        
        // 현재 섬과 연결된 다음 섬 방문 
        for (auto [next_cost, next] : graph[curr]) {
            if (visited[next]) {
                continue; 
            }
            
            pq.push({next_cost, next});
             
        }

    }

    return answer;
}