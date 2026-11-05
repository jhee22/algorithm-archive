package swea.day02_stack;
import java.util.*; 

public class Solution2 {
    public static void main(String args[]) throws Exception{
		Scanner sc = new Scanner(System.in);
		int T=sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++){
			// input, stack  
            int loop = sc.nextInt(); 
            Deque<Integer> stack = new ArrayDeque<>(); 

            for (int i = 0; i < loop; i++) {
                int num = sc.nextInt(); 
                if (num != 0) {
                    stack.push(num); 
                } else if (!(stack.isEmpty())) {
                    stack.pop(); 
                }
            }

            int total = 0; 
            while(!stack.isEmpty()) {
                total += stack.pop(); 
            }
            System.out.println("#" + test_case + " " + total);
        }
    }
}