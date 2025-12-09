#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "BookManageProgramFunc.h"

int main() {
	int user_choice;
	int num_total_book = 0;

	char book_name[100][30], auth_name[100][30], publ_name[100][30];
	int borrowed[100];

	while (1) {
		printf("==== 도서 관리 프로그램 ====\n");
		printf("1. 책 새로 추가하기\n");
		printf("2. 책 검색하기\n");
		printf("3. 책 빌리기\n");
		printf("4. 책 반납하기\n");
		printf("5. 프로그램 종료하기\n");
		printf("메뉴를 선택해주세요 : ");
		scanf("%d", &user_choice);

		printf("\n");

		if (user_choice == 1) {
			add_book(book_name, auth_name, publ_name, &num_total_book, borrowed);
		}
		else if (user_choice == 2) {
			search_book(book_name, auth_name, publ_name, num_total_book, borrowed);
		}
		else if (user_choice == 3) {
			borrow_book(borrowed);
		}
		else if (user_choice == 4) {
			return_book(borrowed);
		}
		else if (user_choice == 5) {
			break;
		}
	}

	return 0;
}
