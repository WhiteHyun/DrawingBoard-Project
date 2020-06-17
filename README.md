## Lab4 - Embedded Systems Team Project

### 팀원

- 201601563: 김동언
- 201601639: 홍승현
- 201801527: 김대성
- 201801546: 김태현

### 개발선정

- 그림판

### 일정

- 6월 13일 Lab4 사전회의(9시~10시)

  - 논의사항
    - `개발 선택`: 그림판, 스마트폰 한글 입력지 중 택일
    - 간단한 질의응답
  - 논의결과
    - `그림판` 개발 선정
      1.  UI 구현 및 화면 클리어 구현 ( 2명 ) - 김대성, 김태현
      2.  기초 코드 세팅 ( 2명 ) - 김동언, 홍승현

- 6월 15일 회의 (9시~10시 10분)

  - 논의사항
    - 전반적인 코드 흐름 분석
    - 도형과 이벤트에 `interactive`한 방식에 대한 토의
    - 아이디어 공유
  - 논의결과
    1.  Shape 구조체 논의 보류
    2.  도형에 필요한 matrix만큼 동적 할당하여 가지는 것이 구현 용이성이 있을 것으로 판단
    3.  각자 도형에 대한 구현방안 고려
    4.  FreeDraw에 QnA 답변에 따라 해당되는 내용에 맞는 방안으로 구현 고려
    5.  위의 내용을 상기하여 17일 회의 진행

- 6월 17일 기초구현점검 예정(9시~10시)

  - 논의사항
    1.  13일 코드 리뷰
    2.  Line & Pen & Clear 기능 ( 2명 )
    3.  Oval & Rectangle & Select & Erase ( 2명 )
    4.  Fill & 색상 ( 미정 )
  - 논의결과
    1. 파일 분할 (set.c -> main , btn -> touch sense Events, draw -> Draw UI)
    2. 각 도형 이벤트 분할 ( 김대성 : Line , 김동언 : Oval , 김태현 : Rectangle)
    3. 위의 내용을 상기하여 19일 3시 회의 진행
  - 논의결과
    - TODO

* 6월 26일 Zoom 발표 진행 예정

### 개발 요구사항 (필수)

- 변수명 : addToList (`카멜 표기법`)
- 함수명 : AddToList (`파스칼 표기법`)
- 함수들의 경우 초반부에 역할에 따른 주석 표기
- `if`, `for`문등의 경우 1줄이라도 중괄호`{}` 표기

### 개발 요구사항 (선택)

- TODO

### Role

- Hard Copy Writer
- Developer

### Technology

- Git
- wiringPi

### 개발언어

- C

### 기타사항

- TODO
