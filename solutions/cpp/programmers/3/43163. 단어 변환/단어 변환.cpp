#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

// 전역변수 선언 
int answer = 1e9; 
vector<bool> visited;

// dfs 함수 정의 
void dfs(string curr_w, int cnt, vector<string>& words, string target) {
    //  종료 조건 
    //  현재 단어 == target
    if (curr_w == target) {
        answer = min(answer, cnt);
        return; 
    }
    
    for (int i = 0; i < words.size(); i++) {
        // 이미 쓴 단어면 패스 
        if (visited[i]) {
            continue; 
        }
        
        // 한 번에 한 개의 알파벳만 바꿀 수 있음 
        int incorrect = 0; 
        for (int j = 0; j < words[i].size(); j++) {
            if (curr_w[j] != words[i][j]) {
                incorrect++; 
            } 
        }
        if (incorrect == 1) {   
            visited[i] = true; 
            // 조건을 만족한 words[i] dfs탐색 시작 
            dfs(words[i], cnt+1, words, target); 
            visited[i] = false; 
        
        }
       
    }
    
} 


int solution(string begin, string target, vector<string> words) {
    visited = vector<bool> (words.size(), false); 
    /*
        dfs 에 넘겨줘야할 것들
        (1) 현재 단어
        (2) 바뀐 횟수 
        (3) words
        (4) target
    */
    dfs(begin, 0, words, target);
    
    // target 으로 갈 수 없는 경우 
    if (answer == 1e9) {
        return 0; 
    }
    return answer;
}