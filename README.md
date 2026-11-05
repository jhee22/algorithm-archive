# Coding Test Study

코딩 테스트 풀이와 직접 구현하는 학습 세트를 한곳에 모았습니다.

**[언어·플랫폼별 풀이 목록](INDEX.md)** · **[Java 연습과 주간 계획](practice/java/README.md)** · **[새 풀이 업로드 방법](docs/WORKFLOW.md)**

## 폴더 구조

```text
solutions/
  java/
    programmers/       # 프로그래머스
    codetree/          # CodeTree
    swea/              # SWEA
    leetcode/          # LeetCode
  cpp/
    programmers/
    codetree/
practice/
  java/                # 날짜별 TODO 연습, 힌트, main 테스트, 복습 기록
docs/
  MIGRATION.md         # 통합 기준과 원본 이력
  migration-manifest.json
scripts/               # 새 업로드 정리, 목록 갱신, 이전 검증
```

## 공부하기

1. 플랫폼 풀이를 찾을 때는 [전체 목록](INDEX.md)에서 언어와 플랫폼을 고릅니다.
2. 연습할 때는 [Java 학습 세트](practice/java/README.md)에서 날짜별 README와 TODO를 엽니다.
3. 복습 기록에 사용한 힌트, 소요 시간, 반례를 남깁니다.

풀이 파일의 보관과 정답 판정은 다릅니다. 기존 풀이의 로직은 수정하지 않았으며, 학습 세트의 TODO와 알려진 오류도 그대로 유지했습니다. 같은 문제의 다른 구현은 `variants/` 또는 별도 파일로 남겼습니다.

각 Java 문제는 개별 실행 단위입니다. 같은 `Solution` 클래스가 여러 폴더에 있으므로 저장소 전체를 한 번에 컴파일하지 않습니다. SWEA 코드는 기존 package 선언을 유지하므로 `javac -encoding UTF-8 -d out <파일 경로>`로 개별 컴파일한 뒤 package를 포함한 클래스 이름으로 실행합니다.

## 저장소 운영

앞으로 코테 풀이와 자동 생성 연습 자료는 **이 저장소**에 추가합니다. `cs-interview study`는 별도 관리합니다.

BaekjoonHub와 CodeTree 확장의 업로드 대상은 `jhee22/algorithm-archive`로 지정하세요. 브라우저 확장의 설정은 이 저장소의 코드로 바뀌지 않습니다. 지원되는 업로드 폴더는 GitHub Actions가 언어·플랫폼별로 정리하고 목록을 갱신합니다. 자세한 설정과 수동 실행 방법은 [작업 흐름](docs/WORKFLOW.md)을 참고하세요.

2026-11-05 통합 당시 코드 파일은 300개이며, 이후 현황은 [자동 생성 목록](INDEX.md)에서 확인할 수 있습니다. 원본 레포별 통합 내역과 출처는 [이전 기록](docs/MIGRATION.md)에 있습니다.
