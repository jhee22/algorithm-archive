#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

/* 문제 이해 
    n : 입국 심사를 기다리는 사람 수 
    times : 각 심사관이 한 명을 심사하는데 걸리는 시간 
    모든 사람이 심사를 받는 최소 시간 
*/

/*  예제 이해 
    1 2 3 4 5 6
    7 10 14 20 21 28 
*/

long long solution(int n, vector<int> times) {
    long long answer = 0;
    // 입력값이 크기 때문에 어떤 시간을 하나 찍어보고 그 시간 안에 n명을 처리할 수 있는지 확인하는 것임 
    // long long : int 보다 훨씬 큰 정수형 
    
    // 최소 후보 시간 : 0 
    long long left = 0; 
    // 최대 후보 시간 : 가장 빠른 심사관이 모든 사람을 혼자 처리
    long long right =  (long long) (*min_element(times.begin(), times.end())) * n; 
    
    // 가운데
    while (left <= right) {
        long long mid = (left + right) / 2; 
        
        // mid 분 동안 처리 가능한 사람의 수 
        long long cnt = 0; 
        for (int t : times) {
            cnt += mid / t; 
        }
        if (cnt >= n){
            answer = mid; 
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    

    return answer;
}