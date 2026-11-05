#include <iostream>

using namespace std;

int N;
int x[100], y[100];
int offset = 100; 

//  최소 : -100 + 100 = 0 
//  최대 : 92 + 100 = 192 + 8, 200
int board[200][200] = {0}; 

int main() {
    cin >> N;

    // 꼭짓점부터 8 x 8 색종이가 있음 
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        x[i] += offset; 
        y[i] += offset; 

        // 변수명이 같아서 생긴 오류 
        for (int width = x[i]; width < x[i] + 8; width++) {
            for (int height = y[i]; height < y[i] + 8; height++) {
                board[width][height] = 1; 
            }
        }
    }

    // 집계
    int sum = 0; 
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            if (board[i][j]) {
                sum++;
            }
        }
    }

    cout << sum; 
    return 0;
}