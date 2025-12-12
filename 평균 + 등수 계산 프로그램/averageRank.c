#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(int argc, char **argv) {

	int subjects;
	int students;
	int** arr;
	int input;

	printf("과목 수 입력 : ");
	scanf("%d", &subjects);
	printf("학생 수 입력 : ");
	scanf("%d", &students);

	arr = (int**)malloc(sizeof(int*) * students);

	for (int i = 0; i < students; i++) {
		arr[i] = (int*)malloc(sizeof(int) * subjects);
	}

	for (int i = 0; i < students; i++) {
		printf("학생 %d 점수 ------------ \n", i);
		for (int j = 0; j < subjects; j++) {
			printf("과목 %d 점수 입력 : ", j);
			scanf("%d", &input);

			arr[i][j] = input;
		}
	}

	double* avg = (double*)malloc(sizeof(double) * students);
	int* rank = (int*)malloc(sizeof(int) * students);

	student_average(arr, subjects, students, avg);
	student_rank(avg, rank, students);

	printf("\n========== 학생 평균 ==========\n");
	for (int i = 0; i < students; i++) {
		printf("학생 %d 평균 : %.2f, %d등\n", i, avg[i], rank[i]);
	}

	for (int i = 0; i < students; i++) {
		free(arr[i]);
	}
	free(arr);
	free(avg);
	free(rank);

	return 0;
}
