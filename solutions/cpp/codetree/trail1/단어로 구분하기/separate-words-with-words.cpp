#include <iostream>
#include <string> 
using namespace std;

int main() {
    // c에서는 공백 단위로 문자 입력 받음 
    for (int i = 0; i < 10; i++) {
        string s; 
        cin >> s; 
        cout << s << "\n"; 
    }
    return 0;
}