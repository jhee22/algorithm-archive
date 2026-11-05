package swea.day01_array;
import java.util.Scanner;
import java.io.FileInputStream;
public class Solution1 {
    public static void main(String args[]) throws Exception{
        Scanner sc = new Scanner(System.in);
        int T;
		T=sc.nextInt();
        	for(int test_case = 1; test_case <= T; test_case++){
                // 2 차원 배열 받기  
                int n = sc.nextInt(); 
                int m = sc.nextInt(); 

                int[][] matrix = new int[n][n]; 
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        matrix[i][j] = sc.nextInt(); 
                    }
                }

                // 파리 찾기 
                int max = Integer.MIN_VALUE;
                // 마지막 시작 위치 : n - m 
                for (int r = 0; r <= n-m; r ++) {
                    for (int c = 0; c <= n-m; c++) {
                        int sum = 0; 
                        // i, j 가 어디서부터 시작해야하는지를 잘 생각해보자 
                        for (int i = r; i < r + m; i++) {
                            for (int j = c; j < c + m; j++) {
                                sum += matrix[i][j]; 
                            }
                        }
                        if (max < sum) {
                            max = sum; 
                        }

                    }
                }
                System.out.println("#" + test_case + " " + max);
		    }

    }
}
