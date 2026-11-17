"""나누어 떨어지는 숫자 배열 · https://school.programmers.co.kr/learn/courses/30/lessons/12910?language=python3"""


def solution(arr, divisor):
    result = [] 
    for i in range(len(arr)):
        if (arr[i] % divisor == 0):
            result.append(arr[i])
    
    return sorted(result) if len(result) > 0 else [-1]


if __name__ == "__main__":
    # 코치 작성 예제
    actual = solution([6, 5, 2], 2)
    print("실제", actual, "기대", [2, 6], "일치", actual == [2, 6])


if __name__ == "__main__":
    # 공식 공개 예제. 실행할 행의 맨 앞 #을 지우세요.
    cases = [
        # (([5, 9, 7, 10], 5), [5, 10]),
        # (([2, 36, 1, 3], 1), [1, 2, 3, 36]),
        # (([3, 2, 6], 10), [-1]),
    ]
    for args, expected in cases:
        actual = solution(*args)
        print("PASS" if actual == expected else "FAIL", "입력", args, "실제", repr(actual), "기대", repr(expected))
