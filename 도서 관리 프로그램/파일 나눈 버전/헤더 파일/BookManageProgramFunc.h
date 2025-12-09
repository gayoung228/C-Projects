int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int* num_total_book, int* borrowed);
int search_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int num_total_book, int* borrowed);
int borrow_book(int* borrowed);
int return_book(int* borrowed);
int search_option();
void print_book_info(int id, char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int* borrowed);
char* borrowed_status(int id, int* borrowed);
