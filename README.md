## 목적
기본 자료구조를 제공합니다

## 목록
- 스택(stack)
- 큐(queue)
- 연결리스트(linked list)
- 해시맵(hashmap)

## 사용하기
#### 리눅스계열
1. 해당 프로젝트를 클론합니다
2. 프로젝트의 루트 디렉토리(root directory)에서 `ar -r ./lib/data_structure.a ./obj/*.o` 실행합니다.(lib 폴더 안에 `data_structure.a`가 생성되어야 합니다)
3. 빌드하고자 하는 프로젝트에서 `clang -std=c89 -W -Wall -pedantic-errors -I <헤더파일_위치_디렉토리> -L <라이브러리파일_위치_디렉토리> -l<라이브러리_이름> *.c` 를 통해 라이브러리를 정적 링킹 해줍니다.  
ex) `clang -std=c89 -W -Wall -pedantic-errors -I /Users/heechul/c-data-structure/header -L /Users/heechul/c-data-structure/lib -ldata_structure *.c`

#### 윈도우
1. 해당 프로젝트를 클론합니다
2. 프로젝트의 루트 디렉토리(root directory)에서 `llvm-ar -r ./lib/data_structure.lib ./obj/*.o` 실행합니다.(lib 폴더 안에 `data_structure.lib`가 생성되어야 합니다)
3. 빌드하고자 하는 프로젝트에서 `clang -std=c89 -W -Wall -pedantic-errors -I <헤더파일_위치_디렉토리> -L <라이브러리파일_위치_디렉토리> -l<라이브러리_이름> *.c` 를 통해 라이브러리를 정적 링킹 해줍니다.  
ex) `clang -std=c89 -W -Wall -pedantic-errors -I /Users/heechul/c-data-structure/header -L /Users/heechul/c-data-structure/lib -ldata_structure *.c`

## 이슈 로그
### 링크드리스트 헤드 이슈
##### 상황
```
list_node_t* head = NULL;

add(head, 100);
```
이런식으로 링크드리스트의 헤드를 null로 설정하고 값을 넘겨준다 
```
void add(node_t* head, int value)
```
여기서 넘겨받은 head의 주소는 매개변수로 넘어오기 때문에 복사되어 호출하는 곳에서 있는 주소와 다른 주소가 넘어오게 된다.
그래서 head에 아무리 값을 추가로 할당을해도 add의 호출 컨텍스트에 값이 할당되지 않고 댕글링 포인터가 발생한다.
