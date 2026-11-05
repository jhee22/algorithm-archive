#include <string>
#include <vector>

using namespace std;

void dfs(int curr, const vector<vector<int>>& graph, vector<bool>& visited) {
    // 방문 처리   
    visited[curr] = true; 
    
    // 다음 방문 
    for (int next : graph[curr]) {
        if (visited[next]) continue; 
        dfs(next, graph, visited); 
    }
    
} 


int solution(int n, vector<vector<int>> computers) {
    // computers[i][j] == 1 : i 번째 컴퓨터와 j번쨰 컴퓨터가 연결되있음 
    
    // graph 
    vector<vector<int>> graph(n); 
    for (int i = 0; i < computers.size(); i++) {
        for (int j = 0; j < computers[0].size(); j++) {
            if (i != j && computers[i][j] == 1) {
                // 양쪽의 연결이 행렬에 이미 표시 
                // [[1, 1, 0], [1,1,0], ... ] 
                graph[i].push_back(j); 
            }
        }
    }
    
    // 방문여부
    vector<bool> visited(n, false); 
    
    // 네트워크 개수 
    int answer = 0;
    
    for (int i = 0; i < computers.size(); i++) {
        // 이미 방문한 컴퓨터먼 사절 
        if (visited[i]) continue; 
        // i 가 이미 컴퓨터 그 자체임 
        dfs(i, graph, visited); 
        answer++; 
    }
    
    return answer;
}