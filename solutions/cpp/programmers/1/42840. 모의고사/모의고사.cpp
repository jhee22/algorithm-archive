#include <string>
#include <vector>
#include <algorithm> 
#include <iostream> 

using namespace std;
/*
    1번 수포자가 찍는 방식 : 1 2 3 4 5 반복
    2번 수포자 : 2, 1, 2, 3, 2, 4, 2, 5 반복 
    3번 수포자 : 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 반복 
    
    가장 많은 문제를 맞힌 사람을 리떤! 

*/ 

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    // 수포자 
    vector<int> std1 = {1, 2, 3, 4, 5};
    vector<int> std2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> std3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; 
    
    // 정답 비교 
    int s1 = 0; 
    int s2 = 0; 
    int s3 = 0;
    
    //cout << std1[std1.size() % 2]; 
    // % 0 은 불가능임 !!! 
    // answer, answers 구분 유의 
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == std1[i % std1.size()]) {
            s1++; 
        }
        
        if (answers[i] == std2[i % std2.size()]) {
            s2++; 
        }
        
        if (answers[i] == std3[i % std3.size()]) {
            s3++; 
        }
    } 
    
    int max_v = max({s1, s2, s3}); 
    if (s1 == max_v) {
        answer.push_back(1); 
    } 
    
    if (s2 == max_v) {
        answer.push_back(2); 
    }
    
    if (s3 == max_v) {
        answer.push_back(3); 
    }
    
    // 오름차순 정렬 
    sort(answer.begin(), answer.end()); 
    return answer;
}