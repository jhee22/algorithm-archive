package swea.day02_stack;
import java.util.*; 

import java.io.FileInputStream;
public class Solution1 {
    public static void main(String args[]) throws Exception
	{
        Scanner sc = new Scanner(System.in);
        for(int test_case = 1; test_case <= 10; test_case++)
		{
            // answer, stack 
            int answer = 1;  
            Deque<Character> stack = new ArrayDeque<>(); 

            // Input 
            int t = sc.nextInt(); 
            
            // 문자 입력 받는거 좀 외워라 
            // stack.peek() 확인 필요 
            String s = sc.next(); 
            for (int i = 0; i < t; i++) {
                char c = s.charAt(i);
                if (c == '(' || c == '[' || c == '{' || c == '<') {
                    stack.push(c);
                } else if (!(stack.isEmpty())) {
                    if (
                        (stack.peek() == '(' && c == ')') || 
                        (stack.peek() == '[' && c == ']') || 
                        (stack.peek() =='{' && c == '}')  || 
                        (stack.peek() == '<' && c == '>')
                        ){
                        stack.pop();
                    } else {
                        answer = 0; 
                    }
                } else {
                    answer = 0; 
                }    
            }  

            // output 
            System.out.println("#" + test_case + " " +answer);
    
        }
    }
}
