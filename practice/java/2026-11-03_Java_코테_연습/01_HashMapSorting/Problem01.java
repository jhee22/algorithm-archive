import java.util.*;
import java.util.function.Supplier;

/* 관측소 신호 순위
 * 같은 인덱스의 관측소와 신호 세기가 한 건의 관측이다. 관측소 이름을 한 번씩 반환한다.
 * 순위는 총 세기 내림차순, 관측 횟수 오름차순, 이름 사전순이다.
 * 두 배열의 길이는 같고 0~100,000이다. 이름은 영문 소문자 1~10자, 세기는 0~1,000,000,000이다.
 * 예: [b,a,b], [2,4,2] → [a,b]. 총합의 표현 범위와 서로 다른 관측소 수에 따른 정렬 비용을 고려한다.
 */
public class Problem01 {
    public static String[] solution(String[] stations, int[] signal) {
        // TODO: 직접 구현하세요.
        Map<String, Long[]> m = new HashMap<>(); 
        
        // stations, signal 의 인덱스는 동일함 
        for (int i = 0; i < signal.length; i++) {
            String k = stations[i]; 
            int v = signal[i]; 

            Long[] record = m.getOrDefault(k, new Long[]{0L, 0L}); 
            record[0] += v; 
            record[1]++; 
            m.put(k, record); 
            
        }
        // throw new UnsupportedOperationException();
        List<String> names = new ArrayList<>(m.keySet()); 
        
        names.sort((a, b) -> {
            Long[] recordA = m.get(a); 
            Long[] recordB = m.get(b); 

            // 1. 총 신호 세기 
            int result = Long.compare(recordB[0], recordA[0]); 
            if (result != 0) return result; 

            // 2. 관측 횟수 오름차순 
            result = Long.compare(recordA[1], recordB[1]); 
            if (result != 0 ) return result; 

            // 3. 이름 사전순 
            return a.compareTo(b); 
        });
       
        return names.toArray(new String[0]);
    }

    private static void test(int number, String label, String[] expected, Supplier<String[]> run) {
        System.out.print(number + ". " + label + " | 예상=" + Arrays.toString(expected));
        try {
            String[] actual = run.get();
            System.out.println(" | 실제=" + Arrays.toString(actual) + " | " + (Arrays.equals(expected, actual) ? "PASS" : "FAIL"));
        } catch (UnsupportedOperationException e) {
            System.out.println(" | 실제=미구현 | NOT_IMPLEMENTED");
        } catch (RuntimeException e) {
            System.out.println(" | 실제=" + e + " | FAIL");
        }
    }

    public static void main(String[] args) {
        test(1, "동점에서 관측 횟수", new String[]{"a", "b"},
                () -> solution(new String[]{"b","a","b"}, new int[]{2,4,2}));
        test(2, "총합과 이름 순서", new String[]{"m", "a", "z"},
                () -> solution(new String[]{"z","a","m"}, new int[]{3,3,5}));
        test(3, "빈 기록", new String[]{},
                () -> solution(new String[]{}, new int[]{}));
        test(4, "합계 범위", new String[]{"x", "y"},
                () -> solution(new String[]{"x","x","x","y"}, new int[]{1000000000,1000000000,1000000000,9}));
        test(5, "세기 0도 관측", new String[]{"a", "b"},
                () -> solution(new String[]{"b","a","b"}, new int[]{0,0,0}));
    }
}
