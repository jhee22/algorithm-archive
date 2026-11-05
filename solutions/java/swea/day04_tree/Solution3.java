package swea.day04_tree;
import java.io.*; 
import java.util.*; 

public class Solution3 {
    static String[] tree; 
    static int N; 

    static void inorder(int node) {
        
        if (node > N) {
            return; 
        }

        inorder(node * 2); 
        System.out.print(tree[node]);
        inorder(node * 2 + 1);
    }
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        for(int test_case = 1; test_case <= 10; test_case++) {
            N = Integer.parseInt(br.readLine());
            tree = new String[N + 1]; 

            for (int i = 0; i < N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine()); 
                int node = Integer.parseInt(st.nextToken()); 
                String val = st.nextToken(); 

                tree[node] = val; 
            }
            System.out.println("#" + test_case + " ");
            inorder(1);
            System.out.println();
		}
    }
    
}
