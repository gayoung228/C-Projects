#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void displayWord(const char guessedWord[]) {
	printf("\nword : ");
	for (int i = 0; guessedWord[i] != '\0'; i++) {
		printf(" %c", guessedWord[i]);
	}
	printf("\n");
}


void displayHangman(int tries) {
	const char* hangmanParts[] = {
		"     _________",
		"    |         |",
		"    |         O",
		"    |        /|\\",
		"    |        / \\",
		"    |"
	};

	printf("\n");
	for (int i = 0; i < tries; i++) {
		printf("%s\n", hangmanParts[i]);
	}
}
