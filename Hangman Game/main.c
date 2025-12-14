#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "func.h"

#define MAX_TRIES 6
#define MAX_WORD_LENGTH 60

struct WordHint {
	char word[MAX_WORD_LENGTH];
	char hint[MAX_WORD_LENGTH];
};

int main() {

	srand(time(NULL));
	
	struct WordHint wordList[] = {
		{"elephant", "A large animal"},
		{"computer", "An electronic device"},
		{"beach", "Sandy shore by the sea"},
		{"pizza", "Italian food with cheese"},
		{"guitar", "A musical instrument with strings"}
	};

	int wordIndex = rand() % 5; // 단어 리스트에서 무작위로 선택

	const char* answer = wordList[wordIndex].word;
	const char* hint = wordList[wordIndex].hint;

	int wordLength = strlen(answer);
	char guessedWord[MAX_WORD_LENGTH] = { 0 }; // 추측한 단어 저장
	bool guessedLetters[26] = { 0 }; // 추측한 글자 저장

	// guessedWord 초기화
	for (int i = 0; i < wordLength; i++) {
		guessedWord[i] = '_';
	}
	guessedWord[wordLength] = '\0';  

	printf("===== Welcome to Hangman! =====\n");
	printf("Hint : %s\n", hint);

	int tries = 0;

	while (tries < MAX_TRIES) {

		displayWord(guessedWord); //단어 표시
		displayHangman(tries); // 행맨 표시

		char guess;
		printf("\nEnter your guess (single letter): ");
		scanf(" %c", &guess);
		guess = tolower(guess); // 소문자로 변환

		// 입력 유효성 검사
		if (guess < 'a' || guess > 'z') {
			printf("알파벳만 입력하세요.\n");
			continue;
		}

		if (guessedLetters[guess - 'a']) {
			printf("이미 입력한 글자입니다. 다시 시도하세요.\n");
			continue;
		}

		guessedLetters[guess - 'a'] = true;

		bool correctGuess = false; // 정답 여부 확인
		for(int i=0; i<wordLength; i++) {
			if (answer[i] == guess) {
				guessedWord[i] = guess;
				correctGuess = true;
			}
		}

		if (correctGuess) {
			printf("정답입니다!\n");
		}
		else {
			printf("틀렸습니다. 그 단어에는 '%c'가 없습니다.\n", guess);
			tries++;
		}

		if (strcmp(answer, guessedWord) == 0) {
			printf("\n축하합니다! 단어를 맞추셨습니다. 답 : %s\n", answer);
			break;
		}
	}

	if(tries>=MAX_TRIES) {
		printf("\n게임 오버! 정답은 '%s'였습니다.\n", answer);
	}

	return 0;
}
