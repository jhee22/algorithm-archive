/*
I 숫자 : 큐에 주어진 숫자 삽입
D 1 : 큐에서 최댓값 삭제
D -1 큐에서 최솟값 삭제 

모든 연산 처리한 후 큐 비어있으면 [0,0] 반환, 
비어있지 않으면 [최댓값, 최솟값] 반환
*/

import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        PriorityQueue<Integer> minPq = new PriorityQueue<>();
        
        PriorityQueue<Integer> maxPq = new PriorityQueue<>(Collections.reverseOrder());
        
        for(String operation : operations) {
            String[] parts = operation.split(" ");
            String cmd = parts[0];
            int num = Integer.parseInt(parts[1]);
            
            if(cmd.equals("I")) {
                minPq.offer(num);
                maxPq.offer(num);
            } else if (cmd.equals("D")){
                if(minPq.isEmpty()) continue;
                if(num==1) {
                    int max = maxPq.poll();
                    minPq.remove(max);
                } else if(num == -1){
                    int min = minPq.poll();
                    maxPq.remove(min);
                }
            }
        }
        
        if(minPq.isEmpty()) return new int[]{0,0};
        return new int[] {maxPq.peek(), minPq.peek()};
    }
}