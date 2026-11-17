import java.util.*; 
class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        // HashMap 선언 
        HashMap <String, Integer> partMap = new HashMap<>(); 
        
        // put(k,v)
        for (int i = 0; i < participant.length; i++) {
            partMap.put(participant[i], partMap.getOrDefault(participant[i], 0)+1);
        }
        
        for (int i = 0; i < completion.length; i++) {
            partMap.put(completion[i], partMap.getOrDefault(completion[i], 0)-1); 
        }
        
        // 이거 처음봄 
        for (Map.Entry<String, Integer> entry : partMap.entrySet()) {
            if (entry.getValue() > 0) {
                answer = entry.getKey(); 
                break; 
            }
        }
        
            
    
        
        return answer;
    }
}