import java.util.*; 
import java.io.*; 

public class Main {
    public static void main(String[] args) throws Exception{
        // Please write your code here.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        StringTokenizer st = new StringTokenizer(br.readLine()); 

        int n = Integer.parseInt(st.nextToken()); 
        int m = Integer.parseInt(st.nextToken()); 

        int[][] arr = new int[n][m]; 
        int num = 1; // 아핫아핫
        for (int i = 0; i < n; i++) { // n,m으로 안함;;
            for (int j = 0; j < m; j++) {
                arr[i][j] = num++; 
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }    
    }
}