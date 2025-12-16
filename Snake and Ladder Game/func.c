#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

int player1 = 0, player2 = 0;

int rollDice() {
	return (rand() % 6) + 1; // 1부터 6까지의 랜덤 숫자 반환
}

void printBoard() {
	int board[101];
	for (int i = 0; i <= 100; i++) {
		board[i] = i;
	}

	int alt = 0; //출력 방향 결정(줄이 바뀔 때마다 0과 1로 변경)
	int iterLR = 101; //왼쪽에서 오른쪽으로
	int iterRL = 80; //오른쪽에서 왼쪽으로
	int val = 100; //보드를 몇 번 출력할지 결정

	while (val--) { //val이 0이 될 때까지 반복
		if (alt == 0) { //alt가 0일 때 왼쪽에서 오른쪽으로 출력
			iterLR--; //숫자를 줄여가며 출력
			if (iterLR == player1) {
				printf("#P1    ");
			}
			else if (iterLR == player2) {
				printf("#P2    ");
			}
			else {
				printf("%d    ", board[iterLR]);
			}

			if (iterLR % 10 == 1) { //나머지가 1일 때 줄 바꿈
				printf("\n\n");
				alt = 1; //방향 변경
				iterLR -= 10; //다음 줄의 오른쪽 끝으로 이동
			}
		}
		else {
			iterRL++; //숫자를 늘려가며 출력
			if (iterRL == player1) {
				printf("#P1    ");
			}
			else if (iterRL == player2) {
				printf("#P2    ");
			}
			else {
				printf("%d    ", board[iterRL]);
			}

			if (iterRL % 10 == 0) { //나머지가 0일 때 줄 바꿈
				printf("\n\n");
				alt = 0;
				iterRL -= 30;
			}
		}
		if (iterRL == 10) {
			break;
		}
	}
	printf("\n");
}

int movePlayer(int currentPlayer, int roll) {
	int newPosition = currentPlayer + roll;
	int snakesLadders[101];

	for (int i = 0; i <= 100; i++) {
		snakesLadders[i] = 0;
	}

	snakesLadders[3] = 12;   // 사다리
	snakesLadders[18] = 26;  // 사다리
	snakesLadders[25] = 29;  // 사다리
	snakesLadders[30] = -5; // 뱀
	snakesLadders[43] = 56;  // 사다리
	snakesLadders[50] = -12; // 뱀
	snakesLadders[71] = -19; // 뱀
	snakesLadders[85] = -4;  // 뱀
	snakesLadders[92] = -10; // 뱀

	int newSquare = newPosition + snakesLadders[newPosition]; 

	if (newSquare > 100) {
		return currentPlayer; // 100을 넘으면 이동하지 않음
	}

	return newSquare;
}
