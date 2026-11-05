#include <string>
#include <vector>
#include <unordered_map>
#include <iostream> 
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    // 1. hash 객체에 담기 
    unordered_map<string, int> m; 
    for (int i = 0; i < want.size(); i++) {
        m[want[i]] = number[i]; 
    } 
    
    // 2. discount
    for (int i = 0; i <= discount.size() - 10; i++) {
        // 1일부터 10일간 할인 품목 개수 세기 
        unordered_map<string, int> tmp; 
        for (int j = i; j < i + 10; j++) {
            tmp[discount[j]]++; 
        }
        // 원하는것과 개수가 동일하면 answer++
        bool flag = true;
        for (const auto&[item, cnt] : m) {
            if (tmp[item] != cnt) {
                flag = false;
                break; 
            }
        }
        if (flag) {
            answer++; 
        }
    }
    
    
    return answer;
}