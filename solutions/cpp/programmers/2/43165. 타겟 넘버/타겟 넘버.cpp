#include <string>
#include <vector>

using namespace std;
// 1. 전역 변수 선언 
int idx = 0; 
int cnt = 0; 

// 2. DFS 구현 
// 지금 어디까지 왔으며, 다음 단계에서도 필요한 값이 무엇인가 
// DFS 파라미터 : 지금 이 지점까지 오면서 만들어진 상태 중, 다음 선택을 할 때 꼭 필요한 값 
void dfs(int idx, int sum, vector<int>& numbers, int target) {
    // 종료 조건 : numbers 배열을 다 순회 했을 때  
    if (idx == numbers.size()) {
        if (sum == target) {
            cnt++; 
        }
        return; 
    }

    
    // 재귀 호출 
    // 다음 위치, 합계(더하는 건 현재 숫자임!!!)
    // (1) 더하기 
    dfs(idx + 1, sum + numbers[idx], numbers, target); 
    // (2) 빼기 
    dfs(idx + 1, sum - numbers[idx], numbers, target); 
}



int solution(vector<int> numbers, int target) {
    // *** 시작 시 인덱스 및 합계 다 0 으로 초기화 하고 들어가야함 *** 
    dfs(idx, 0, numbers, target); 
    return cnt;
}