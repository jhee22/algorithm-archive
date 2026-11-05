#include <vector>
#include <string>
#include <queue> 
#include <set>
#include <iterator> 

using namespace std; 
/*
    "I 16" : 16을 뀨에 넣음 
    "D -1" : 최솟값을 삭제 
    "D 1"  : 최대값을 삭제  
*/

vector<int> solution(vector<string> operations) {
    /* 
        뀨가 비어있음 [0, 0] 리턴
        return [최댓값, 최솟값]
    */
    
    // 중복을 허용하고, 자동으로 정렬해 주는 자료구조 
    /*
        ms.insert(숫자) : 삽입 
        ms.empty() : 비어있는지 확인 
        *ms.begin() : 최솟값
        *ms.rbegin() : 최대값 
        ms.erase(ms.begin()) : 최소값 하나 제거 
        ms.erase(prev(ms.end())) : 최대값 하나 제거 
    */
    multiset<int> ms; 
    
    // operations 순회 
    // "I 16"
    for (int i = 0; i < operations.size(); i++) {
        // command 
        string action = operations[i]; 
        string oper = action.substr(0, 1); 
        int num = stoi(action.substr(2)); 
        
        if (oper == "I") {
            ms.insert(num); 
        }
        
        // 삭제하기 전에 물었나요? 
        if (!ms.empty() && oper == "D") {
            if (num == -1) {
                ms.erase(ms.begin()); 
            } 
            
            else if (num == 1){
                ms.erase(prev(ms.end())); 
            }
        }
  
    }
    
    
    if (ms.empty()) {
        return {0, 0};
    } 
    
    return {*ms.rbegin(), *ms.begin()};
}