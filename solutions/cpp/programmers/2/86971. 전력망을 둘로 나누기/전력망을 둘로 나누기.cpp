#include <string>
#include <vector>
#include <algorithm> 
#include <cmath> 
using namespace std;

int dfs(int node, int blocked, const vector<vector<int>>& graph, vector<bool>& visited) {
    
    // 현재 송전탑 방문 
    visited[node] = true; 
    int cnt = 1; 
    
    for (int next : graph[node]) {
        if (next == blocked) continue; 
        if (visited[next]) continue; 
        
        cnt += dfs(next, blocked, graph, visited); 
        
    }
    
    return cnt; 
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> graph (n+1); 
    for (int i = 0; i < wires.size(); i++) {
        int a = wires[i][0]; 
        int b = wires[i][1]; 
        
        graph[a].push_back(b); 
        graph[b].push_back(a); 
    }
    
    // 끊었을 때의 그 덩어리 차이 비교  
    int minValue = n;
    
    // 끊을 전선 하나 선택
    for (int i = 0; i < wires.size(); i++) {
        int cutA = wires[i][0]; 
        int cutB = wires[i][1]; 
        
        // 끊을 전선을 바꿀때마다 방문 여부 초기화 
        vector<bool> visited(n + 1, false); 
        
        // 끊을 전선을 먼저 방문해봄 
        int cnt = dfs(cutA, cutB, graph, visited); 
        int other = n - cnt;
        int diff = abs(cnt - other); 
        minValue = min(minValue, diff);  
    }
    
    
    return minValue;
}