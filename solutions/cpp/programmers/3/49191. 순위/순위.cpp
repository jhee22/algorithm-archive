#include <string>
#include <vector>
#include <iostream> 
#include <queue> 
using namespace std;

/*
    n : 선수의 수 
    results : 경기의 결과를 담은 2차원 배열 
    results.size() : 경기의 수 
    4번이 누구를 이겼는가만 구하는 것이 아니라, 4번과 순위를 비교할 수 있는 사람이 몇 명? 
    순위를 아는 조건 : 나를 이긴 사람의 수 + 내가 이긴 사람 수 =  n - 1 (자기자신)
*/
// 같은 bfs 탐색을 여러 번 재사용해야함
// 이번 탐색에서 나를 이긴/ 내가 이긴 선수가 몇명인지 발견하는 목적  
int bfs(int curr, const vector<vector<int>>& graph) {    
    int n = graph.size(); 
    // 뀨 : 앞으로 탐색해야할 선수들
    // vector<bool> : 해당 선수 탐색 여부 
    queue<int> q; 
    q.push(curr); 
    vector<bool> visited (n + 1, false); 
    visited[curr] = true; 
    int cnt = 0; 
    // 뀨 탐색 시작 
    while (!q.empty()) {
        int p = q.front(); 
        q.pop(); 
        
        for (int elem : graph[p]) {
            // 이미 본 p 라면 빼수 
            if (visited[elem]) {
                continue; 
            }
            
            // 방문 표시 
            visited[elem] = true; 
            // 발견한 선수 카운트 up 
            cnt++; 
            // 뀨 
            q.push(elem);
        }
        
    }
    
    return cnt;
}


int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    // win_graph[1] : 1번 사람이 이긴 사람 목록 저장 
    // lose_graph[1] : 1번 사람을 이긴 사람 목록 저장 
    vector<vector<int>> win_graph(n + 1); 
    vector<vector<int>> lose_graph(n + 1); 
    
    for (int i = 0; i < results.size(); i++) {
        int win = results[i][0]; 
        int lose = results[i][1]; 
        
        win_graph[win].push_back(lose); 
        lose_graph[lose].push_back(win); 
    }

    // win_graph, lose_graph BFS 탐색 돌려야하니까 함수로 분리 
    for (int i = 1; i <= n; i++) {
        int win_cnt = bfs(i, win_graph); 
        int lose_cnt = bfs(i, lose_graph);
        
        if (win_cnt + lose_cnt  == n - 1) {
            answer++; 
        }
    }
    
    return answer;
}