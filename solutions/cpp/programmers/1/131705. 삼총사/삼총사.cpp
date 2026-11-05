#include <string>
#include <vector>
#include <iostream> 
using namespace std;

/*
    3명의 점수를 더했을 때 0이 되면 삼총사 
    학생들 중 삼총사를 만들 수 있는 방법의 수를 return 
*/
int solution(vector<int> number) {
    int answer = 0;
    for (int i = 0; i < number.size(); i++) {
        for (int j = i + 1; j < number.size(); j++) {
            for (int k = j + 1; k < number.size(); k++) {
                if (number[i] + number[j] + number[k] == 0) {
                    answer++; 
                }
            }
          
        }
    }
    return answer;
}