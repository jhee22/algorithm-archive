#include <iostream>
#include <string> 
using namespace std;

string dirs;

int main() {
    cin >> dirs;

    // Please write your code here.
    // 1. 초기 위치 
    pair<int, int> pos = {0, 0}; // x, y 

    // *** 2. 현재 방향을 저장 **** 
    // 0 : N, 1 : E, 2 : S, 3 : W 
    int dir = 0; 

    // 3. 명령 문자열 
    // 문자열의 길이 1 <= S <= 100 000 
    for (int i = 0; i < dirs.length(); i++) {
        // 방향 셋팅 
        if (dirs[i] == 'L') {
            dir = (dir + 3) % 4; 
        } 
        else if (dirs[i] == 'R') {
            dir = (dir + 1) % 4; 
        } 

        // 이동 
        else if (dirs[i] == 'F') {
            if (dir == 0) {
                pos.second++; 
            } else if (dir == 1) {
                pos.first++; 
            } else if (dir == 2) {
                pos.second--;
            } else {
                pos.first--; 
            }
        }
    }
    cout << pos.first << " " << pos.second; 
    return 0;
}