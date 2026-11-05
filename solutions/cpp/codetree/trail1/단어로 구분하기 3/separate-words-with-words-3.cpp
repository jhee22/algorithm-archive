#include <iostream>
#include <vector> 
using namespace std;

int main() {
    // Please write your code here.
    string s; 
    vector<string> vs; 
    for (int i = 0; i < 10 && cin >> s; ++i) {
        vs.push_back(s); 
    }

    for (int i = vs.size() - 1; i >= 0; i--) {
        cout << vs[i] << "\n"; 
    }
    return 0;
}