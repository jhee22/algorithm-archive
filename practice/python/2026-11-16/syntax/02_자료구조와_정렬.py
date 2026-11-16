"""문법 연습 2: 좌표, 스택과 큐, 집합과 딕셔너리, 정렬

각 함수를 직접 완성하고 이 파일을 실행하세요.
"""


def neighbors(r, c):
    """(행, 열)의 상, 하, 좌, 우 좌표를 이 순서대로 리스트에 담아 반환합니다."""    
    # raise NotImplementedError
    result = [] 
    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1] 

    for i in range(4):
        nr = r + dr[i] 
        nc = c + dc[i] 
        result.append((nr, nc))
    return result 

    
from collections import deque 
def stack_and_queue(numbers):
    """비어 있지 않은 numbers로 스택과 큐를 각각 만들고, 꺼낸 값 (스택, 큐)을 반환합니다.

    스택은 list의 pop, 큐는 collections.deque의 popleft를 사용합니다.
    """
    # raise NotImplementedError
    stack = list(numbers) 
    queue = deque(numbers) 
    return (stack.pop(), queue.popleft())
    

from collections import Counter
def count_words(words):
    """단어별 등장 횟수를 딕셔너리로 반환합니다. 대소문자는 구분합니다."""
    # raise NotImplementedError
    counter = Counter(words) 
    return dict(counter)
    

from collections import defaultdict
def first_duplicate(numbers):
    """왼쪽부터 볼 때 두 번째로 처음 등장하는 숫자를 반환합니다. 없으면 None을 반환합니다."""
    # raise NotImplementedError 

    # 빈 dictionary, 이제 기본 k-v, v의 값이 0으로 셋팅되는 
    counts = defaultdict(int) 
    for number in numbers:
        counts[number] += 1 
        if counts[number] == 2:
            return number 
    return None 



def sort_scores(items):
    """(번호, 점수) 쌍을 점수 내림차순, 점수가 같으면 번호 오름차순으로 정렬해 반환합니다."""
    # raise NotImplementedError
    return sorted(
        items, 
        key=lambda x: (-x[1], x[0])
    )


def test(label, expected, run):
    try:
        actual = run()
        print(f"{label} | 예상: {expected} | 실제: {actual} | {'PASS' if actual == expected else 'FAIL'}")
    except NotImplementedError:
        print(f"{label} | 예상: {expected} | 미구현")
    except Exception as error:
        print(f"{label} | 오류: {type(error).__name__}: {error} | FAIL")


def main():
    test('이웃 (1, 2)', [(0, 2), (2, 2), (1, 1), (1, 3)], lambda: neighbors(1, 2))
    test('스택과 큐 [1, 2, 3]', (3, 1), lambda: stack_and_queue([1, 2, 3]))
    test('빈도 [a, A, a]', {'a': 2, 'A': 1}, lambda: count_words(['a', 'A', 'a']))
    test('빈도 []', {}, lambda: count_words([]))
    test('첫 중복 [1, 2, 2, 1]', 2, lambda: first_duplicate([1, 2, 2, 1]))
    test('첫 중복 없음', None, lambda: first_duplicate([1, 2]))
    test('점수 정렬', [(1, 4), (2, 4), (3, 2)], lambda: sort_scores([(2, 4), (1, 4), (3, 2)]))
    test('빈 점수', [], lambda: sort_scores([]))


if __name__ == '__main__':
    main()
