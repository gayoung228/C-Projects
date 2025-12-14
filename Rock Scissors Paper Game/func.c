#include <stdio.h>
#include "func.h"

void player2_move(player2) {
	if (player2 == 0) {
		printf("It's a tie!\n\n");
	}
	else if (player2 == 1) {
		printf("Player 2 wins!\n\n");
	}
	else if (player2 == 2) {
		printf("Player 1 wins!\n\n");
	}
	else {
		printf("Invalid choice for Player 2.\n\n");
	}
}
