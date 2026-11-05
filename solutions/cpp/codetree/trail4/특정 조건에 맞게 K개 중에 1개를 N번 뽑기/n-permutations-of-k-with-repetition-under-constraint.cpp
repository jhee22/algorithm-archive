#include <iostream>
#include <vector> 

using namespace std;

int K, N;

// 1. selected
vector<int> selected; 

// 2. N번째 자리수 방문 
void dfs(int depth) {
    // 3. 종료 조건 
    if (depth == N) {
        // 출력 
        for (int num : selected) {
            cout << num << " ";
        }
        cout << "\n"; 
        return; 
    }
    
    // 셀렉티등~ 
    // i는 선택할 숫자, k 범위 이내의 수 
    for (int i = 1; i <= K; i++) {
        // 조건 추가 
        // 일단 두개를 뽑고 난 이후 
        if (selected.size() >= 2 &&
            // 인덱스로 사용하면 안됨 
            selected[selected.size() - 2] == i && 
            selected[selected.size() - 1] == i 
        ) continue;

        // 선택, 재귀 호출, 선택 해제 
        selected.push_back(i); 
        dfs(depth + 1); 
        selected.pop_back(); 

    }



}

int main() {
    cin >> K >> N;

    // Please write your code here.
    dfs(0); 
    return 0;
}
