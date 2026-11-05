#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

int solution(vector<int> people, int limit) {
    // 1. 몸무게 순서대로 정렬 
    sort(people.begin(), people.end()); 
    
    // 2. 투 포인터 구현 (인덱스) 
    int left = 0;  
    int right = people.size() - 1; 
    
    // 3. 구명 보트 개수 
    int cnt = 0; 
    
    // 4. 투 포인터가 교차하기 직전까지 
    while (left <= right) {
        // 가장 무거운 사람과 가장 가벼운 사람이 같이 탈 수 있으? 
        if (people[left] + people[right] <= limit) {
            left++; 
        }
        
        // 가장 무거운 사람은 무조건 구명 보트 1개를 태운다 
        right--; 
        
        // 개수 up 
        cnt++; 
        
    }
    
    return cnt;
}