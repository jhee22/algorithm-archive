#include <string>
#include <vector>
 
using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow; 
    
    for (int height = 3; height <= total; height++) {
        // height 가 전체 넓이의 약수가 아니면 꺼져 
        if (total % height != 0) {
            continue; 
        }
        
        // 가로 
        int width = total / height; 
        
        // 문제 조건 가로 >= 세로 
        if (width < height) {
            continue;
        }
        
        // yellow 
        if ((width -  2) * (height - 2) == yellow) {
            return {width, height}; 
        }
        
    }
}