import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int cnt = 0;
        
        for(int s : scoville) {
            pq.offer(s);
        }
        
        while(pq.size() >= 2 && pq.peek() < K) {
            int a = pq.poll();
            int b = pq.poll();
            
            int mix = a + (b*2);
            pq.offer(mix);
            cnt++;
        }
        
        if(!pq.isEmpty() && pq.peek() >= K) return cnt;
        else return -1;
        
    }
}