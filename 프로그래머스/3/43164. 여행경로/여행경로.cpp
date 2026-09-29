#include <string>
#include <vector>
#include <unordered_map> 
#include <algorithm> 
#include <iostream> 
using namespace std;

int cnt = 0; 
int total = 0; 
vector<bool> visited; 
vector<string> route; 
vector<string> answer; 
unordered_map<string, vector<pair<string, int>>> graph;

bool dfs(string cur, int cnt) {
    // 종료 조건 
    // tickets 는 전역 변수가 아닙니다 휴 - 먼 
    if (cnt == total) {
        answer = route;
        return true;    
    }
    
    // 탐색 
    for (int i = 0; i < graph[cur].size(); i++) {
        string target = graph[cur][i].first; 
        int idx = graph[cur][i].second; 
        
        // 이미 쓴 티켓의 경우 
        if (visited[idx]) {
            continue; 
        }
        
        // 티켓 사용 
        route.push_back(target); 
        visited[idx] = true; 
        
        // target 으로 들어감
        if (dfs(target, cnt + 1)) {
            return true; 
        }
        
        // 돌아왔으므로 티켓 사용 취소
        visited[idx] = false;
        route.pop_back(); 
        
    }
    return false; 
    
}


vector<string> solution(vector<vector<string>> tickets) {
    visited = vector<bool>(tickets.size(), false); 
    total = tickets.size(); 
    
    // 출발지 하나, 목적지 여러개 
    // {"출발지" : {{"도착지1", 2}, {"도착지2", 3"}}
    for (int i = 0; i < tickets.size(); i++){
        string from = tickets[i][0]; 
        string to = tickets[i][1];
        
        graph[from].push_back({to, i}); 
    }
    
    // 도착지 알파벳 정렬 
    for (auto& p : graph) {
        sort(p.second.begin(), p.second.end());  
    }
    
    // 항상 시작은 인국공 
    string cur = "ICN";
    route.push_back(cur); 
    
    // 현재 시작 공항, 사용한 티켓 수 
    dfs(cur, 0); 
    
    
    return answer;
}