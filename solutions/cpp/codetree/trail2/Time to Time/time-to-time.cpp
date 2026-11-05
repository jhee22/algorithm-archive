#include <iostream>

using namespace std;

int a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;

    // Please write your code here.
    // 분 
    if (d < b) {
        c--; 
        d += 60; 
    }
    d -= b; 

    // 시간 
    c -= a; 
    c *= 60; 

    cout << c + d; 
    return 0;
}