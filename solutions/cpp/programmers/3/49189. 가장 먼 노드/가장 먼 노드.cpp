#include <string>
#include <vector>
#include <queue>
#include <algorithm> 
#include <iostream> 

using namespace std;
/*
    구하는 것 : 1번 노드에서 가장 멀리 떨어진 노드의 개수 
    가장 멀리 떨어진 노드 : 최단 경로로 이동 시 간선의 개수가 많은 것 
    
*/

/*
    edge = {
        {3, 6} // i = 0번째 간선의 {첫 번째 노드, 두 ~ }
        {4, 3} // i = 1
        {3, 2} // i = 2
    }
*/

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    // graph 
    // 노드 번호 1-based 이니까 1 ~ n 으로 생각 
    vector<vector<int>> graph(n + 1); 
    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i][0]; 
        int b = edge[i][1]; 
        
        graph[a].push_back(b); 
        graph[b].push_back(a); 
        
    }
    
    // (거리재기/ 방문 저장)/ 큐 
    // 노드*** 생각 
    vector<int> dist(n + 1, -1); 
    
    // 뀨 -> 시작점(1번 노드) 저장 -> 거리/ 방문여부 
    queue<int> q; 
    q.push(1); 
    dist[1] = 0; 
    
    // 뀨뀨~~ 
    while (!q.empty()) {
        // 늘 ~ 하던대로 
        int curr = q.front(); 
        q.pop(); 
        
        // curr 타고 타고 타기 
        for (int elem : graph[curr]) {
            // 이미 갔음 됫슈 
            if (dist[elem] > -1) {
                continue; 
            }
            
            // 진짜 갔슈~ 
            dist[elem] = dist[curr] + 1; 
            q.push(elem); 
            
        }
    }
    
    // 가장 최대 dist 구한 다음에 해당 거리와 같은 노드가 몇개인지 세기 
    int maxDist = -2; 
    for (int i = 0; i < dist.size(); i++) {
        maxDist = max(maxDist, dist[i]); 
    } 
    
    for (int i = 0; i < dist.size(); i++){
        if (maxDist == dist[i]) {
            answer++; 
        }
    }
    
    return answer;
}