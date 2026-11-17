"""문법 연습 1: 리스트 참조와 복사

각 함수를 직접 완성하고 이 파일을 실행하세요.
힌트: 2차원 리스트의 각 행과 저장할 경로가 독립적인지 확인하세요.
"""


def make_grid(rows, cols):
    """rows x cols 크기의 0으로 채운 리스트를 반환합니다. 각 행은 독립적이어야 합니다."""
    
    # raise NotImplementedError
    return [[0 for _ in range(cols)] for _ in range(rows)]


def save_path(path, next_value):
    """path를 복사해 저장한 후 원래 path에 next_value를 추가하고 (저장한 복사본, path)를 반환합니다."""
    # raise NotImplementedError
    copy = path.copy() 
    path.append(next_value)
    return (copy, path)


def test(label, expected, run):
    try:
        actual = run()
        print(f"{label} | 예상: {expected} | 실제: {actual} | {'PASS' if actual == expected else 'FAIL'}")
    except NotImplementedError:
        print(f"{label} | 예상: {expected} | 미구현")
    except Exception as error:
        print(f"{label} | 오류: {type(error).__name__}: {error} | FAIL")


def grid_after_change():
    """2행 3열 격자의 첫 번째 칸만 1로 바꾼 뒤 격자를 반환합니다"""
    grid = make_grid(2, 3)
    grid[0][0] = 1
    return grid


def main():
    test('독립적인 행 (2, 3)', [[1, 0, 0], [0, 0, 0]], grid_after_change)
    test('빈 격자 (0, 3)', [], lambda: make_grid(0, 3))
    test('경로 [1, 2]에 3 추가', ([1, 2], [1, 2, 3]), lambda: save_path([1, 2], 3))
    test('빈 경로에 7 추가', ([], [7]), lambda: save_path([], 7))


if __name__ == '__main__':
    main()
