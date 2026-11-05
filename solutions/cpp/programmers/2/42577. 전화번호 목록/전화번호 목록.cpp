#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

bool solution(vector<string> phone_book) {
    // 
    sort(phone_book.begin(), phone_book.end()); 
    
    for (int i = 0; i < phone_book.size() - 1; i++) {
        string cur = phone_book[i]; 
        string next = phone_book[i + 1]; 
        
        // next가 cur 로 시작하면, cur 은 next 의 접두어 
        if (next.compare(0, cur.size(), cur) == 0) {
            return false; 
        }
    }
    
    return true;
}