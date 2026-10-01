#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    while (n > 0) {
        int digit = n % 3; 
        answer = answer * 3 + digit;    
        
        n /= 3; 
    }
    
    return answer;
}