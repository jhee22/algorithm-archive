#include <vector>
#include <iostream> 

using namespace std;
/*
    Solution : k합을 만족하는 부분수열 [인덱스 ~ 인덱스]
    원소가 모두 양수 : 오른쪽을 늘리면 합 증가, 왼쪽 줄이면 감소
    합이 K : 현재 합과 k를 비교해 구간 조절 
    길이 최대 <= 1,000,000 -> 모든 구간을 비교하긴 부담
    길이도 같으면 가장 앞 쪽 -> 동률일때 기존의 더 앞선 구간 유지 
    
*/
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    // 투포인터 구현 : 같은 방향으로 감 교차 x 
    int left = 0; 
    int sum = 0; 
    int len = sequence.size() + 1; // 아직 
    
    for (int right = 0; right < sequence.size(); right++) {
        // 1. 새 오른쪽 원소를 sum 에 더해 
        sum += sequence[right]; 
        
        // 2. sum > k 이면 현재 왼쪽 원소를 빼고 left 증가 
        if (sum > k) {
            // sum 이 k 보다 클 때까지 
            while (sum > k) {
                sum -= sequence[left]; 
                left++;    
            }
            // cout << left << " " << right << " "<< sum << "\n"; 
        }
        
        // 3. sum == k, 기존 정답보다 짧으면 갱신 
        if (sum == k &&  (right - left + 1) < len) {
            len = right - left + 1; 
            answer = {left, right}; 
        }

    }     
    
    return answer;
}