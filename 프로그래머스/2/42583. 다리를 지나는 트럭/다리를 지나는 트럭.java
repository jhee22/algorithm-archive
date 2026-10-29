/*
관리해야 하는 것
- 지금 다리 위에 있는 트럭의 weights와 위치 (bridge)
- 현재 다리 위 트럭 전체 무게 (totalWeights)
- 현재 몇초가 지났는지 (time)
*/
import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        Queue<Integer> q = new LinkedList<>();
        
        for(int i=0; i<bridge_length; i++){
            q.offer(0);
        }
        
        int idx = 0;
        int time = 0;
        int totalWeights = 0;
        
        while (idx < truck_weights.length || totalWeights > 0){
           
            //1초 경과 
            time++;
            
            //다리 맨 앞 제거 -> 다리가 한 칸 이동한 효과 
            totalWeights -= q.poll();
            
            //새로운 트럭 진입 가능 
            if(idx < truck_weights.length && 
              totalWeights + truck_weights[idx] <= weight) {
                q.offer(truck_weights[idx]);
                totalWeights += truck_weights[idx];
                idx++;
            } else {
                q.offer(0);
            }
        }
        return time;
    }
}