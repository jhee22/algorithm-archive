import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        PriorityQueue<Integer> min_pq = new PriorityQueue<>();
        PriorityQueue<Integer> max_pq = new PriorityQueue<>(Collections.reverseOrder());
        
        for(String o : operations){
            String[] part = o.split(" ");
            String cmd = part[0];
            int num = Integer.parseInt(part[1]);
            
            if(cmd.equals("I")) {
                max_pq.offer(num);
                min_pq.offer(num);
            }
            else if(cmd.equals("D")) {
                
                if(min_pq.isEmpty()) continue;
                
                if(num == 1){
                    int max = max_pq.poll();
                    min_pq.remove(max);
                } else if(num==-1) {
                    int min = min_pq.poll();
                    max_pq.remove(min);
                }
            }
        }
        
        if(min_pq.isEmpty()) return new int[] {0,0};
        
        return new int[] {max_pq.peek(), min_pq.peek()};
        
    }
}