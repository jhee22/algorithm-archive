# Coding Test Study

코딩 테스트 풀이와 직접 구현하는 학습 세트를 한곳에 모았습니다.

**[언어·플랫폼별 풀이 목록](INDEX.md)** · **[Java 연습과 주간 계획](syntax/records/java/README.md)** · **[새 풀이 업로드 방법](docs/WORKFLOW.md)** · **[백준 3주 문제 목록](3weekBoj/README.md)**

## 풀이 현황

<!-- solution-stats:start -->
**전체 풀이 파일: 308개**

| 언어 | CodeTree | LeetCode | 프로그래머스 | SWEA | 합계 |
|---|---:|---:|---:|---:|---:|
| C++ | 39 | 0 | 64 | 0 | 103 |
| Java | 8 | 29 | 141 | 19 | 197 |
| Python | 0 | 0 | 5 | 3 | 8 |
| **합계** | 47 | 29 | 210 | 22 | **308** |

풀이 파일 수 기준입니다. 같은 문제의 여러 구현을 각각 세며, 정답 판정이나 고유 문제 수를 의미하지 않습니다. `syntax/` 연습 파일은 제외합니다.
<!-- solution-stats:end -->

## 폴더 구조

```text
solutions/
  java/
    programmers/       # 프로그래머스 (0, 1, 2, 3 ... 레벨별)
    codetree/          # CodeTree
    swea/              # SWEA
    leetcode/          # LeetCode
  cpp/
    programmers/
    codetree/
  python/
    programmers/       # 프로그래머스 (레벨별)
syntax/                # 주제별 문법 연습 (언어별 파일을 함께 보관)
  Collections/
  Recursion/
  Reference/
  records/             # 날짜별 학습 계획, 힌트와 복습 기록
docs/
  MIGRATION.md         # 통합 기준과 원본 이력
  migration-manifest.json
scripts/               # 새 업로드 정리, 목록 갱신, 이전 검증
```

## 공부하기

1. 플랫폼 풀이를 찾을 때는 [전체 목록](INDEX.md)에서 언어와 플랫폼을 고릅니다.
2. 날짜별 학습 세트에서 문제를 풀고, 문법 연습은 [syntax 안내](syntax/README.md)에서 주제별로 찾습니다.
3. 복습 기록에 사용한 힌트, 소요 시간, 반례를 남깁니다.

풀이 파일의 보관과 정답 판정은 다릅니다. 기존 풀이의 로직은 수정하지 않았으며, 학습 세트의 TODO와 알려진 오류도 그대로 유지했습니다. 같은 문제의 다른 구현은 `variants/` 또는 별도 파일로 남겼습니다.

각 Java 문제는 개별 실행 단위입니다. 같은 `Solution` 클래스가 여러 폴더에 있으므로 저장소 전체를 한 번에 컴파일하지 않습니다. SWEA 코드는 기존 package 선언을 유지하므로 `javac -encoding UTF-8 -d out <파일 경로>`로 개별 컴파일한 뒤 package를 포함한 클래스 이름으로 실행합니다.

## 저장소 운영

앞으로 코테 풀이와 자동 생성 연습 자료는 **이 저장소**에 추가합니다. `cs-interview study`는 별도 관리합니다.

BaekjoonHub와 CodeTree 확장의 업로드 대상은 `jhee22/algorithm-archive`로 지정하세요. 브라우저 확장의 설정은 이 저장소의 코드로 바뀌지 않습니다. 지원되는 업로드 폴더는 GitHub Actions가 언어·플랫폼별로 정리하고 목록을 갱신합니다. 자세한 설정과 수동 실행 방법은 [작업 흐름](docs/WORKFLOW.md)을 참고하세요.

2026-11-05 통합 당시 코드 파일은 300개이며, 이후 현황은 [자동 생성 목록](INDEX.md)에서 확인할 수 있습니다. 원본 레포별 통합 내역과 출처는 [이전 기록](docs/MIGRATION.md)에 있습니다.
