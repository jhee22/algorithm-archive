#include <algorithm> 
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for (long long idx = left; idx <= right; idx++) {
        long long row = idx / n; 
        long long col = idx % n; 
        
        answer.push_back((int)(max(row, col) + 1));
    }
   
    
    
    return answer;
}