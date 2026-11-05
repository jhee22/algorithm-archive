import java.io.*; 
import java.util.*; 

public class Main {
    public static void main(String[] args) throws Exception{
        // Please write your code here.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        int[][] arr = new int[3][3]; 
        
        // 첫 입력 배열 
        for (int i = 0; i < 3; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine()); 
            for (int j = 0; j < 3; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken()); 
            }
        }

        // 빈줄 
        br.readLine(); 

        // 두번째 입력 배열 바로 곱하기 
          for (int i = 0; i < 3; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine()); 
            for (int j = 0; j < 3; j++) {
                arr[i][j] *= Integer.parseInt(st.nextToken()); 
                System.out.print(arr[i][j] + " ");
            }
            System.out.println(); 
        }
    }
}