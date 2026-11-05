#include <string>
#include <vector>
#include <algorithm> 
#include <iostream> 
using namespace std;
/*
    solution
    모든 차량이 한 번은 단속용 카메라를 만나도록 하려면 최소 몇 대의 카메라 설치? 
    
    매개변수
    routes : 차량의 이동 경로, 
    routes[i][0] : i번째 차량이 고속도로에 진입한 지점 
    routes[i][1] : i번째 차량이 고속도로에서 나간 지점 
    
    조건
    - 차량의 진입/진출 지점에 카메라가 설치되어있어도 카메라를 만남
    - 차량의 진입 지점, 진출 지점 -30,000 <= x <= 30,000 
*/
int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), 
        [] (const vector<int>& a, const vector<int>& b){
            return a[1] < b[1]; 
    });
    
    int standard = routes[0][1]; 
    answer++; 
    
    for (int i = 1; i < routes.size(); i++) {
        // 현재 카메라로 다음 차량을 못잡는 경우 
        if (standard < routes[i][0]) {
            standard = routes[i][1];
            answer++; 
        }
    }
    
    
    return answer;
}