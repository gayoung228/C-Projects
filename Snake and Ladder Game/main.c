#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

int main() {

	srand(time(NULL));
	int currentPlayer = 1;
	int won = 0;

	printf("===== Snake and Ladder Game =====\n\n");

	while (!won) {
		printf("player %d, press enter to roll the dice! ", currentPlayer);
		getchar(); // 유저가 엔터를 누를 때까지 대기

		int roll = rollDice();
		printf("you rolled a %d!\n", roll);

		if (currentPlayer == 1) {
			player1 = movePlayer(player1, roll);
			printf("Player 1 is now on square %d\n\n", player1);
			printBoard();
			if (player1 == 100) {
				printf("Player 1 wins!\n");
				won = 1;
			}
		}
		else {
			player2 = movePlayer(player2, roll);
			printf("Player 2 is now on square %d\n\n", player2);
			printBoard();
			if (player2 == 100) {
				printf("Player 2 wins!\n");
				won = 1;
			}
		}

		currentPlayer = (currentPlayer == 1) ? 2 : 1; // 플레이어 교체
	}

	return 0;
}
