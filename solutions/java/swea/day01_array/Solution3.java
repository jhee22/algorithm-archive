package swea.day01_array;

import java.util.Scanner;

public class Solution3 {
    public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		for(int test_case = 1; test_case <= 10; test_case++)
		{
            // dummy 
            int d = sc.nextInt(); 

            // input 
            // test -> 5 X 5 
            int[][] arr = new int[100][100]; 
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    arr[i][j] = sc.nextInt(); 
                }
            }

            // logic 
            int answer = 0; 
            // start 
            int last = arr[0].length; 
            for (int j = 0; j < arr[0].length; j++) {
                if (arr[0][j] == 1) {
                    // path 
                    int path = j; 

                    // Current State 
                    int curr_i = 0; 
                    int curr_j = j;
                    
                    // Previous State 
                    int prev_i = -1; 
                    int prev_j = -1;

                    // next : 오 - 왼 - 아  
                    // (1) 이동했을 때 배열의 범위 안 
                    // (2) Previous State와 동일하면 안됨 
                    // (3) 1 이어야함 
                    while (curr_i < arr.length - 1) {
                        if (curr_j + 1 < last && !(prev_i == curr_i && prev_j == curr_j + 1) && arr[curr_i][curr_j + 1] >= 1) {
                            // Renew the State  
                            prev_i = curr_i; 
                            prev_j = curr_j; 
                            curr_j = curr_j + 1; 
                    
                        } else if (curr_j - 1 >= 0 && !(prev_i == curr_i && prev_j == curr_j - 1) && arr[curr_i][curr_j - 1] >= 1) {
                            // Renew the State 
                            prev_i = curr_i; 
                            prev_j = curr_j; 
                            curr_j = curr_j - 1; 

                        } else if (curr_i + 1 < last && !(prev_i == curr_i + 1 && prev_j == curr_j) && arr[curr_i + 1][curr_j] >= 1) {
                            // Renew the State 
                            prev_i = curr_i; 
                            prev_j = curr_j; 
                            curr_i = curr_i + 1; 
                        } else {
                            break; 
                        }
                    }
                    if (arr[curr_i][curr_j] == 2) {
                            answer = path; 
                            break; 
                    }
                    
                }
            }

            // output
            System.out.println("#" + test_case + " " + answer);
		}
	}

}
