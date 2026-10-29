/*
모든 음식의 스코빌 지수 >= k
섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
-> 모든 음식의 스코빌 지수가 k 이상이 될 때까지 반복해서 섞기 
*/

import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int s : scoville){
            pq.offer(s);
        }
        
        int cnt = 0;
        
        while (pq.peek() < K){
            
            if(pq.size() < 2) return -1;
            
            int a = pq.poll();
            int b = pq.poll();
            int mixed = a + (b*2);
            pq.offer(mixed);
            cnt++;
        }
        return cnt;
        
    }
}