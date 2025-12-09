//구조체 사용한 도서 관리 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "BookManageProgramStructFunc_file.h"

int main() {
    int user_choice;
    int num_total_book = 0;

    Book books[MAX_BOOK];

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
            add_book(books, &num_total_book);
        }
        else if (user_choice == 2) {
            search_book(books, num_total_book);
        }
        else if (user_choice == 3) {
            borrow_book(books, num_total_book);
        }
        else if (user_choice == 4) {
            return_book(books, num_total_book);
        }
        else if (user_choice == 5) {
            break;
        }
        else {
            printf("잘못된 입력입니다.\n\n");
        }
    }

    return 0;
}
