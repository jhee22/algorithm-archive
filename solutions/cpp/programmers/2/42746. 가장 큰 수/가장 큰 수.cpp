#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

string solution(vector<int> numbers) {
    // 1. int -> string 변환 
    vector<string> nums; 
    
    for (int num : numbers) {
        nums.push_back(to_string(num)); 
    }
    
    // 2. 두 문자를 이어 붙였을 때 더 큰 순서로 정렬 
    sort(nums.begin(), nums.end(), 
        [] (const string& a, const string& b) {
            return a + b > b + a; 
        }
    );
        
    // 3. 가장 앞이 0이면 전체가 0 
    if (nums[0] == "0") {
        return "0"; 
    }
    
    // 4. 순서대로 이어 붙이기 
    string answer = ""; 
    for (const string& num: nums) {
        answer += num; 
    }
    return answer; 

}