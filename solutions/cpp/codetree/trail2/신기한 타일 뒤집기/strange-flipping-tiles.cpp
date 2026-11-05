#include <iostream>
using namespace std;

int n;
int x[1000];
char dir[1000];

// OFFSET : 1000 * 100 
// 배열의 크기 : 1000 * 100 * 2 + 1 
int black[200001] = {}; 
int white[200001] = {}; 

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }

    int start = 0; 
    for (int i = 0; i < n; i++) {
        // 왼쪽으로 이동하면 흰색 
        if (dir[i] == 'L') {
            int end = start - (x[i] - 1); 
            for (int j = end; j <= start; j++) {
                black[j + 100000] = 0; 
                white[j + 100000] = 1;
            }
            start = end; 

        }

        // 오른쪽으로 뒤집히면 검은색 
        else if (dir[i] == 'R') {
            int end = start + (x[i] - 1); 
            for (int j = start; j <= end; j++) {
                white[j + 100000] = 0;
                black[j + 100000] = 1; 
            }
            start = end; 
        }
    }

    // 개수 세기 흰/ 검 순 
    int w = 0;
    int b = 0; 
    for (int i = 0; i < 200001; i++) {
        w += white[i]; 
        b += black[i];
    }


    cout << w << " "<< b; 

    return 0;
}