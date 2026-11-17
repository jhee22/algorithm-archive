"""문법 연습 3: 재귀 반환값과 nonlocal

두 함수를 직접 완성하고 이 파일을 실행하세요.
각 단계에서 두 갈래로 나뉘는 재귀의 마지막 지점 수를 세어 봅니다.
"""


def count_with_return(n):
    """깊이 n에서 마지막 지점의 수를 재귀 반환값을 합쳐 구합니다. n은 0 이상의 정수입니다.

    깊이 0이면 마지막 지점이 하나입니다. 그 외에는 n-1로 두 번 재귀 호출합니다.
    """
    # raise NotImplementedError
    if n == 0:
        return 1
    return count_with_return(n - 1) + count_with_return(n - 1)
    


def count_with_nonlocal(n):
    """마지막 지점의 수를 내부 재귀 함수와 nonlocal 변수로 셉니다."""
    # raise NotImplementedError
    count = 0 
    def dfs(n):
        # outer 에 있는 count 변수를 사용할 때 'nonlocal' 키워드 사용 
        nonlocal count 
        if n == 0:
            count += 1 # 마지막 지점에 도착할 때마다 증가  
            return     # 이번  dfs 종료  

        # 첫 번째 갈래 
        dfs(n - 1)

        # 두 번째 갈래 
        dfs(n - 1) 

    dfs(n)
    return count 


def test(label, expected, run):
    try:
        actual = run()
        print(f"{label} | 예상: {expected} | 실제: {actual} | {'PASS' if actual == expected else 'FAIL'}")
    except NotImplementedError:
        print(f"{label} | 예상: {expected} | 미구현")
    except Exception as error:
        print(f"{label} | 오류: {type(error).__name__}: {error} | FAIL")


def main():
    test('return 깊이 0', 1, lambda: count_with_return(0))
    test('return 깊이 3', 8, lambda: count_with_return(3))
    test('nonlocal 깊이 0', 1, lambda: count_with_nonlocal(0))
    test('nonlocal 깊이 3', 8, lambda: count_with_nonlocal(3))
    test('nonlocal은 호출마다 초기화', (2, 2), lambda: (count_with_nonlocal(1), count_with_nonlocal(1)))


if __name__ == '__main__':
    main()
