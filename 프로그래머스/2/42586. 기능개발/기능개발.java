/*
기능 개발 속도 다름
뒤에 있는 기능이 먼저 개발될 수 있음 -> 이때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 같이 배포됨
먼저 배포되어야 하는 순서대로 작업의 진도가 적힌 progresses
각 작업의 개발속도 speeds
각 배포마다 몇 개의 기능이 배포되는지 return 
*/

import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] days = new int[progresses.length];
        
        for(int i=0; i<progresses.length; i++){
            days[i] = (int)Math.ceil((double)(100-progresses[i]) / speeds[i]);
        }
        
        List<Integer> ans = new ArrayList<>();
        
        int max = days[0];
        int cnt = 1;
        
        for(int i=1; i<days.length; i++){
            if(days[i] <= max){
                cnt++;
            } else {
                ans.add(cnt);
                max = days[i];
                cnt = 1;
            }
        }
        
        ans.add(cnt);
        
        int[] result = new int[ans.size()];
        
        for(int i=0; i<ans.size(); i++){
            result[i] = ans.get(i);
        }
        
        return result;
        
    }
}