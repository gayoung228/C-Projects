#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "BookManageProgramStructFunc_file.h"
#include "BookManageProgramStructStr_file.h"

// 책 추가
int add_book(Book books[], int* num_total_book) {

    if (*num_total_book >= MAX_BOOK) {
        printf("더 이상 책을 추가할 수 없습니다.\n\n");
        return 0;
    }

    printf("추가할 책 이름 : ");
    scanf("%s", books[*num_total_book].name);
    printf("추가할 책 저자 : ");
    scanf("%s", books[*num_total_book].author);
    printf("추가할 책 출판사 : ");
    scanf("%s", books[*num_total_book].publisher);

    books[*num_total_book].borrowed = 0;   // 대출 가능 상태
    printf("\n추가 완료!\n\n");
    (*num_total_book)++;

    return 0;
}

// 책 검색
int search_book(Book books[], int num_total_book) {
    int user_input;
    char user_search[30];
    int found = 0;

    if (num_total_book == 0) {
        printf("등록된 책이 없습니다.\n\n");
        return 0;
    }

    user_input = search_option();

    printf("\n검색할 단어를 입력하세요 : ");
    scanf("%s", user_search);

    printf("\n검색 결과\n");

    for (int i = 0; i < num_total_book; i++) {
        if (user_input == 1) { // 제목
            if (compare(books[i].name, user_search)) {
                print_book_info(i, books);
                found = 1;
            }
        }
        else if (user_input == 2) { // 지은이
            if (compare(books[i].author, user_search)) {
                print_book_info(i, books);
                found = 1;
            }
        }
        else if (user_input == 3) { // 출판사
            if (compare(books[i].publisher, user_search)) {
                print_book_info(i, books);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("검색 결과가 없습니다.\n\n");
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

// 책 정보 출력
void print_book_info(int id, Book books[]) {

    printf("-> 번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s // 대출여부 : %s \n\n",
        id,
        books[id].name,
        books[id].author,
        books[id].publisher,
        borrowed_status(books[id].borrowed));
}

// 대출 여부
const char* borrowed_status(int borrowed) {
    if (borrowed == 0) {
        return "대출 가능";
    }
    else {
        return "대출 불가능";
    }
}

// 책 대출
int borrow_book(Book books[], int num_total_book) {
    int book_num;

    if (num_total_book == 0) {
        printf("등록된 책이 없습니다.\n\n");
        return 0;
    }

    printf("빌릴 책 번호 입력 : ");
    scanf("%d", &book_num);

    if (book_num < 0 || book_num >= num_total_book) {
        printf("잘못된 번호입니다.\n\n");
        return 0;
    }

    if (books[book_num].borrowed == 0) {
        printf("성공적으로 대출되었습니다!\n\n");
        books[book_num].borrowed = 1;
    }
    else {
        printf("이미 대출된 책입니다.\n\n");
    }

    return 0;
}

// 책 반납
int return_book(Book books[], int num_total_book) {
    int book_num;

    if (num_total_book == 0) {
        printf("등록된 책이 없습니다.\n\n");
        return 0;
    }

    printf("반납할 책 번호 입력 : ");
    scanf("%d", &book_num);

    if (book_num < 0 || book_num >= num_total_book) {
        printf("잘못된 번호입니다.\n\n");
        return 0;
    }

    if (books[book_num].borrowed == 0) {
        printf("이미 반납된 책입니다.\n\n");
    }
    else {
        books[book_num].borrowed = 0;
        printf("성공적으로 반납되었습니다!\n\n");
    }

    return 0;
}
