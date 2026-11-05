#include <iostream>

using namespace std;

int m1, d1, m2, d2;

int main() {
    cin >> m1 >> d1 >> m2 >> d2;

    // Please write your code here.
    
    int result = 1; 
    // 달 별 조건 분기를 만드는 것보다 각 달의 일수를 배열에 저장하는 것이 더 효율적 
    // 1월달부터 맞추려고, days[1] = 31 
    int days[] = {
        0,
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31 
    }; 

    pair<int, int> curr = {m1, d1}; 
    pair<int, int> next =  {m2, d2}; 

    // 각 월을 날짜를 순회하는 것이 아니라 
    // (2, 27) -- curr 
    // (2, 28)
    // (3, 1) 

    // targetDt 와 같기 전까지 
    // while : 특정 상태가 될때ㅐ까지 반복 
    while (curr != next) {
        // 하루 증가 
        curr.second++; 
        result++; 

        if (curr.second > days[curr.first]) {
            // 다음달 
            curr.first++; 
            // 1일로 초기화
            curr.second = 1; 
        }

    }

    cout << result; 
    return 0;
}