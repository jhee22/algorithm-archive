package swea.day02_string;
// 회문 
import java.util.Scanner; 
import java.io.FileInputStream; 
public class Solution1 {
    public static void main(String[] args) throws Exception{
        // dummy 
        Scanner sc = new Scanner(System.in); 
        int d = sc.nextInt(); // 1 
        
        // 10 으로 바꾸기 제출시 
        for(int test_case = 1; test_case <= d; test_case++)
		{
             // Input
        // test : 8 x 8, actual : 100 x 100 matrix
        // 문자 입력 받기  
        char[][] arr = new char[100][100]; 
        for (int i = 0; i < arr.length; i++) {
            String row = sc.next(); 
            for (int j = 0; j < arr[0].length; j++) {
                 arr[i][j] = row.charAt(j); 
            }
        }

        // logics 
        // 각 행, 각 열에서 만들 수 있는 회문의 최대길이를 구하긔~~ 
        int max = Integer.MIN_VALUE; 
        for (int i = 0; i < arr.length; i++) {
            StringBuilder rowSb = new StringBuilder(); 
            StringBuilder colSb = new StringBuilder(); 
            
            for (int j = 0; j < arr[0].length; j++) {
                // 각 행과 열을 순회 
                rowSb.append(arr[i][j]); 
                colSb.append(arr[j][i]); 
            } 

            // 회문 Check 
            // .reverse() 는 StringBuilder Method 
            for (int last = rowSb.length(); last >= 1; last--) {
                for (int start = 0; start <= rowSb.length() - last; start++) {
                    int answer = 0; 
                    String temp = rowSb.substring(start, start + last); 
                    String reverse = new StringBuilder(temp).reverse().toString();
                    if (temp.equals(reverse)) answer = temp.length(); 
                    max = Math.max(max, answer); 
                }
            }

            for (int last = colSb.length(); last >= 1; last--) {
                for (int start = 0; start <= colSb.length() - last; start++) {
                    int answer = 0; 
                    String temp = colSb.substring(start, start + last); 
                    String reverse = new StringBuilder(temp).reverse().toString(); 
                    if (temp.equals(reverse)) answer = temp.length(); 
                    max = Math.max(max, answer);
                }
            }


		}
        System.out.println("#" + d + " " + max);
        }
    }
}
