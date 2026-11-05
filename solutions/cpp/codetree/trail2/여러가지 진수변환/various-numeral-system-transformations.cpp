#include <iostream>
#include <vector> 
#include <cmath> 

using namespace std;

int N, B;
vector<int> digits; 

int main() {
    // 정수 N, 바꿀 진수 B 
    cin >> N >> B;

    // 4진수 변환 
    if (B == 4) {
        while (true) {
            if (N < 4) {
                digits.push_back(N % 4); 
                break;
            }
            digits.push_back(N % 4); 
            N /= 4; 
        }

    }

    // 8진수 변환 
    else if (B == 8) {
        while (true) {
            if (N < 8) {
                digits.push_back(N % 8);
                break; 
            }
            digits.push_back(N % 8); 
            N /= 8; 
        }
    }

    // 순서 역순 정렬 
    for (int i = digits.size() - 1; i >= 0; i--) {
        cout << digits[i]<< ""; 
    }
    


    return 0;
}