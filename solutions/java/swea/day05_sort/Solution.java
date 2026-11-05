package swea.day05_sort;

import java.util.*;
import java.io.*;

public class Solution {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        int T = Integer.parseInt(br.readLine()); 
		
        for(int test_case = 1; test_case <= T; test_case++) {
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n]; 
            
            StringTokenizer st = new StringTokenizer(br.readLine()); 
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken()); 
            }

            Arrays.sort(arr); 

            // 출력 부분 stringBuilder 로 하면 더 빠름 
            System.out.print("#" + test_case + " ");
            for (int elem : arr) {
                System.out.print(elem + " ");
            }
            System.out.println();
		}
	}
}
