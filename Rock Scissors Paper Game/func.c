#include <stdio.h>
#include "func.h"

void player2_move(int player2, int *total, int *p1wins, int *p2wins, int *ties) {
	if (player2 == 0) {
		printf("It's a tie!\n\n");
		(*total)++;
		(*ties)++;
	}
	else if (player2 == 1) {
		printf("Player 2 wins!\n\n");
		(*total)++;
		(*p2wins)++;
	}
	else if (player2 == 2) {
		printf("Player 1 wins!\n\n");
		(*total)++;
		(*p1wins)++;
	}
	else {
		printf("Invalid choice for Player 2.\n\n");
	}
}

void print_status(int total, int p1wins, int p2wins, int ties) {
	printf("\n----- Game Summary -----\n");
	printf("Total games played: %d\n", total);
	printf("Player 1 wins: %d\n", p1wins);
	printf("Player 2 wins: %d\n", p2wins);
	printf("Ties: %d\n", ties);
}
