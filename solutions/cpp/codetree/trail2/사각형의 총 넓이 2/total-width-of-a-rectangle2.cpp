#include <iostream>

using namespace std;

int N;
int x1[10], y1[10];
int x2[10], y2[10];
int OFFSET = 100; 
int board[201][201] = {0}; 
int sum = 0; 

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        x1[i] += OFFSET; 
        x2[i] += OFFSET;
        y1[i] += OFFSET; 
        y2[i] += OFFSET; 


        for (int x = x1[i]; x < x2[i]; x++) {
            for (int y = y1[i]; y < y2[i]; y++) {
                board[x][y] = 1; 
            }
        }
    }

    // 배열의 범위를 벗어났기 때문에 
    for (int i = 0; i < 201; i++) {
        for (int j = 0; j < 201; j++) {
            if (board[i][j] == 1) {
                sum++; 
            }
        }
    }
    
    cout << sum; 
    return 0;
}