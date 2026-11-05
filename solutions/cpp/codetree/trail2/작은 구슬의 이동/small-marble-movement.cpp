#include <iostream>

using namespace std;

int n, t;
int r, c;
char d;

int main() {
    // n : matrix n x n 
    // t : 시간 (초) 
    cin >> n >> t;
    // r,c : 초기 구슬 위치
    // d : 초기 구술 이동 방향 
    cin >> r >> c >> d;

    // Please write your code here.
    // 1. 초기 구슬의 위치 
    pair <int, int> pos = {r, c};
    
    // 2. 방향 저장 
    int dir = 0; 

    // 3. 방향은 들어가기 전에 딱 한번만 체크, % 계산 할 필요가 없음 
    if (d == 'U') dir = 0; 
    else if (d == 'D') dir = 1; 
    else if (d == 'R') dir = 2; 
    else if (d == 'L') dir = 3; 


    // 4. t초동안 이동     
    for (int i = 0; i < t; i++) {
        // 매 초(반복)마다 현재 위치 기준으로 다시 선언해야함 
        int nr = pos.first; 
        int nc = pos.second; 

        // 다음 위치 후보 계산 
        if (dir == 0) {
            nr--;
        } 

        else if (dir == 1) {
            nr++;
        }

        else if (dir == 2) {
            nc++;
        }

        else if (dir == 3) {
            nc--; 
        }

        // 유효성 검사 (1부터 시작함 주의)
        if (nr < 1 || nr > n || nc < 1 || nc > n) {
            // 범위를 벗어나면 위치 이동은 하지않고 방향만 반대 
            if (dir == 0) {
                dir = 1; 
            } 

            else if (dir == 1) {
                dir = 0; 
            }

            else if (dir == 2) {
                dir = 3; 
            }

            else {
                dir = 2; 
            }
        } 
        // 유효한 경우 
        else {
            pos.first = nr; 
            pos.second = nc; 
        }
    

        

    }

    cout << pos.first << " " << pos.second; 


    return 0;
}