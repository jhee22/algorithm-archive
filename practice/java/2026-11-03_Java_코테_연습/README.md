# 11월 3일 · 자료구조를 규칙으로 연결하기

어제는 컬렉션 하나의 동작을 구현했다. 오늘은 동률, 도착 시각, 취소, 구간 제한을 읽고 무엇을 기억할지 직접 정한다. 목표는 150분이다. 아래 순서로 130분을 풀고 마지막 20분은 반례와 기록에 쓴다.

| 순서 | 문제 | 연습 난이도 | 목표 |
|---|---|---|---|
| 1 | [관측소 신호 순위](01_HashMapSorting/Problem01.java) | 기초 응용 | 20분 |
| 2 | [교정실의 빈 슬롯](02_QueueHeap/Problem02.java) | 중급 | 30분 |
| 3 | [교정 테이프의 봉인](03_StringSimulation/Problem03.java) | 중급~중상급 | 35분 |
| 4 | [연속 항차 감사 구간](04_ImplementationChallenge/Problem04.java) | 중상급 도전 | 45분 |

시작 전 빈 입력의 반환값, 동률 규칙, 상태를 바꾸는 시점, 종료 조건을 한 줄씩 적는다. 예제 하나를 손으로 실행한 뒤 변수와 자료형을 고른다. 오늘 쓸 수 있는 Java 8 도구로 `getOrDefault`, `Long.compare`, `thenComparing`, `offer/poll/peek`, `charAt`, `setLength`의 반환값과 호출 조건을 점검한다.

## 실행과 완료 확인

각 문제 폴더에서 아래 명령을 실행한다. 2~4번은 클래스 이름의 번호를 바꾼다.

```powershell
javac -encoding UTF-8 Problem01.java
java '-Dfile.encoding=UTF-8' Problem01
```

- [ ] 첫 실행에서 모든 케이스에 NOT_IMPLEMENTED가 표시되는지 확인했다.
- [ ] 각 파일의 solution에 내 코드를 작성하고 main을 다시 실행했다.
- [ ] 실패한 입력은 가장 작게 줄였고, 직접 만든 경계 입력도 확인했다.
- [ ] [힌트](힌트.md)를 열었다면 최고 단계를 [복습 기록](복습기록.md)에 적었다.
- [ ] 핵심 상태와 시간·공간 복잡도를 설명하고 재풀이할 문제를 골랐다.
