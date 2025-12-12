#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void student_average(int **arr, int subjects, int students, double *avg) {
	int sum;

	for (int i = 0; i < students; i++) {
		sum = 0;
		for (int j = 0; j < subjects; j++) {
			sum += arr[i][j];
		}
		avg[i] = (double)sum / subjects;
	}
}

void student_rank(double *avg, int *rank, int students) {
	for (int i = 0; i < students; i++) {
		rank[i] = 1; // 초기 등수 1등으로 설정
		for (int j = 0; j < students; j++) {
			if (avg[j] > avg[i]) {
				rank[i]++; // 더 높은 평균 점수를 가진 학생이 있으면 등수 증가
			}
		}
	}
}
