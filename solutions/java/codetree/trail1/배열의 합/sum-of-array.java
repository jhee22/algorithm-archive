import java.io.*; 
import java.util.*; 
public class Main {
    public static void main(String[] args) throws Exception{
        // Please write your code here.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        for (int i = 0; i < 4; i++) {
            int total = 0; 
            StringTokenizer st = new StringTokenizer(br.readLine()); 
            for (int j = 0; j < 4; j++) {
                total += Integer.parseInt(st.nextToken()); 
            }
            System.out.println(total); 
        
        
        }

    }
}