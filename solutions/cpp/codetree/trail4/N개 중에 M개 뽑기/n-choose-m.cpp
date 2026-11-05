#include <iostream>
#include <vector> 

using namespace std;

int N, M;
vector<int> selected; 

void dfs(int depth) {
    // 종료 조건 is 다 돌았을 때 
    if (depth == M) {
        // 출려억
        for (int num : selected) {
            cout << num << " ";
        }
        cout << "\n"; 
        return; 
    }


    

    // 탐색해 줘잉~ 
    for (int i = 1; i <= N; i++) {
        // selected 안에 있는 숫자와 절대로 겹쳐서는 안됨 
        // selected 를 순회하고 나서도, 중복이 있다는 사실을 밖의 scope에도 전달해야함 
        
        // 조합의 수 
        // selected.back() : 마지막 수 
        if (!selected.empty() && 
            selected.back() >= i
        ) continue; 
        
        bool flag = false; 
        for (int idx = 0; idx < selected.size(); idx++) {
            if(selected[idx] == i ) {
                flag = true; 
                break; // for문 종료 
            }
        }

        if (flag) {
            continue;
        }

        // 안겹치면 selected 
        selected.push_back(i); 
        dfs(depth + 1); 
        selected.pop_back(); 
    }

}


int main() {
    cin >> N >> M;

    // Please write your code here.
    dfs(0); 
    return 0;
}
