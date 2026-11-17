# 새 풀이와 학습 자료 추가

## 직접 저장

풀이: `solutions/<언어>/<플랫폼>/<문제 번호 또는 제목>/<파일>`

- 언어: `java`, `cpp`, `python` 등
- 플랫폼: `programmers`, `baekjoon`, `codetree`, `swea`, `leetcode`
- 같은 문제의 다른 구현: 별도 파일 또는 `variants/<구분>/` 아래에 보관
- 날짜별 학습 세트: `syntax/records/<언어>/<날짜 또는 날짜_주제>/`에 README, 힌트, 복습 기록 저장. 연습 코드는 `syntax/<주제>/`에 저장
- 문법 연습: `syntax/<주제>/syntax1.py`, `syntax1.java`처럼 주제별로 보관. 같은 언어의 새 파일은 번호를 늘리고 Java 클래스 이름과 파일 이름을 일치시킨다.
- 프로그래머스 문제를 다 풀면 `solutions/<언어>/programmers/<레벨>/<문제번호>.<문제이름>/`으로 옮기고 날짜별 README의 링크를 갱신한다. 미완성 연습 문제는 주제별 syntax 폴더에 남긴다.
- 문제 설명과 출처 링크는 해당 풀이 폴더의 README에 기록

완성 풀이를 요청하기 전에는 TODO를 대신 풀지 않고, 기존 풀이와 학습 기록을 보고 다음 세트를 준비합니다. 매일의 세트 README에는 주제별 문법 파일과 문제 링크를 모읍니다. 완료 여부는 학습자의 확인과 테스트 결과를 참고하며, 테스트 통과만으로 플랫폼 정답을 보장하지는 않습니다. Java 학습 세트를 추가하면 `syntax/records/java/README.md`의 목록도 갱신합니다.

## 자동 업로드 확장

브라우저의 BaekjoonHub/CodeTree 확장 설정에서 업로드 저장소를 `jhee22/algorithm-archive`로 변경해야 합니다. 기존 레포가 보관되면 이전 대상을 향한 업로드는 실패합니다.

현재 자동 정리기가 인식하는 루트 폴더:

| 입력 위치 | 정리 위치 |
|---|---|
| `프로그래머스/…` | `solutions/<언어>/programmers/…` |
| `백준/…` | `solutions/<언어>/baekjoon/…` |
| `SWEA/…` | `solutions/<언어>/swea/…` |
| `trail*/…` | `solutions/<언어>/codetree/trail*/…` |

프로그래머스의 Java·Python 업로드는 레벨 폴더가 있으면 그대로 유지하고, 이름이 포함된 문제 폴더는 `문제번호.문제이름` 형식으로 정리합니다. 레벨이 없는 업로드는 `programmers/unclassified/`에 보관합니다. 레벨이나 문제 이름이 빠져 있다면 확인한 뒤 직접 폴더를 정리합니다.

프로그래머스 Java의 `Solution`과 CodeTree Java의 `Main`은 클래스 이름에 맞는 파일명으로 보관합니다. 같은 문제의 다른 구현은 `variants/<내용 해시>/`에 별도로 저장합니다.

다른 경로를 사용하는 확장은 직접 저장 구조로 설정하거나 정리기의 매핑을 추가합니다. Leetdash 대시보드와 타인의 제출물 수집 기능은 통합하지 않았습니다. LeetCode 풀이는 `solutions/java/leetcode/<문제 번호>/`에 직접 추가합니다.

`main`에 관련 파일이 올라오면 `Organize coding study` 워크플로가 실행됩니다. 이미 있는 파일과 내용이 다르면 덮어쓰지 않고 내용 해시로 구분한 버전을 보존합니다. 풀이 없는 README는 이동 대상으로 처리하지 않습니다.

수동 실행:

```sh
python scripts/organize_uploads.py
python -m unittest discover -s scripts -p 'test_*.py'
```

목록만 갱신:

```sh
python scripts/build_index.py
```

이 명령은 `INDEX.md`와 README의 풀이 현황을 함께 갱신합니다. 통계는 `solutions/` 아래의 풀이 파일 수를 세며, 정답 여부나 중복 문제를 판별하지 않습니다.

GitHub Actions가 비활성화되거나 브랜치 정책으로 봇의 push가 차단되면 위 명령을 로컬에서 실행하고 변경 사항을 커밋합니다. 자동화가 돌아가도 문제의 정답 여부를 판정하지는 않습니다.

## 다른 컴퓨터와 기존 자동화

기존 로컬 레포의 미커밋 풀이가 있다면 먼저 보존한 뒤 통합 레포에 추가합니다. 이번 이전은 원격 브랜치에 올라간 파일을 기준으로 했습니다.

코테 생성 자동화에서 사용하던 레포/경로도 `algorithm-archive`와 `syntax/records/java/`로 바꾸어야 합니다. 기존 예약 작업의 실행 설정은 이번 파일 통합만으로 자동 변경되지 않습니다. CS 정리 자동화는 별도로 구성합니다.
