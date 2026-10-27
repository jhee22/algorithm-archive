import java.util.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        HashMap<String, Integer> map = new HashMap<>();
        
        //plays 합산한거 구하기
        for(int i=0; i<genres.length; i++){
            String genre=genres[i];
            
            map.put(genre, map.getOrDefault(genre, 0) + plays[i]);
        }
        
        List<Integer> songs = new ArrayList<>();
        
        for(int i=0; i<genres.length; i++){
            songs.add(i);
        }
        
        //노래 번호를 정렬해보기
        songs.sort((a,b) -> {
            if(!genres[a].equals(genres[b])){
                return Integer.compare(map.get(genres[b]), map.get(genres[a]));
            }
            
            if(plays[a] != plays[b]) {
                return Integer.compare(plays[b], plays[a]);
            }
            
            return Integer.compare(a,b);
        });
        
        //장르별로 2곡 선택
        HashMap<String, Integer> cnt = new HashMap<>(); //장르별로 현재 몇곡을 선택했는지
        List<Integer> ans = new ArrayList<>(); //실제로 베스트 앨범에 수록할 노래 고유 번호 저장
        
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