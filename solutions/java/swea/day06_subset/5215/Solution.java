import java.io.*; 
import java.util.*; 

public class Solution {
    
    public static void main(String[] args) throws Exception{ 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        int T = Integer.parseInt(br.readLine()); 
        for (int test_case = 1; test_case  <= T; test_case++) {
            StringTokenizer st = new StringTokenizer(br.readLine()); 
            // 재료의 수 
            int n = Integer.parseInt(st.nextToken()); 
            
            // 제한 칼로리 
            int l = Integer.parseInt(st.nextToken()); 
            
            // 맛에 대한 점수와 칼로리 
            int[] t = new int[n]; 
            int[] k = new int[n]; 
            int max = Integer.MIN_VALUE; 

            // 모든 재료 입력 
            for (int i  = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                
                // 주어진 제한 칼로리 이하의 조합 중에서 가장 맛에 대한 점수가 높은 햄버거 점수 
                t[i] = Integer.parseInt(st.nextToken()); 
                k[i] = Integer.parseInt(st.nextToken()); 
            }

            // 부분집합 순회 
            for (int subset = 0; subset < (1 << n); subset++) {

                int tSum = 0; 
                int kSum = 0; 

                for (int i = 0; i < n; i++) {

                    if ((subset & (1 << i)) != 0) {
                        tSum += t[i]; 
                        kSum += k[i]; 
                    }
                }
    
                // kSum <= l 
                if (kSum <= l) {
                    max = Math.max(tSum, max); 
                }

            }
            System.out.println("#" + test_case + " " + max);
        }
    }
}
