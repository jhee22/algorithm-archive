#include <string>
#include <vector>
#include <queue> 
#include <iostream> 
using namespace std;

/*
    n : 지역의 개수 
    roads : 지역 정보 
    sources : 부대원이 위치한 서로 다른 지역 
    destination : 강철 부대의 지역 
*/
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    // (1-based) 길 연결 
    vector<vector<int>> graph(n+1); 
    for (int i = 0; i < roads.size(); i++) {
        int a = roads[i][0]; 
        int b = roads[i][1]; 
   
        graph[a].push_back(b); 
        graph[b].push_back(a);
    } 
    
    // 출발지 
    vector<int> dist(n+1, -1); 
    dist[destination] = 0; 
    
    // 시작점 
    queue<int> q; 
    q.push(destination); 
    
    // bfs 탐색 
    while (!q.empty()) {
        int curr = q.front(); 
        q.pop(); 
        
        for (int next : graph[curr]) {
            // 이미 방문 했으면 
            if (dist[next] > -1) continue; 
            dist[next] = dist[curr] + 1; 
            q.push(next);     
        }
        
    }
    
    // 부대로 복귀할 수 있는 최단 시간 
    vector<int> answer; 
    for (int source : sources) {
        answer.push_back(dist[source]);
    }
    return answer;
}