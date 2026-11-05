#include <iostream>

using namespace std;

int N, M, K;
int student[10000]; 

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        cin >> student[i];
    }
    int answer = 0; 
    int cnt[N+1] = {0}; 
    for (int i = 0; i < M; i++) {
        cnt[student[i]]++; 
        if (cnt[student[i]] == K) {
            answer = student[i]; 
            break; 
        }
    }
    
    if (answer != 0) {
        cout << answer;
    } else {
        cout << -1; 
    }

    return 0;
}