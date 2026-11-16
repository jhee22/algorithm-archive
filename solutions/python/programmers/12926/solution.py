"""시저 암호 · https://school.programmers.co.kr/learn/courses/30/lessons/12926?language=python3"""

# print(ord('z')) 122 
# print(ord('Z')) 90
def solution(s, n):
    result = [] 
    for i in range(len(s)):
        # 대문자 처리 
        if s[i].isupper() and ord(s[i]) + n > 90:
            result.append(chr(ord(s[i]) - 26 + n))
        # 소문자 처리 
        elif s[i].islower() and ord(s[i]) + n > 122:
            result.append(chr(ord(s[i]) - 26 + n))
        # 공백 처리 
        elif s[i].isspace():
            result.append(s[i])
        else:
            result.append(chr(ord(s[i]) + n))
        
    return  ''.join(result)


if __name__ == "__main__":
    # 코치 작성 예제
    actual = solution('Y z', 2)
    print("실제", actual, "기대", 'A b', "일치", actual == 'A b')


if __name__ == "__main__":
    # 공식 공개 예제. 실행할 행의 맨 앞 #을 지우세요.
    cases = [
        # (('AB', 1), 'BC'),
        # (('z', 1), 'a'),
        # (('a B z', 4), 'e F d'),
    ]
    for args, expected in cases:
        actual = solution(*args)
        print("PASS" if actual == expected else "FAIL", "입력", args, "실제", repr(actual), "기대", repr(expected))
