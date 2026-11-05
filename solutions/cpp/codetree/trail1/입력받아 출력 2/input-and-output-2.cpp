#include <iostream>
#include <string> 

using namespace std;

int main() {
    string s; 
    cin >> s; 
    for (char elem : s) {
        if (elem != '-') {
            cout << elem << ""; 
        }
    }
    return 0;
}