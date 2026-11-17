import java.io.*; 
import java.util.*; 

public class Main {
    public static void main(String[] args) throws Exception{
        // Please write your code here.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        StringTokenizer st = new StringTokenizer(br.readLine()); 

        // n,m 
        int n = Integer.parseInt(st.nextToken());  
        int m = Integer.parseInt(st.nextToken()); 

        // 첫 번째 배열 입력 
        int[][] arr = new int[n][m]; 
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine()); 
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken()); 
            }
        }
        // check 
        // System.out.println(Arrays.deepToString(arr));

        // 두 번째 배열 입력 
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine()); 
            for (int j = 0; j < m; j++) {
                int num  = Integer.parseInt(st.nextToken()); 
                if (num == arr[i][j]) {
                    arr[i][j] = 0; 
                } else {
                    arr[i][j] = 1; 
                }
                System.out.print(arr[i][j] + " ");
            }
            System.out.println(); 
        }
    }
}