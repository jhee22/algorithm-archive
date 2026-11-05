# 11월 2일 Java 코딩 테스트 연습

압축 파일의 10월 30일 학습 내용을 기준으로 이어지는 Java 8 연습입니다. 배열과 문자열 메서드는 코드가 작성되어 있었고, 컬렉션과 큐·스택·힙은 미구현 상태였습니다. 작성 여부는 정답 검증과 다릅니다.

## 오늘의 순서

1. `01_Collections/CollectionsPractice.java`: 리스트, 맵, 집합 (약 40분)
2. `02_QueueStackHeap/QueueStackHeapPractice.java`: 큐, 스택, 힙 (약 40분)
3. `힌트.md`는 막혔을 때 한 단계씩 확인하고 `복습기록.md`에 기록합니다.

각 파일의 TODO 메서드를 직접 작성하고 `throw new UnsupportedOperationException();`을 제거하세요. `main`에서 입력, 예상값, 실제값, 통과 여부를 확인합니다. 미구현은 아직 풀지 않았다는 표시입니다. VS Code에서 각 파일의 `main` 위 Run 또는 Debug를 누르거나, 각 폴더에서 다음 명령을 사용하세요.

```powershell
javac -encoding UTF-8 -source 8 -target 8 CollectionsPractice.java
java '-Dfile.encoding=UTF-8' CollectionsPractice
```

두 번째 폴더에서는 파일명과 클래스명을 `QueueStackHeapPractice`로 바꾸세요. `.java`는 직접 수정하는 코드이고 `.class`는 컴파일 결과입니다.

## GitHub로 진도 공유하기

GitHub에 이 폴더를 저장소로 올리면 다른 컴퓨터에서 `git clone <저장소-URL>`로 받을 수 있습니다. 이미 클론한 컴퓨터에서는 `git pull`로 새 내용을 받아오고, 푼 내용을 확인받으려면 변경사항을 커밋하고 `git push`해야 합니다. 제가 확인할 때는 저장소 URL과 접근 권한 또는 최신 파일이 필요합니다. 로컬에서만 수정한 내용은 GitHub나 제가 자동으로 볼 수 없습니다.

공개 저장소는 누구나 볼 수 있으므로 코테 연습 외 개인정보나 비밀키가 들어가지 않았는지 확인하세요. `.gitignore`는 컴파일 결과를 제외합니다. 기존 압축 파일은 자동으로 업로드하지 않았습니다.
