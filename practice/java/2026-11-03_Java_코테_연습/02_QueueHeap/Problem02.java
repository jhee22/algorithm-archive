import java.util.*;
import java.util.function.Supplier;

/* 교정실의 빈 슬롯
 * 요청 번호는 배열 인덱스다. 각 슬롯 시각에 도착 시각이 그 이하인 미처리 요청 중 하나를 처리한다.
 * 긴급도가 큰 요청이 우선이며 동률이면 번호가 작은 요청이 우선이다. 슬롯마다 처리 번호 또는 유휴 표시 -1을 반환한다.
 * arrival과 urgency는 같은 길이이며 arrival은 비내림차순이다. slots도 비내림차순이며 같은 시각 슬롯은 순서대로 각각 처리한다.
 * 각 배열 길이 0~100,000, 모든 값 0~1,000,000,000. 예: 도착 [1,2], 긴급도 [1,9], 슬롯 [0,2] → [-1,1].
 * 슬롯마다 모든 요청을 다시 검사할 때의 시간과 대기 요청을 보관하는 공간을 고려한다.
 */
public class Problem02 {
    public static int[] solution(int[] arrival, int[] urgency, int[] slots) {
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
        test(1, "대기 중 우선순위", new int[]{-1, 1},
                () -> solution(new int[]{1,2}, new int[]{1,9}, new int[]{0,2}));
        test(2, "동시 도착·동시 슬롯", new int[]{0, 1, -1},
                () -> solution(new int[]{2,2}, new int[]{3,3}, new int[]{2,2,2}));
        test(3, "빈 요청", new int[]{-1},
                () -> solution(new int[]{}, new int[]{}, new int[]{0}));
        test(4, "빈 슬롯", new int[]{},
                () -> solution(new int[]{0}, new int[]{9}, new int[]{}));
        test(5, "대기 요청 이월", new int[]{0, 2, 1},
                () -> solution(new int[]{0,1,4}, new int[]{2,2,9}, new int[]{1,4,5}));
    }
}
