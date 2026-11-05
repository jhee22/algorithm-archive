#include <string>
#include <vector>

using namespace std;
// 내가 고를 수 있는 후보 
string vows = "AEIOU";
// 현재까지 내가 만든 단어 
string selected; 
// 지금까지 만들어본 단어의 개수 
int cnt; 
// word가 몇 번째 단어인지 
int answer; 

// dfs : selected 뒤에 A/E/I/O/U 중 하나를 붙여서 다음 단어를 만들어봄 
void dfs(string word){
    // 종료조건 
    if (selected.size() == 5) {
        return; 
    }
    // AEIOU 하나씩 붙여봄
    for (int i = 0; i < 5; i++) {
        selected.push_back(vows[i]); 
        cnt++; 
        
        if (selected == word) {
            answer = cnt; 
        }
        
        dfs(word); 
        
        selected.pop_back(); 
    }
    return;
}


int solution(string word) {
    // dfs 탐색으로 모든 단어를 사전순으로 만들어보라고 시킴 
    dfs(word);
    return answer;
}