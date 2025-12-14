#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main() {

	int player1, player2;

	while (1) {
		printf("========== 가위 바위 보 게임 ==========\n");
		printf("0: Rock\n");
		printf("1: Paper\n");
		printf("2: Scissors\n");
		printf("3: Exit\n");
		printf("=======================================\n\n");
		printf("Enter Player 1's choice : ");
		scanf("%d", &player1);
		printf("Enter Player 2's choice : ");
		scanf("%d", &player2);

		printf("\n----- 결과 창 -----\n");

		switch (player1) {
		case 0: // Rock
			player2_move(player2);
			break;
		case 1: // Paper
			player2_move(player2);
			break;
		case 2: // Scissors
			player2_move(player2);
			break;
		case 3: // Exit
			printf("Exiting the game.\n");
			return 0;
		}
	}

	return 0;
}
