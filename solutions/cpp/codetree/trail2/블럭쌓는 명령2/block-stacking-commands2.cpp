#include <iostream>
#include <vector> 

using namespace std;

int N, K;
int A[100], B[100];

int answer; 

int main() {
    // 1번 칸부터 N번 칸 
    // 명령은 총 K번 
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> A[i] >> B[i];
    }
    
    // 쌓인 블럭의 수 
    vector<int> vp(N + 1, 0); 
    for (int i = 0; i < K; i++) {
        // Ai 번쨰 칸부터 Bi 번째 칸까지 양 끝칸 포함 
        for (int j = A[i]; j <= B[i]; j++) {
            vp[j]++; 
        }
    }
    
    // 합계
    for (int i = 0; i < vp.size(); i++) {
        if (answer < vp[i]) {
            answer = vp[i]; 
        } 
    }
    cout << answer; 
    return 0;
}