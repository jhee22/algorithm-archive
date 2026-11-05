#include <iostream>
#include <vector> 

using namespace std;

int K, N;

// 1. 지금까지 내가 선택한 값을 저장하는 vector 
vector<int> selected; 

// 2. depth번째 자리에 무엇을 넣을지 결정 
void dfs(int depth) {
    // 3. 종료 조건 : N 자리 모두 완성  
    if (depth == N) {
        // 5. 결과 출력 
        for (int num : selected) {
            cout << num << " "; 
        }
        cout << "\n"; 
        return; 
    }

    // 4. 현재 선택 가능한 것들 
    for (int i = 1; i <= K; i++) {
        // 이번 자리에 선택한 숫자 i 를 넣기 
        selected.push_back(i);

        // 다음 자리 숫자 선택 시작 
        dfs(depth+1); 

        // 이번 자리에서 선택한 숫자 선택 취소 (for 다음 자리를 위해)
        selected.pop_back(); 

    }
}

int main() {
    cin >> K >> N;

    // Please write your code here.
    dfs(0); 
    
    return 0;
}
