#define MAX_BOOK 100

typedef struct {
    char name[30];      // 책 이름
    char author[30];    // 저자
    char publisher[30]; // 출판사
    int borrowed;       // 0: 대출 가능, 1: 대출 불가능
} Book;

int add_book(Book books[], int* num_total_book);
int search_book(Book books[], int num_total_book);
int borrow_book(Book books[], int num_total_book);
int return_book(Book books[], int num_total_book);
int search_option();
void print_book_info(int id, Book books[]);
const char* borrowed_status(int borrowed); 
