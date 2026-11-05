import java.util.*;

public class QueueStackHeapPractice {
    // 문제 1: 큐에서 꺼낸 순서 기록하기
    // 입력: 정수 배열 numbers.
    // 할 일: 배열의 숫자를 앞에서부터 모두 큐에 넣은 뒤, 큐가 빌 때까지 꺼내세요.
    // 꺼낸 순서대로 숫자를 리스트에 담아 반환하세요. ArrayDeque를 큐로 사용합니다.
    // 예: [3, 1, 2] -> [3, 1, 2], [] -> []
    static List<Integer> queueOrder(int[] numbers) {
        // TODO: ArrayDeque 큐를 사용하세요.
        Deque<Integer> deque = new ArrayDeque<>();  
        for (int i = 0; i < numbers.length; i++) {
            deque.offer(numbers[i]);
        }
        List<Integer> result = new ArrayList<>(); 
        while (!deque.isEmpty()) {
            result.add(deque.poll());
        }
        return result; 
        // throw new UnsupportedOperationException();
    }

    // 문제 2: 올바른 괄호 문자열인지 확인하기
    // 입력: '('와 ')'로만 이루어진 문자열 text. 빈 문자열도 입력될 수 있습니다.
    // 할 일: 모든 여는 괄호가 올바른 순서로 닫히면 true, 그렇지 않으면 false를 반환하세요.
    // 여는 괄호보다 닫는 괄호가 먼저 나오거나, 짝을 찾지 못한 괄호가 남으면 올바르지 않습니다.
    // 예: "(())" -> true, "()()" -> true, "" -> true
    // 예: ")(" -> false, "(()" -> false, "())" -> false
    // 스택을 사용해 직접 판별하세요.
    static boolean validParentheses(String text) {
        // TODO: 스택을 사용하세요.
        Deque<Character> deque = new ArrayDeque<>(); 
        for (char c : text.toCharArray()) {
            if (c == '(') {
                deque.push(c); 
            }
            else if (!deque.isEmpty() && c == ')') {
                deque.pop(); 
            }
        }

        if (!deque.isEmpty()){
            return false;
        }
        
        return true; 
        // throw new UnsupportedOperationException();

    }

    // 문제 3: 가장 작은 숫자 k개 뽑기
    // 입력: 정수 배열 numbers와 뽑을 개수 k. k는 0 이상이고 배열 길이 이하입니다.
    // 할 일: 숫자 중 가장 작은 것부터 k개를 골라 오름차순 리스트로 반환하세요.
    // 같은 숫자도 각각 하나로 셉니다. PriorityQueue를 사용하세요.
    // 예: numbers=[3, 1, 2, 1], k=3 -> [1, 1, 2]
    // 예: numbers=[4, -1], k=1 -> [-1], numbers=[], k=0 -> []
    // k가 0이면 빈 리스트를 반환하세요.
    static List<Integer> smallestK(int[] numbers, int k) {
        // TODO: PriorityQueue를 사용하세요.
        PriorityQueue<Integer> minHeap = new PriorityQueue<>(); 
        for (int i = 0; i < numbers.length; i++) {
            minHeap.offer(numbers[i]);
        }

        List<Integer> result = new ArrayList<>(); 
        for (int i = 0; i < k; i++) {
            result.add(minHeap.poll());
        }
        return result;
        // throw new UnsupportedOperationException();
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
        test("큐 [3, 1, 2]", Arrays.asList(3, 1, 2), () -> queueOrder(new int[]{3, 1, 2}));
        test("큐 []", Collections.emptyList(), () -> queueOrder(new int[]{}));
        test("괄호 (())", true, () -> validParentheses("(())"));
        test("괄호 )( ", false, () -> validParentheses(")("));
        test("괄호 (()", false, () -> validParentheses("(()"));
        test("괄호 빈 문자열", true, () -> validParentheses(""));
        test("작은 수 [3, 1, 2, 1], k=3", Arrays.asList(1, 1, 2), () -> smallestK(new int[]{3, 1, 2, 1}, 3));
        test("작은 수 [], k=0", Collections.emptyList(), () -> smallestK(new int[]{}, 0));
    }
}
