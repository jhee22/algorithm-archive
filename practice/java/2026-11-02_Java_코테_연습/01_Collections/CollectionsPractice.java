import java.util.*;

public class CollectionsPractice {
    // 문제 1: 짝수만 모으기
    // 입력: 정수 배열 numbers. 음수와 0, 중복된 수가 들어올 수 있습니다.
    // 할 일: 배열에서 짝수만 골라 입력에 나온 순서대로 리스트에 담아 반환하세요.
    // 예: [3, 2, -4, 0] -> [2, -4, 0], [2, 2, 1] -> [2, 2]
    // 빈 배열이거나 짝수가 없으면 빈 리스트를 반환하세요.
    static List<Integer> evens(int[] numbers) {
        // TODO: 직접 작성하세요.
        List<Integer> result = new ArrayList<>(); 
        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i] % 2 == 0){
                result.add(numbers[i]);
            }
        }
        // throw new UnsupportedOperationException();
        return result; 
    }

    // 문제 2: 단어별 등장 횟수 세기
    // 입력: 문자열 배열 words.
    // 할 일: 각 단어가 몇 번 나왔는지 세어 단어를 key, 횟수를 value로 하는 Map을 반환하세요.
    // 대문자와 소문자는 다른 단어입니다. Map의 출력 순서는 상관없습니다.
    // 예: ["a", "A", "a"] -> {"a": 2, "A": 1}
    // 빈 배열이면 빈 Map을 반환하세요.
    static Map<String, Integer> counts(String[] words) {
        // TODO: 직접 작성하세요.
        Map<String, Integer> map = new HashMap<>();
        for (String w : words) {
            map.put(w, map.getOrDefault(w, 0) + 1); 
        }
        // throw new UnsupportedOperationException();
        return map;
        
    }

    // 문제 3: 가장 먼저 다시 나온 숫자 찾기
    // 입력: 정수 배열 numbers.
    // 할 일: 왼쪽부터 확인할 때, 이미 한 번 나왔던 숫자가 처음 다시 나오면 그 숫자를 반환하세요.
    // 예: [1, 2, 2, 1] -> 2 (1보다 2가 두 번째로 먼저 나옴)
    // 예: [4, 5, 4, 5] -> 4, [1, 2] -> null, [] -> null
    // 중복이 없으면 null을 반환하므로 반환 자료형이 int가 아닌 Integer입니다.
    static Integer firstDuplicate(int[] numbers) {
        // TODO: 직접 작성하세요.
        Set<Integer> set = new HashSet<>(); 
        for (int num : numbers) {
            if (set.contains(num)) {
                return num; 
            } else {
                set.add(num);
            }
        }
        // throw new UnsupportedOperationException();
        return null;
        
    }

    interface Check { Object run(); }
    static void test(String input, Object expected, Check check) {
        System.out.println("입력: " + input + " | 예상: " + expected);
        try {
            Object actual = check.run();
            System.out.println("실제: " + actual + " -> " + (Objects.equals(expected, actual) ? "통과" : "실패"));
        } catch (UnsupportedOperationException e) {
            System.out.println("실제: 미구현");
        } catch (Exception e) {
            System.out.println("실제: 예외 " + e);
        }
    }
    public static void main(String[] args) {
        test("짝수 [3, 2, -4, 0]", Arrays.asList(2, -4, 0), () -> evens(new int[]{3, 2, -4, 0}));
        test("짝수 []", Collections.emptyList(), () -> evens(new int[]{}));
        Map<String, Integer> expected = new HashMap<>();
        expected.put("a", 2); expected.put("A", 1);
        test("빈도 [a, A, a]", expected, () -> counts(new String[]{"a", "A", "a"}));
        test("빈도 []", Collections.emptyMap(), () -> counts(new String[]{}));
        test("중복 [1, 2, 2, 1]", 2, () -> firstDuplicate(new int[]{1, 2, 2, 1}));
        test("중복 [1, 2]", null, () -> firstDuplicate(new int[]{1, 2}));
        test("중복 []", null, () -> firstDuplicate(new int[]{}));
    }
}
