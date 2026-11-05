#include <iostream>
#include <vector> 

using namespace std;

int n;
// 자리수 방문 
vector<int> selected; 

void dfs(int depth) {
    // 종료 조건 
    if (depth == n) {
        for (int elem : selected) {
            cout << elem << " "; 
        }
        cout << "\n"; 
        return; 
    }

    // 탐색 
    for (int num = 1; num <= n; num++) {
        // 순열 
        bool flag = false;  
        for (int idx = 0; idx < selected.size(); idx++) {
            if (selected[idx] == num) {
                flag = true; 
                break; 
            }
        }

        if (flag) {
            continue; 
        }

        flag = false; 

        selected.push_back(num); 
        dfs(depth + 1); 
        selected.pop_back(); 

    }

}


int main() {
    cin >> n;

    // Please write your code here.
    dfs(0); 
    return 0;
}
