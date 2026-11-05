#include <iostream>

// 2번 이상 지나간 구간을 구함 
using namespace std;

int n;
int x[100];
char dir[100];
// 1 <= N <== 100, 1 <= x <= 10 
int cnt[2001] = {}; 

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }

    // 시작점 
    int start = 0; 
    for (int i = 0; i < n; i++) {
        if (dir[i] == 'L') {
            int end = start - x[i]; 

            for (int j = end; j < start; j++) {
                // 음수 인덱스 피하기 
                cnt[j + 1001]++; 
            }

            // 다음 명령은 도착한 위치에서 시작 
            start = end; 
        }

        else if (dir[i] == 'R') {
            int end = start + x[i]; 

            for (int j = start; j < end; j++) {
                cnt[j + 1001]++; 
            }

            start = end; 

        }
    }

    int answer = 0; 
    for (int i = 0; i < 2001; i++) {
        if (cnt[i] >= 2) {
            answer++; 
        }
    }

    cout << answer; 
    return 0;
}