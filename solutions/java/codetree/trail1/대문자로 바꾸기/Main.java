import java.io.*; 
import java.util.*; 
public class Main {
    public static void main(String[] args) throws Exception{
        // Please write your code here.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[][] arr = new String[5][3]; 

        // 문자 배열 받기 
        for (int i = 0; i < 5; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine().toUpperCase()); 
            for (int j = 0; j < 3; j++) {
                arr[i][j] = st.nextToken(); 
            }
        }


        // 출력 
         for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }
}