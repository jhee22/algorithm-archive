import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        Queue<Integer> q = new LinkedList<>();
        
        for(int i=0; i<priorities.length; i++){
            q.offer(i);
        }
        
        int cnt = 0;
        
        while(!q.isEmpty()){
            int idx = q.poll();
            
            boolean higher = false;
            
            for(int i=0; i<priorities.length; i++){
                if (priorities[i] > priorities[idx]) {
                    higher = true;
                    break;
                }
            }
            
            if(higher) {
                q.offer(idx);
            } else {
                cnt++;
                priorities[idx] = 0;
                
                if(idx == location) return cnt;
            }
            
        }
        return cnt;
    }
}