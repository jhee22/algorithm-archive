import java.io.*; 
import java.util.*; 

// Arrays.strem(arr).sum()
public class Main {
    public static void main(String[] args) throws Exception{
        // Please write your code here.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        int[][] arr = new int[2][4]; 
        double totalAvg = 0.0; 
        
        // 가로 평균 
        for (int i = 0; i < 2; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine()); 
            double widthAvg = 0.0; 
            
            for (int j = 0; j < 4; j++){
                arr[i][j] = Integer.parseInt(st.nextToken()); 
                widthAvg += arr[i][j]; 
            }
            widthAvg /= 4; 
            System.out.printf("%.1f ", widthAvg); 
            
        }
        System.out.println();

        // 세로 평균 
        // 이미 있는 배열을 다시 받을 필요가 없음 (잘못생각)
        for (int i = 0; i < 4; i++) {
            double heightAvg = 0.0; 
                
            for (int j = 0; j < 2; j++){
                heightAvg += arr[j][i]; 
                totalAvg += arr[j][i]; 
            }
            heightAvg /=2; 
            System.out.printf("%.1f ", heightAvg); 
            
        }
        System.out.println();
        totalAvg /= 8; 
        System.out.printf("%.1f", totalAvg); 



        
            
    
    }
}