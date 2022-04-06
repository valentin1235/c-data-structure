## 목적
기본 자료구조를 제공합니다

## 자료구조 목록
- 스택(stack)
- 큐(queue)
- 연결리스트(linked list)
- 해시맵(hashmap)

## 사용하기
#### 리눅스계열
1. 해당 프로젝트를 클론합니다
2. 프로젝트의 루트 디렉토리(root directory)에서 `ar -r ./lib/data_structure.a ./obj/*.o` 실행합니다.(lib 폴더 안에 `data_structure.a`가 생성되어야 합니다)
3. 빌드하고자 하는 프로젝트에서 `clang -std=c89 -W -Wall -pedantic-errors -I <헤더파일_위치_디렉토리> -L <라이브러리파일_위치_디렉토리> -l<라이브러리_이름> *.c` 를 통해 라이브러리를 정적 링킹 해줍니다.  
예시 `clang -std=c89 -W -Wall -pedantic-errors -I /Users/heechul/c-data-structure/header -L /Users/heechul/c-data-structure/lib -ldata_structure *.c`

#### 윈도우
1. 해당 프로젝트를 클론합니다
2. 프로젝트의 루트 디렉토리(root directory)에서 `llvm-ar -r ./lib/data_structure.lib ./obj/*.o` 실행합니다.(lib 폴더 안에 `data_structure.lib`가 생성되어야 합니다)
3. 빌드하고자 하는 프로젝트에서 `clang -std=c89 -W -Wall -pedantic-errors -I <헤더파일_위치_디렉토리> -L <라이브러리파일_위치_디렉토리> -l<라이브러리_이름> *.c` 를 통해 라이브러리를 정적 링킹 해줍니다.  
예시 `clang -std=c89 -W -Wall -pedantic-errors -I /Users/heechul/c-data-structure/header -L /Users/heechul/c-data-structure/lib -ldata_structure *.c`
