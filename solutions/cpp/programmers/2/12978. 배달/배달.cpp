#include <iostream>
#include <vector>
#include <queue> 
#include <functional> 
#include <utility> 

using namespace std;

/*
    도로마다 이동 시간이 다름, 모두 양수 : 다익스트라로 최단 시간 계산
    도로가 양방향 : 그래프에 양쪽 방향 모두 추가 
    출발점은 1번 마을 : dist[1] = 0 
    두 마을 사이에 도로가 여러 개일 수 있음 : 인접리스트에 각각 저장
    K 시간 이하인 마을 수 반환 : dist[i] <= k
*/

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    // graph[현재 마을] = {다음 마을, 도로 하나의 비용}
    vector<vector<pair<int, int>>> graph (N + 1); 
    
    for (int i = 0; i < road.size(); i++) {
        int a = road[i][0]; 
        int b = road[i][1]; 
        int cost = road[i][2]; 
        
        graph[a].push_back({b, cost}); 
        graph[b].push_back({a, cost}); 
    } 
    
    //  1번 마을부터 각 마을가지의 최소 비용  
    const int INF = 1e9; 
    vector<int> dist(N+1, INF); 
    dist[1] = 0; 
    
    // {누적비용, 마을 번호} 
    // greater를 사용해서 비용이 작은 것부터 꺼냄 
    priority_queue<
        pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>> 
    > pq;
    
    pq.push({0, 1});
    
    while (!pq.empty()) {
        int currCost = pq.top().first; 
        int curr = pq.top().second; 
        pq.pop(); 
        
        // 이미 더 짧은 경로를 찾았으면 이 기록은 무시 
        if (currCost > dist[curr]) continue; 
        
        // 그래프 탐색 
        for (pair<int, int> edge : graph[curr]) {
            int next = edge.first; 
            int roadCost = edge.second; 
            int newCost = currCost + roadCost; 
            
            // 현재 마을을 거치는 경로가 더 짧으면 갱신
            if (newCost < dist[next]) {
                dist[next] = newCost; 
                pq.push({newCost, next}); 
            }
        }
        
    }
    
 
    for (int i = 1; i <= N; i++) {
        if (dist[i] <= K) {
            answer++; 
        }
    }

    return answer;
}