# 새 풀이와 학습 자료 추가

## 직접 저장

풀이: `solutions/<언어>/<플랫폼>/<문제 번호 또는 제목>/<파일>`

- 언어: `java`, `cpp`, `python` 등
- 플랫폼: `programmers`, `baekjoon`, `codetree`, `swea`, `leetcode`
- 같은 문제의 다른 구현: 별도 파일 또는 `variants/<구분>/` 아래에 보관
- 학습 세트: `practice/<언어>/<날짜_주제>/` 아래에 TODO, README, 힌트, 복습 기록 저장
- 문제 설명과 출처 링크는 해당 풀이 폴더의 README에 기록

완성 풀이를 요청하기 전에는 TODO를 대신 풀지 않고, 기존 풀이와 학습 기록을 보고 다음 세트를 준비합니다. 새 학습 세트를 추가하면 `practice/java/README.md`의 목록도 갱신합니다.

## 자동 업로드 확장

브라우저의 BaekjoonHub/CodeTree 확장 설정에서 업로드 저장소를 `jhee22/algorithm-archive`로 변경해야 합니다. 기존 레포가 보관되면 이전 대상을 향한 업로드는 실패합니다.

현재 자동 정리기가 인식하는 루트 폴더:

| 입력 위치 | 정리 위치 |
|---|---|
| `프로그래머스/…` | `solutions/<언어>/programmers/…` |
| `백준/…` | `solutions/<언어>/baekjoon/…` |
| `SWEA/…` | `solutions/<언어>/swea/…` |
| `trail*/…` | `solutions/<언어>/codetree/trail*/…` |

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

GitHub Actions가 비활성화되거나 브랜치 정책으로 봇의 push가 차단되면 위 명령을 로컬에서 실행하고 변경 사항을 커밋합니다. 자동화가 돌아가도 문제의 정답 여부를 판정하지는 않습니다.

## 다른 컴퓨터와 기존 자동화

기존 로컬 레포의 미커밋 풀이가 있다면 먼저 보존한 뒤 통합 레포에 추가합니다. 이번 이전은 원격 브랜치에 올라간 파일을 기준으로 했습니다.

코테 생성 자동화에서 사용하던 레포/경로도 `algorithm-archive`와 `practice/java/`로 바꾸어야 합니다. 기존 예약 작업의 실행 설정은 이번 파일 통합만으로 자동 변경되지 않습니다. CS 정리 자동화는 별도로 구성합니다.
