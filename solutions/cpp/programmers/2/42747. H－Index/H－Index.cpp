#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

int solution(vector<int> citations) {
    // 1. 정렬 
    sort(citations.rbegin(),
         citations.rend()
    );
    
    // 2. 조건을 만족하는 논문의 개수 
    // <> 논문의 인용 횟수라 생각하면 안됨 
    // 논문의 인용 횟수는 i + 1 로 관리하는 것 
    int h = 0;  
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i + 1) {
            h++; 
        } else {
            return h; 
        }
    }
    
    // int answer = 0;
    // return answer;
}