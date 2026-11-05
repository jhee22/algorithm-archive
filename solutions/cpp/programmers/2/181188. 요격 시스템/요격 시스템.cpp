#include <string>
#include <vector>
#include <algorithm> 
#include <iostream>

using namespace std;

/*
    (이해) 문제를 한 문장으로 바꾼다
    - [s, e] : 이 구간 안에 아무 지점에 미사일 하나 쏘면 잡을 수 있음 
    - 여러 구간이 주어졌을 때, 모든 구간을 찌르는 최소 지점 개수를 구하기 
    - 끝나는 지점이 중요 : 끝점이 가장 빠른 지점부터 처리 
    - 끝점 e 오름차순 정렬
*/

/*
    구간 문제 사고 방식
    문제에서 구간[시작, 끝] 이 여러 개 등장
    -> 겹치는 구간을 묶는 문제? 
    -> 최소/최대 라는 말이 있음? 
    -> 정렬 + 그리디 의심
    -> 시작점 정렬 vs 끝점 정렬 의심
    -> 가장 빨리 끝나는 놈부터 처리하면 미래 선택지를 많이 남길 수 잇나? 
    -> 끝점 정렬 그리디
*/ 

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int last = -1;  // 내가 마지막으로 쏜 요격 미사일의 기준 위치 
        
    // 1. 끝점 기준으로 오름차순 정렬
    sort(targets.begin(), targets.end(),
         [] (const vector<int>& a, const vector<int>& b) {
             return a[1] < b[1]; 
         }
    );
    
    for (int i = 0; i < targets.size(); i++){
        // 시작점, 끝점
        int start = targets[i][0]; 
        int end = targets[i][1]; 
        
        // 기존 요격으로 못 잡는가? 
        if (last <= start) {
            // 새 미쏠 
            answer++;
            // 새 기준점
            last = end; 
        }
    }
    
    
    return answer;
}