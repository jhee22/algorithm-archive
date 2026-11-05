package swea.day02_stack;
// import 
import java.io.*; 
import java.util.*; 

public class Solution3 {
    	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        int T = Integer.parseInt(br.readLine()); 
        
        for(int test_case = 1; test_case <= T; test_case++) {
			// input 
            String s = br.readLine(); 
            Deque <Character> stack = new ArrayDeque<>(); 
            int answer = 0; 
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i); 

                // logic
                // (1) '(' 을 만나면 얘가 몽둥이인지 레인저인지 현재 시점에서는 알 수 없음 
                if (c == '(') {
                    stack.push(c); 
                } else if ( c == ')') {
                    // 직전의 문자열이 '(' 이면 이 경우에는 '()' 레이저임! 
                    if (!stack.isEmpty() && s.charAt(i - 1) == '(') {
                        stack.pop(); 
                        answer += stack.size(); 
               
                    // '))'
                    } else if (!stack.isEmpty() && s.charAt(i - 1) == ')') {
                        stack.pop(); 
                        answer++; 
                    }
                } 
            }  
            System.out.println("#" + test_case + " " + answer);
		}
	}
}
