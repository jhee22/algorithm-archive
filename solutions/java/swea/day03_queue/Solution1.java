package swea.day03_queue;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution1 {
       public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        for(int test_case = 1; test_case <= 10; test_case++) {
            // input 
            int tc  = Integer.parseInt(br.readLine()); 
            StringTokenizer st = new StringTokenizer(br.readLine()); 
            Queue<Integer> queue = new ArrayDeque<>(); 
             
            for (int i = 0; i < 8; i++) {
                queue.add(Integer.parseInt(st.nextToken()));
            }
             
            // logics 
            int cnt = 1; 
            while (!queue.isEmpty() ){
                int first = queue.poll(); 
                int value = first - cnt; 
                 
                //break
                if (value <= 0) {
                    queue.offer(0); 
                    break; 
                } else {
                    queue.offer(value); 
                }
 
                cnt++; 
                if (cnt > 5) cnt = 1; 
                
            }
             
            // output
            System.out.print("#" +  tc + " ");
            for (int elem : queue) {
                System.out.printf("%d ", elem);
            }
            System.out.println();
        }
    }
}
