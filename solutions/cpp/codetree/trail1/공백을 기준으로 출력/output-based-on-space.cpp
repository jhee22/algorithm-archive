#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    string word; 
    string answer = ""; 

    while (cin >> word) {
        answer += word; 
    }
    cout << answer; 
    return 0;
}