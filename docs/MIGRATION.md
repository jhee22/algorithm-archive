# 2026-11-05 코테 저장소 통합

통합 대상은 `jhee22/algorithm-archive`입니다. 기존 기본 브랜치의 이력을 이어서 정리했으며, 다른 원본 레포의 커밋 이력을 이 저장소에 합쳐 넣지는 않았습니다. 원본 커밋은 원본 레포와 로컬 Git bundle 백업에 보존합니다.

## 가져온 자료

| 원본 | 추가된 풀이 파일 | 처리 |
|---|---:|---|
| algorithm-archive | 43 | Java 31, C++ 12; 기존 프로그래머스 풀이 재배치 |
| codeTree | 47 | Java 8, C++ 39; 문제 설명 포함 |
| swea | 19 | Java; package와 학습일별 구조 보존 |
| hynixCpp | 52 | C++; 실제 내용은 프로그래머스 풀이. 본인 코드 공개 통합 승인 후 반영 |
| leetdash | 139 | Java; LeetCode 29, 프로그래머스 110 |
| algo-autopilot | 별도 | Java 연습 파일 6개와 README·힌트·복습 기록을 practice에 보존 |

총 300개는 **고유 목적지의 풀이 코드 파일 수**입니다. 서로 다른 구현 버전도 포함하므로 해결한 고유 문제 수나 정답 수가 아닙니다.

## 본인 풀이와 중복 판단

- 원본 Git 이력에서 본인 작성자 이메일을 확인했습니다. 파일명 변경은 `git log --follow`로 추적했습니다.
- Leetdash는 `submissions/jhee22/` 아래만 가져왔습니다. `jeehee`, `master`, `prompt`의 원격 브랜치를 모두 비교했습니다.
- Leetdash의 타인 풀이, 대시보드, 배포·AI 리뷰 워크플로는 제외했습니다.
- 실제 GitHub fork인 레포는 leetdash이며, codeTree/hynixCpp/swea는 fork 플래그가 없는 본인 레포였습니다.
- 같은 문제의 동일 바이트 파일만 합쳤습니다. 다른 내용은 별도 파일 또는 `variants/`로 보존했습니다.
- CodeTree의 풀이 없는 문제 설명은 `docs/source-readmes/codeTree/` 아래에 보존하고 풀이 집계에서 제외했습니다.
- 원본 코드를 고치거나 TODO를 완성하지 않았습니다. 기존 오류와 미완성 여부도 그대로입니다.

## 검증과 출처

`migration-manifest.json`에 원본 레포, ref, 커밋 SHA, 경로, 목적지, SHA-256, 중복 여부, 선정 근거를 기록했습니다. 원본은 다음 형식으로 확인할 수 있습니다.

```text
https://github.com/jhee22/<repository>/blob/<commit>/<source>
```

이전 직후 원본 자료 513건이 목적지 459개 파일에 정확히 보존됐는지 SHA-256으로 검증했습니다. 이는 생성된 README, 목록, 정리 스크립트 등을 제외한 수치입니다.

```sh
python scripts/verify_migration.py
```

이 검증은 이전 시점의 스냅샷용입니다. 이후 공부하면서 코드를 수정하면 해시가 달라지는 것이 정상이며, 일상적인 CI에서 실행하지 않습니다.

원본 6개 레포는 작업 컴퓨터의 `Git매니졀/backups/<레포>.bundle`에 전체 원격 브랜치와 태그를 포함해 백업했습니다. 백업 파일은 GitHub에 업로드하지 않습니다. 복원 예:

```sh
git clone <레포>.bundle <복원할 새 폴더>
```

원격 기본 브랜치 통합 완료 후 원본 5개 레포에는 이전 안내를 남기고 보관(archive) 처리합니다. 삭제하지 않으며, 필요하면 GitHub Settings에서 보관을 해제할 수 있습니다. `cs-interview study`는 변경하지 않습니다.
