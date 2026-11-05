#include <iostream>
#include <vector> 
#include <algorithm> 
using namespace std;

int main() {
    // Please write your code here.
    string word; 
    vector<pair<string, int>> s; 

    int idx = 0; 
    while (cin >> word) {
        s.push_back({word, idx});
        idx++;  
    } 

    // 아 주어진 순서와 반대로 인덱스 아차차 
    sort(s.begin(), s.end(),
    [] (const pair<string, int>& a, const pair<string, int>& b){
        return a.second > b.second; 
    }); 

    for (const auto&[string, idx] : s) {
        cout << string << "\n"; 
    }
    return 0;
}