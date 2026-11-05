#include <string>
#include <vector>
#include <unordered_map> 

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1; 
    
    // hash 객체 생성 및 입력 
    unordered_map<string, int> m; 
    for (int i = 0; i < clothes.size(); i++) {
        string type = clothes[i][1]; 
        m[type]++;
    }
    
    // hash 객체 순회 
    for (const auto& [type, count] : m) {
        answer *= count + 1;
    }
    
    
    return answer - 1;
}