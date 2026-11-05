package swea.day03_linkedList;
import java.util.*;
import java.io.*;
public class Solution1 {
    public static void main(String args[]) throws Exception{
        // BufferedReader 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
         
        for(int test_case = 1; test_case <= 10; test_case++) {
            // input 
            LinkedList <Integer> list = new LinkedList<>(); 
            // StringTokenizer : 특정 한 줄에 붙어 있는 토큰 꺼내기 도구   
            // 새로운 br.readLine()에서 여러 값을 꺼내야 할 때 새로 만든다.
            int n = Integer.parseInt(br.readLine()); 
            StringTokenizer st = new StringTokenizer(br.readLine());     
            for (int i = 0; i < n; i++) {
                list.add(Integer.parseInt(st.nextToken())); 
            }

            int m = Integer.parseInt(br.readLine()); 
            StringTokenizer st2 = new StringTokenizer(br.readLine()); 
            
            for (int i = 0; i < m; i++) {
                String command = st2.nextToken(); // I 
                int x = Integer.parseInt(st2.nextToken()); 
                int y = Integer.parseInt(st2.nextToken()); 

                for (int j = 0; j < y; j++) {
                    int value = Integer.parseInt(st2.nextToken());
                    list.add(x+j, value); 
                }   
            }
            
            // output 
            System.out.print("#" + test_case + " ");
            for (int i = 0; i < 10; i++) {
                System.out.print(list.get(i) + " "); 
            }
            System.out.println();
	    }
    }
}
