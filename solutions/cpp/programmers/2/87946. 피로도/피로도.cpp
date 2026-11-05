#include <string>
#include <vector>
 

using namespace std;

bool visited[8]; 
int maxCount = 0; 

// dfs 에 넘겨야 하는 것, dfs(현재 피로도, 지금까지 방분한 던전 수, 던전 목록 )
void dfs(int k, int count, vector<vector<int>>& dungeons) {
    
    // 어디까지 들어갈 수 있는지 모르니까 (피로도가 안되면 못드감)
    // DFS 함수가 호출될 때마다
    maxCount = max(maxCount, count); 
    
    // 모든 던전을 한번씩 후보로 본다 
    // 현재 상태에서 0 번 던전을 갈 수 있나? 
    // 1번 던전을 갈 수 있나 ? 
    // 2번 던전을 갈 수 있나 ? 
    for (int i = 0; i < dungeons.size(); i++) {
        // 아직 방문하지 않고 
        // 현재 피로도가 최소 피로도 이상? 
        if (!visited[i] && k >= dungeons[i][0]) {
            // 백 트래킹 
            // 던전을 선택
            visited[i] = true; 
            dfs(
                k - dungeons[i][1], 
                count + 1, 
                dungeons
            ); 
            
            // 복구 
            visited[i] = false; 
        }
        
    
    }
    
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(k, 0, dungeons); 
    
    return maxCount;
}