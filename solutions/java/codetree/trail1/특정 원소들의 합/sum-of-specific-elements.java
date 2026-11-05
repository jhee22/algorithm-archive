import java.io.*; 
import java.util.*; 

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        int[][] arr = new int[4][4]; 
        int result = 0;
        
        for (int i = 0; i < 4; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine()); 
            for (int j = 0; j < 4; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken()); 
                if (j <= i) {
                    result += arr[i][j]; 
                }
            }
        }
         
       

       

        System.out.println(result);


    }
}