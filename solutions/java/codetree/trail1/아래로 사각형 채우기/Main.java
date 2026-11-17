// import 
import java.io.*; 
import java.util.*; 

public class Main {
    public static void main(String[] args) throws Exception{
        // Please write your code here.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        int n = Integer.parseInt(br.readLine());

        int[][] arr = new int[n][n]; 

        for (int i = 0; i < n; i++) {
            // 정석 
            int num = i + 1; 
            for (int j = 0; j < n; j++) {
                arr[i][j] = num; 
                System.out.print(arr[i][j] + " "); 
                num += n; 
            }
            System.out.println(); 
        } 
    }
}