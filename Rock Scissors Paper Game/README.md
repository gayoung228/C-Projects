# 가위 바위 보 게임 (C 콘솔 프로그램)

## 1. 개요
두 명의 플레이어가 콘솔에서 가위, 바위, 보 중 하나를 선택하여  
승패를 판단하고, 게임 결과를 **누적 통계로 관리하는**  
C 언어 기반 콘솔 게임입니다.

게임은 반복 실행되며, 사용자가 종료를 선택하면  
총 게임 수, 승리 횟수, 무승부 횟수를 요약하여 출력합니다.

---

## 2. 게임 규칙

### 입력 값 의미
- `0` : Rock (바위)
- `1` : Paper (보)
- `2` : Scissors (가위)
- `3` : Exit (게임 종료)

### 승패 규칙
- 같은 선택 → 무승부
- Rock < Paper
- Paper < Scissors
- Scissors < Rock

---

## 3. 실행 방법

### 실행 예시
```text
========== 가위 바위 보 게임 ==========
0: Rock
1: Paper
2: Scissors
3: Exit
=======================================

Enter Player 1's choice : 0
Enter Player 2's choice : 2

----- 결과 창 -----
Player 1 wins!

----- Game Summary -----
Total games played: 5
Player 1 wins: 2
Player 2 wins: 2
Ties: 1
```

--- 

## 4. 프로그램 흐름
1. 게임 메뉴 출력
2. Player 1과 Player 2의 선택 입력
3. Player 2의 선택을 기준으로 승패 판정
5. 결과 출력 및 누적 통계 갱신
6. Exit 선택 시 게임 종료 및 통계 출력

--- 

## 5. 주요 함수 설명

### `player2_move`

```c
void player2_move(
    int player2,
    int *total,
    int *p1wins,
    int *p2wins,
    int *ties
);
```
- Player 1과 Player 2의 선택 값을 비교하여 승패를 판정합니다.
- 게임 결과에 따라 전체 게임 수, 승리 횟수, 무승부 횟수를 누적합니다.
- 포인터를 사용하여 main 함수의 통계 변수를 직접 수정합니다.
- 잘못된 입력 값이 들어오면 오류 메시지를 출력합니다.

### `print_status`
```c
void print_status(int total, int p1wins, int p2wins, int ties);
```
- 게임 종료 시 누적된 통계 정보를 출력합니다.
- 총 게임 수, Player 1 승리 횟수, Player 2 승리 횟수, 무승부 횟수를 보여줍니다.
--- 

## 6. 사용 기술 및 핵심 개념

- C 언어
- `while` 반복문을 이용한 게임 루프
- `switch-case` 문을 이용한 입력 분기 처리
- 포인터를 활용한 값 누적(Call by Reference)
- 함수 분리를 통한 역할 구분
- 콘솔 기반 사용자 입력/출력

