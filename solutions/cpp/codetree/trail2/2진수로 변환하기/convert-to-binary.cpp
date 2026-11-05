#include <iostream>
#include <vector> 
#include <algorithm> 

using namespace std;

int n;
int cnt; 
// 칸을 미리 만들어놔야함 
vector<int> digit; 

int main() {
    cin >> n;

    cnt = 0; 
    while (true) {
        if (n < 2) {
            digit.push_back(n % 2);  
            break; 
        }

        digit.push_back(n % 2); 
        n /= 2; 
    } 
    
    // 출력
    for (int i = digit.size() - 1; i >= 0; i--) {
        cout << digit[i] << ""; 
    }


    return 0;
}