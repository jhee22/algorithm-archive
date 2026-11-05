#include <iostream>
#include <vector> 
#include <cmath> 
#include <algorithm>

using namespace std;

int n;
int num[20];
int minValue = 1e9; 
int total = 0;  
vector<int> selected; 

void dfs(int start) {
    // 종료 조건
    if (selected.size() == n) {
        int sum1 = 0; 

        for (int x : selected) {
            sum1 += x; 
        }

        int sum2 = total - sum1; 
        minValue = min(abs(sum1 - sum2), minValue); 

        return; 
    }

    // 탐색 
    for (int i = start; i < 2 * n; i++) {
        selected.push_back(num[i]); 
        dfs(i+1); 
        selected.pop_back(); 
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
        total += num[i]; 
    }

    // Please write your code here.
    dfs(0); 
    cout << minValue; 
    return 0;
}
