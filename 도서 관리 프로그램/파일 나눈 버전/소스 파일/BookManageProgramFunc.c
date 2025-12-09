#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "BookManageProgramFunc.h"
#include "BookManageProgramStr.h" //search_book 함수에서 compare함수 호출하니까

// 책 추가
int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int* num_total_book, int* borrowed) {

	printf("추가할 책 이름 : ");
	scanf("%s", book_name[*num_total_book]);
	printf("추가할 책 저자 : ");
	scanf("%s", auth_name[*num_total_book]);
	printf("추가할 책 출판사 : ");
	scanf("%s", publ_name[*num_total_book]);

	borrowed[*num_total_book] = 0;
	printf("\n추가 완료!\n\n");
	(*num_total_book)++;

	return 0;
}

// 책 검색
int search_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int num_total_book, int* borrowed) {
	int user_input;
	char user_search[30];
	int found = 0;

	user_input = search_option();

	printf("\n검색할 단어를 입력하세요 : ");
	scanf("%s", user_search);

	printf("\n검색 결과\n");

	if (user_input == 1) {
		for (int i = 0; i < num_total_book; i++) {
			if (compare(book_name[i], user_search)) {
				print_book_info(i, book_name, auth_name, publ_name, borrowed);
				found = 1;
			}
		}
		if (found == 0) {
			printf("검색 결과가 없습니다.\n\n");
		}
	}
	else if (user_input == 2) {
		for (int i = 0; i < num_total_book; i++) {
			if (compare(auth_name[i], user_search)) {
				print_book_info(i, book_name, auth_name, publ_name, borrowed);
				found = 1;
			}
		}
		if (found == 0) {
			printf("검색 결과가 없습니다.\n\n");
		}
	}
	else if (user_input == 3) {
		for (int i = 0; i < num_total_book; i++) {
			if (compare(publ_name[i], user_search)) {
				print_book_info(i, book_name, auth_name, publ_name, borrowed);
				found = 1;
			}
		}
		if (found == 0) {
			printf("검색 결과가 없습니다.\n\n");
		}
	}

	return 0;
}

// 검색 옵션
int search_option() {
	int user_input;

	printf("1. 제목 검색\n");
	printf("2. 지은이 검색\n");
	printf("3. 출판사 검색\n");
	printf("어느 것으로 검색할 것인가요? : ");
	scanf("%d", &user_input);

	return user_input;
}

// 완전 일치
//int compare(char* str1, char* str2) { 
//	while (*str1) {
//		if (*str1 != *str2) {
//			return 0;
//		}
//
//		str1++;
//		str2++;
//	}
//
//	if (*str2 == '\0') {
//		return 1;
//	}
//
//	return 0;
//}

// 책 정보 출력
void print_book_info(int id, char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int* borrowed) {

	printf("-> 번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s // 대출여부 : %s \n\n", id, book_name[id], auth_name[id], publ_name[id], borrowed_status(id, borrowed));
}

// 대출 여부
char* borrowed_status(int id, int* borrowed) {
	if (borrowed[id] == 0) {
		return "대출 가능";
	}
	else {
		return "대출 불가능";
	}
}

// 책 대출
int borrow_book(int* borrowed) {
	int book_num;

	printf("빌릴 책 번호 입력 : ");
	scanf("%d", &book_num);

	if (borrowed[book_num] == 0) {
		printf("성공적으로 대출되었습니다!\n\n");
		borrowed[book_num] = 1;
	}
	else {
		printf("이미 대출된 책입니다.\n\n");
	}

	return 0;
}

// 책 반납
int return_book(int* borrowed) {
	int book_num;

	printf("반납할 책 번호 입력 : ");
	scanf("%d", &book_num);

	if (borrowed[book_num] == 0) {
		printf("이미 반납된 책입니다.\n\n");
	}
	else {
		borrowed[book_num] = 0;
		printf("성공적으로 반납되었습니다!\n\n");
	}

	return 0;
}
