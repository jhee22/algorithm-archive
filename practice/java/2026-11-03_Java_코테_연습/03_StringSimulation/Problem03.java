import java.util.*;
import java.util.function.Supplier;

/* 교정 테이프의 봉인
 * 빈 테이프에서 시작해 스크립트를 왼쪽부터 읽는다. 소문자는 끝에 기록한다. [ 는 현재 위치에 봉인을 열고,
 * ] 는 가장 안쪽 봉인을 확정한다(기록 유지). ! 는 가장 안쪽 봉인을 취소해 열 때의 길이로 되돌린다.
 * - 는 마지막 글자를 지우되 가장 안쪽 열린 봉인의 시작 위치보다 짧아질 수 없다. 봉인이 없으면 빈 길이가 하한이다.
 * 열린 봉인 없이 ] 또는 ! 를 만나면 즉시 "ERROR"를 반환한다. 끝까지 열려 있는 봉인은 모두 취소한 뒤 최종 문자열을 반환한다.
 * 길이 0~200,000, 입력 문자는 소문자 또는 네 기호 [, ], !, - 중 하나만 주어진다.
 * 예: a[b[c]! → a. 깊은 중첩에서 전체 문자열을 반복 복사할 때의 시간과 공간을 고려한다.
 */
public class Problem03 {
    public static String solution(String script) {
        // TODO: 직접 구현하세요.
        throw new UnsupportedOperationException();
    }

    private static void test(int number, String label, String expected, Supplier<String> run) {
        System.out.print(number + ". " + label + " | 예상=" + expected);
        try {
            String actual = run.get();
            System.out.println(" | 실제=" + actual + " | " + (expected.equals(actual) ? "PASS" : "FAIL"));
        } catch (UnsupportedOperationException e) {
            System.out.println(" | 실제=미구현 | NOT_IMPLEMENTED");
        } catch (RuntimeException e) {
            System.out.println(" | 실제=" + e + " | FAIL");
        }
    }

    public static void main(String[] args) {
        test(1, "내부 확정 후 외부 취소", "a",
                () -> solution("a[b[c]!"));
        test(2, "삭제 하한과 확정", "ab",
                () -> solution("ab[-c]-"));
        test(3, "미확정 봉인 정리", "x",
                () -> solution("x[y[z"));
        test(4, "첫 명령이 잘못됨", "ERROR",
                () -> solution("]a["));
        test(5, "빈 테이프", "",
                () -> solution(""));
        test(6, "빈 삭제와 취소 후 계속", "ac",
                () -> solution("--a[b!c"));
    }
}
