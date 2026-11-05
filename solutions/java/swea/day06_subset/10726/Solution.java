import java.io.*; 
import java.util.*; 
public class Solution {
    
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        int T = Integer.parseInt(br.readLine()); 
        for (int test_case = 1; test_case <= T; test_case++) {
            // n, m
            StringTokenizer st = new StringTokenizer(br.readLine()); 
            int n = Integer.parseInt(st.nextToken()); 
            int m = Integer.parseInt(st.nextToken()); 

            // 1. 마지막 n 비트가 모두 1인 기준 값 
            int mask = (1 << n) - 1; 

            // 2. m의 마지막 n 비트가 모두 1인지 확인 
            boolean isOn = (m & mask) == mask; 

            // 3. 결과 출력 
            System.out.println("#" + test_case + " " + (isOn? "ON" : "OFF"));
            

        }
    }
}
