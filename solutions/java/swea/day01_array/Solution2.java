package swea.day01_array;
import java.util.Scanner;
import java.io.FileInputStream;
public class Solution2 {
    	public static void main(String args[]) throws Exception
	    {
            Scanner sc = new Scanner(System.in);
		   for(int test_case = 1; test_case <= 10; test_case++)
		    {
                // dummy 
                int tc = sc.nextInt();  
                
                // 이차원 배열  
                int[][] arr = new int[100][100]; 
                for (int i = 0; i < 100; i++) {
                    for (int j = 0; j < 100; j++) {
                        arr[i][j] = sc.nextInt(); 
                    }
                }
                
                // 각 행의 합, 각 열의 합 : 동시에 구할 수 있음
                int max = 0;  
                for (int i = 0; i < arr.length; i++) {
                    int rowSum = 0;
                    int colSum = 0; 
    
                    for (int j = 0; j < arr[0].length; j++) {
                        rowSum += arr[i][j]; 
                        colSum += arr[j][i];  

                        max = Math.max(colSum, max); 
                    }
                    max = Math.max(rowSum, max); 
                }

                // 정방향 대각선의 합 : 규칙이 명확하기 때문에 이중 반복할 필요 X 
                int crossSum = 0; 
                for (int i = 0; i < arr.length; i++) {
                    crossSum += arr[i][i]; 
                }
                max = Math.max(max, crossSum); 

                // 역방향 대각선의 합 : 규칙이 명확하기 때문에 이중 반복할 필요 X 
                int oppCrossSum = 0; 
                int n = arr.length; 
                for (int j = 0; j < arr.length; j++) {
                    oppCrossSum += arr[n-1-j][j]; 
                }
                max = Math.max(max, oppCrossSum);  
                System.out.println("#" + test_case + " " + max);
            
            }
        }
}
