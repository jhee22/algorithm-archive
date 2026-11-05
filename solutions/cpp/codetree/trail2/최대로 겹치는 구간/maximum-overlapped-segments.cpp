#include <iostream>
#include <algorithm> 

// 구간에 선분이 최대 몇개 겹치는지 구하는 문제 
using namespace std;

int n;
int x1[100], x2[100];
int cnt[201]; 

int main() {
    // N개의 선분 
    cin >> n;

    // 시작점, 끝점 
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }
    
    for (int i = 0; i < n; i++) {
        int start = x1[i] + 100; 
        int end = x2[i] + 100; 

        for (int j = start; j < end; j++) {
            cnt[j]++; 
        }
    }
    
    int answer = 0; 
    for (int j = 0; j < 200; j++) {
        answer = max(answer, cnt[j]); 
    }


    cout << answer; 
    return 0;
}