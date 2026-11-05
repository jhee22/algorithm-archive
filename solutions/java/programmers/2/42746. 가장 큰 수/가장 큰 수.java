/*
정수를 이어 붙여 만들 수 있는 가장 큰 수 알아내기
배열 numbers가 주어질 때 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 return

1. 맨 앞자리 숫자가 큰거 (두 숫자를 이어붙였을 때 더 큰거 선택해야 함)

*/

import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String[] arr = new String[numbers.length];
        
        for(int i=0; i<numbers.length; i++){
            arr[i] = String.valueOf(numbers[i]);
        }
        
        Arrays.sort(arr, (a,b) -> (b+a).compareTo(a+b));
        
        if(arr[0].equals("0")) return "0";
        
        StringBuilder sb = new StringBuilder();
        
        for(String a : arr){
            sb.append(a);
        }
        
        return sb.toString();
    }
}