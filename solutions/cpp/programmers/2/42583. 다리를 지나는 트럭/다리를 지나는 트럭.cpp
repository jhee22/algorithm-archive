#include <string>
#include <vector>
#include <queue> 
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // 시간에 따라 바뀌는 변수들 : 인덱스, 다리에 있는 트럭 무게, 시간 
    int idx = 0; 
    int curr_w = 0;
    int time = 0; 
    
    // queue 자료형 : {트럭의 무게, 시간}
    queue<pair<int, int>> q; 
    
    // 트럭 다 넣었을 때, 트럭이 다 건넜을 때 
    // 마지막 트럭 지났는데 q 에 넣었으니까 아직 q 가 안비는 경우! 
    while (idx < truck_weights.size() || !q.empty()) {
        time++; 
        
        // 나갈 트럭 처리 
        if (!q.empty() && q.front().second == time) {   
            curr_w -= q.front().first; 
            q.pop(); 
        }
        
        // 현재 트럭 더 얹어 
        if (idx < truck_weights.size() &&
            curr_w + truck_weights[idx] <= weight) {
            
            curr_w += truck_weights[idx]; 
            q.push({
                truck_weights[idx],
                time + bridge_length                 
            }); 
            
            // 실제 뀨에 넣었을때만 
            idx++; 
        }
        
    }
    
    return time;
}