#include <iostream>
#include <algorithm> 

using namespace std;

int N;
int arr[1000];
int maxValue; 

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int cnt = 1; 
    for (int i = 0; i < N; i++) {
        if (i == 0 || arr[i] !=  arr[i-1]) {
            maxValue = max(cnt, maxValue);  
            cnt = 1; 
            continue; 
        }
        cnt++; 
        maxValue = max(cnt, maxValue);  
    }

    cout << maxValue; 

    return 0;
}