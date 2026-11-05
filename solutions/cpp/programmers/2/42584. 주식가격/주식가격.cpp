#include <string>
#include <vector>
#include <iostream> 
using namespace std;

// 가격이 떨어지지 않은 기간 
vector<int> solution(vector<int> prices) {
    vector<int> result;
    for (int i = 0; i < prices.size(); i++) {
        int time = 0; 
        for (int j = i+1; j < prices.size(); j++) {
            // 입력 크기가 크니까 반대로 생각 
            time++; 
            if (prices[i] > prices[j]) {
                break; 
            }
        }
        result.push_back(time); 
    }
    
    return result;
}