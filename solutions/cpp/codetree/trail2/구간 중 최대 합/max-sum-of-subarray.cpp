#include <iostream>
#include <algorithm> 

using namespace std;

int n, k;
int arr[100];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int maxValue = 0; 
    for (int i = 0; i <= n - k; i++) {
        int total = 0; 
        for (int j = i; j < i+k; j++) {
            total += arr[j]; 
        }
        maxValue = max(maxValue, total); 
    }
    cout << maxValue; 

    return 0;
}