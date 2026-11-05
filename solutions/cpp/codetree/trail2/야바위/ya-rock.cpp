#include <iostream>
#include <vector> 
#include <algorithm> 

using namespace std;

int N;
int a[100], b[100], c[100];

int main() {
    cin >> N;

    // 종이컵에 붙은 번호가 아니라 위치 
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    // Please write your code here.
    int maxValue = 0; 

    // tuple 구조 비추 : 배열처럼 [] 접근이 안되기 때문 
    // 조약돌의 시작 위치를 전부 가정 (이 때부터 반복문 드감) 
    for (int start = 1; start <= 3; start++) {

        int stone = start; 
        int score = 0; 

        for (int i = 0; i < N; i++) {
            // 교환 롸직 
            if (stone == a[i]) {
                stone = b[i]; 
            } 

            else if (stone == b[i]) {
                stone = a[i]; 
            }

            // 정답 확인 
            if (stone == c[i]) {
                score++; 
            }
        }
        maxValue = max(score, maxValue); 
    }

    cout << maxValue; 

    
    return 0;
}