#include "BookManageProgramStr.h"

// 부분 포함 일치
int compare(char* str1, char* str2) {
	int j;
	for (int i = 0; str1[i] != '\0'; i++) { //everyone
		j = 0;
		while (str1[i + j] == str2[j] && str2[j] != '\0') {
			j++;
		}
		if (str2[j] == '\0') {
			return 1;
		}
	}

	return 0;
}
