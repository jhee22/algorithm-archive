import java.util.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        HashMap<String, Integer> map = new HashMap<>();
        
        for(int i=0; i<genres.length; i++){
            String genre = genres[i];
            map.put(genre, map.getOrDefault(genre, 0) + plays[i]);
        }
        
        List<Integer> songs = new ArrayList<>();
        
        for(int i=0; i<genres.length; i++){
            songs.add(i);
        }
        
        songs.sort((a,b) -> {
            //1, 속한 노래가 많이 재생된 장르
            if(!genres[a].equals(genres[b])){
                return Integer.compare(
                map.get(genres[b]), map.get(genres[a]));
            }
            
            //2. 많이 재생된 노래
            if(plays[a]!=plays[b]){
                return Integer.compare(plays[b], plays[a]);
            }
            
            return Integer.compare(a,b);
        });
        
        
        HashMap<String, Integer> cnt = new HashMap<>();
        List<Integer> ans = new ArrayList<>();
        
        for(int idx : songs){
            String genre = genres[idx];
            
            if(cnt.getOrDefault(genre, 0) < 2){
                ans.add(idx);
                cnt.put(genre, cnt.getOrDefault(genre, 0) + 1);
            }
        }
        
        int[] result = new int[ans.size()];
        
        for(int i=0; i<ans.size(); i++){
            result[i] = ans.get(i);
        }
        
        return result;
    }
}