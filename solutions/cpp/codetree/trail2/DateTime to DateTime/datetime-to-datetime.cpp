#include <iostream>

using namespace std;

int a, b, c;

int main() {
    cin >> a >> b >> c;

    // 111일 11시 11분 
    int total = (10 * 24 * 60) + (11 * 60) + 11; 
    int compare = ((a - 1) * 24 * 60) + (b * 60) + c; 

    if (total > compare) {
        cout << -1;
        return 0;  
    }     

    else {
        cout << compare - total; 
    }

    return 0;
}