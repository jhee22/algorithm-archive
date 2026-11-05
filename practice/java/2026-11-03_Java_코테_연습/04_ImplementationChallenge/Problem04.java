import java.util.*;
import java.util.function.Supplier;

/* 연속 항차 감사 구간
 * 항차 기록 중 연속한 비어 있지 않은 구간 하나를 감사한다. 구간 비용 합은 budget 이하이고
 * 같은 항구는 구간 안에서 각각 limit번까지 등장할 수 있다. 가장 긴 유효 구간의 양 끝 인덱스(0부터, 양 끝 포함)를 반환한다.
 * 길이가 같으면 시작이 가장 이른 구간을 선택한다. 후보가 없으면 [-1,-1]이다.
 * port와 cost 길이는 같고 0~200,000이다. 항구 이름은 소문자 1~10자, 비용은 0~1,000,000,000,
 * budget은 0~200,000,000,000,000, limit는 1~200,000이다.
 * 예: 항구 [a,b,a,c], 비용 [2,1,1,1], 예산 3, 제한 1 → [1,3]. 모든 구간을 열거할 때의 비용과 누적값 범위를 고려한다.
 */
public class Problem04 {
    public static int[] solution(String[] port, int[] cost, long budget, int limit) {
        // TODO: 직접 구현하세요.
        throw new UnsupportedOperationException();
    }

    private static void test(int number, String label, int[] expected, Supplier<int[]> run) {
        System.out.print(number + ". " + label + " | 예상=" + Arrays.toString(expected));
        try {
            int[] actual = run.get();
            System.out.println(" | 실제=" + Arrays.toString(actual) + " | " + (Arrays.equals(expected, actual) ? "PASS" : "FAIL"));
        } catch (UnsupportedOperationException e) {
            System.out.println(" | 실제=미구현 | NOT_IMPLEMENTED");
        } catch (RuntimeException e) {
            System.out.println(" | 실제=" + e + " | FAIL");
        }
    }

    public static void main(String[] args) {
        test(1, "두 제한의 상호작용", new int[]{1, 3},
                () -> solution(new String[]{"a","b","a","c"}, new int[]{2,1,1,1}, 3L, 1));
        test(2, "무료 항차와 동률", new int[]{0, 1},
                () -> solution(new String[]{"a","b","a","b"}, new int[]{0,0,0,0}, 0L, 1));
        test(3, "후보 없음", new int[]{-1, -1},
                () -> solution(new String[]{"a","b"}, new int[]{2,3}, 1L, 2));
        test(4, "빈 기록", new int[]{-1, -1},
                () -> solution(new String[]{}, new int[]{}, 0L, 1));
        test(5, "큰 예산", new int[]{0, 2},
                () -> solution(new String[]{"a","a","b"}, new int[]{1000000000,1000000000,1000000000}, 3000000000L, 2));
        test(6, "여러 항차를 제외해야 하는 경우", new int[]{2, 4},
                () -> solution(new String[]{"a","b","c","d","a"}, new int[]{1,2,4,0,0}, 4L, 1));
    }
}
