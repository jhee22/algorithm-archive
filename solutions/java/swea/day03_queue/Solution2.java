package swea.day03_queue;
import java.util.*;
import java.io.*;
public class Solution2 {
    public static void main(String args[]) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        int T = Integer.parseInt(br.readLine());  
        for(int test_case = 1; test_case <= T; test_case++) {
            // input 
            int cnt = Integer.parseInt(br.readLine()); 
            StringTokenizer st = new StringTokenizer(br.readLine()); 
            Deque<String> front_queue = new ArrayDeque<>(); 
            Deque<String> back_queue = new ArrayDeque<>(); 
            for (int i = 0; i < cnt; i++) {
                if (i < (cnt + 1) / 2 ) {
                    front_queue.add(st.nextToken()); 
                } else {
                    back_queue.add(st.nextToken()); 
                }
            }

            // logics + output 
            System.out.print("#" + test_case + " "); 
            while (!front_queue.isEmpty() && !back_queue.isEmpty()) {
                System.out.print(front_queue.poll() + " "); 
                System.out.print(back_queue.poll() + " ");
            }
            if (!front_queue.isEmpty()){
                System.out.print(front_queue.poll() + " "); 
            }
            System.out.println();            
        }
    }
}
