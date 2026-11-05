#include <iostream>

using namespace std;

int x1[3], y1[3];
int x2[3], y2[3];
int offset = 1000; 
int board[2001][2001] = {0}; 
int sum; 

// offset 구해놓고 안 더함 
int main() {
    // A
    cin >> x1[0] >> y1[0] >> x2[0] >> y2[0];
    x1[0] += offset; 
    y1[0] += offset; 
    x2[0] += offset; 
    y2[0] += offset; 
    for (int x = x1[0]; x < x2[0]; x++) {
        for (int y = y1[0]; y < y2[0]; y++) {
            board[x][y] = 1; 
        }
    }
    
    // B
    cin >> x1[1] >> y1[1] >> x2[1] >> y2[1];
    x1[1] += offset; 
    y1[1] += offset; 
    x2[1] += offset; 
    y2[1] += offset; 
    for (int x = x1[1]; x < x2[1]; x++) {
        for (int y = y1[1]; y < y2[1]; y++) {
            board[x][y] = 1; 
        }
    }   
    
    // M 
    cin >> x1[2] >> y1[2] >> x2[2] >> y2[2];
    x1[2] += offset; 
    y1[2] += offset; 
    x2[2] += offset; 
    y2[2] += offset; 
    for (int x = x1[2]; x < x2[2]; x++) {
        for (int y = y1[2]; y < y2[2]; y++) {
            board[x][y] = 0; 
        }
    } 

    for (int i = 0; i < 2001; i++) {
        for (int j = 0; j < 2001; j++) {
            if (board[i][j]) {
                sum++;
            }
        }
    }

    cout << sum; 
    
    return 0;
}