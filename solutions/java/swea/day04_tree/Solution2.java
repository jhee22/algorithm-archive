package swea.day04_tree;
import java.io.*; 
import java.util.*; 

public class Solution2 {
    static String[] data; 
    static int[] left; 
    static int[] right; 

    public static int calculate(int node) {
        if (Character.isDigit(data[node].charAt(0))){
            return Integer.parseInt(data[node]); 
        }
        // 연산자 아래 구현? 
        int leftValue = calculate(left[node]); 
        int rightValue = calculate(right[node]); 
        String op = data[node]; 

        if (op.equals("+")) {
            return leftValue + rightValue; 
        }  else if (op.equals("-")) {
            return leftValue - rightValue; 
        } else if (op.equals("*")) {
            return leftValue * rightValue; 
        } else {
            return leftValue / rightValue; 
        } 
       

    }

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        for(int test_case = 1; test_case <= 10; test_case++) {
            // 정점의 개수 N 
            int N = Integer.parseInt(br.readLine()); 
            // input 
            data = new String[N + 1]; 
            left = new int[N + 1]; 
            right = new int[N + 1]; 

            for (int i = 0; i < N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine()); 
                int node = Integer.parseInt(st.nextToken()); 
                data[node] = st.nextToken(); 

                if (st.hasMoreTokens()){
                    left[node] = Integer.parseInt(st.nextToken()); 
                    right[node] = Integer.parseInt(st.nextToken()); 
                }
            }

            int result = calculate(1); 
            System.out.println("#" + test_case + " " + result);
        }
		
    }
    
}
