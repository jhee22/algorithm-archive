import java.util.*; 
class Solution {
    public boolean solution(String[] phone_book) {
        // 접두사를 빨리 찾기 위해 HashSet 을 이용하자 
        HashSet <String> set = new HashSet<>(); 
        for (String phone : phone_book) {
            set.add(phone); 
        }
        
        for (String phone : phone_book) {
            for (int i = 1; i < phone.length(); i++) {
                String prefix = phone.substring(0, i); 
                if (set.contains(prefix)) {
                    return false;
                }
            }
            
        }
        return true;
        
//         // 제일 짧은 전화번호를 접두사로 생각 
//         // 제일 짧은 문자 하나만 접두사로 생각하면 안됨 
//         int min = Integer.MAX_VALUE; 
//         int idx = 0; 
//         for (int i = 0; i < phone_book.length; i++) {
//             if (phone_book[i].length() < min){ 
//                 min = phone_book[i].length(); 
//                 idx = i; 
//             }
            
//         }
        
//         // 찾기  
//         String prefix = phone_book[idx]; 
//         for (String p : phone_book) {
//             if (p.startsWith(prefix) && !(p.equals(prefix))){
//                 return false; 
//             }
//         }
        
//         return true; 
        
    }
}