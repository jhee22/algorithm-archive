/*
초 단위로 기록된 주식가격 prices
가격이 떨어지지 않은 기간이 몇 초인지 return

*/

class Solution {
    public int[] solution(int[] prices) {
        int[] time = new int[prices.length];
        
        for(int i=0; i<prices.length; i++){
            int cnt=0;
            for(int j=i+1; j<prices.length; j++){
                cnt++;
                if (prices[i] > prices[j]) break;
        }
            time[i] = cnt;
           
    }
        return time;
}}