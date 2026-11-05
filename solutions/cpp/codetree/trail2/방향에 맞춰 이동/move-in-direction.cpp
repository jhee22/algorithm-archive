#include <iostream>

using namespace std;

int n;
char dir[100];
int dist[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dir[i] >> dist[i];
    }

    // Please write your code here.
    // 1. 현재 좌표 pair 선언 
    // pair {0,0} : x = 0, y = 0 
    pair<int, int> pos = {0,0}; 
    
    
    /// 방향에 따라 이동 
    for (int i = 0; i < n; i++) {
        if (dir[i] == 'N') {
            pos.second += dist[i]; 
        } else if (dir[i] == 'E') {
            pos.first += dist[i];
        } else if (dir[i] == 'S') {
            pos.second -= dist[i];
        } else {
            pos.first -= dist[i]; 
        }
        
    }

    cout << pos.first << " " << pos.second; 
    return 0;
}