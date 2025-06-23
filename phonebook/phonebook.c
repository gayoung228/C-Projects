#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phone_book {
    char name[20];
    char phone[15];
    int birth;
};

enum { NAME, PHONE, BIRTH }; // 0, 1, 2

int qty = 0; // 현재까지 등록된 학생 수 (예: qty = 0이면 아무도 없음). qty = 0 → list[0]에 새 정보 저장

void print_menu();
void print_list(struct phone_book list);
void add(struct phone_book* list); // add()는 struct phone_book 구조체 자체가 아니라 주소를 넘겨 받아야 동작. list는 struct phone_book 포인터이다.
void search(struct phone_book list[], int kind); //list[]는 전화번호부 구조체 배열. kind는 검색 기준이다.
void sort(struct phone_book list[], int kind);
void save(struct phone_book list[]); //전화번호부 구조체 배열을 받는다.
void load(struct phone_book list[]);
void del(struct phone_book list[]);
void all(struct phone_book list[]);

// 이름 기준 비교 함수 (qsort에서 사용)
int compare_name(const void* a, const void* b) { // 비교 함수는 항상 두 개의 void* 포인터를 매개변수로 받아야한다. 이 포인터들은 배열 안의 원소들을 가리킨다.
    // a와 b는 void* 타입이기 때문에 바로 사용 가능. so, (struct phone_book*)으로 바꿔서 pa, pb라는 포인터에 저장. pa->name, pb->name 처럼 구조체 안의 값을 접근가능하다.
    struct phone_book* pa = (struct phone_book*)a; // 첫 번째 구조체 포인터
    struct phone_book* pb = (struct phone_book*)b; // 두 번째 구조체 포인터
    return strcmp(pa->name, pb->name); // 이름을 기준으로 사전순 비교 (결과값 -> 0, <0, >0)
    // (0: 두 문자열이 같다, <0: 첫 번째 문자열이 두 번째보다 사전순으로 앞에 있다, >0: 첫 번째 문자열이 두 번째보다 사전순으로 뒤에 있다)
}

// 생년월일 기준 비교 함수 (qsort에서 사용)
int compare_birth(const void* a, const void* b) {  //compare_name하고 같음
    struct phone_book* pa = (struct phone_book*)a;
    struct phone_book* pb = (struct phone_book*)b;
    return pa->birth - pb->birth; //이건 strcmp() 안 써도 된다. 이유: 문자열은 단순 뺄셈으로 크기 비교가 안 되니까 strcmp()로 비교하지만 이건 int타입 숫자니까 뺄셈으로 비교 가능하다.
}

int main() {
    int choice;
    struct phone_book list[100] = { 0 }; //phone_book 구조체 타입의 배열을 100개 선언. 즉, 학생 100명의 정보를 저장할 수 있는 구조체 배열. 0으로 초기화(쓰레기값 방지)

    while (1) {
        print_menu();
        scanf("%d", &choice);  //숫자 하나를 입력받아 choice에 저장. 이때 숫자를 입력하고 엔터를 치면 scanf는 숫자만 읽고 엔터(\n)는 입력 버퍼에 남겨둔다.
        // 엔터는 아직 버퍼에 남아있다. 예를 들어 다음 줄에서 문자열을 입력받고 싶을 때 다음 줄을 실행하지 않고 버퍼에 남아있는 엔터만 읽고 실행은 끝나버린다.
        getchar(); // 입력 버퍼 클리어 (위와 같은 문제 해결하기 위해 getchar() 사용한다. getchar();는 남은 엔터를 읽어서 없애는 역할을 한다.)

        switch (choice) {
        case 1:
            add(&list[qty]); //구조체 위치를 함수에 넘겨서 직접 수정 가능하게 함
            break;
        case 2:
            search(list, NAME); //전화번호부 배열 전체에서 이름으로 검색
            break;
        case 3:
            search(list, PHONE); //전화번호부 배열 전체에서 전화번호로 검색
            break;
        case 4:
            sort(list, NAME);
            break;
        case 5:
            sort(list, BIRTH);
            break;
        case 6:
            save(list); // save(list)는 list배열을 save() 함수에 전달해서, 배열 안의 qty만큼 등록된 정보를 파일로 저장하게 만드는 함수 호출
            break;
        case 7:
            load(list); // 저장된 파일에서 전화번호부 데이터를 읽어와서 list 배열에 다시 불러오는 함수 호출
            break;
        case 8:
            del(list); // 전화번호부에서 특정 사람을 삭제하기 위한 함수 호출
            break;
        case 9:
            return 0; // 9누르면 프로그램 종료된다.
        case 0:
            all(list); //전화번호부에 저장된 모든 사람의 정보를 출력하는 함수
            break;
        default:
            printf("잘못된 선택입니다.\n");
        }
        system("pause");
    }
    return 0;
}

void print_menu() {
    system("cls");
    printf("1. 전화번호 추가\n");
    printf("2. 이름 검색\n");
    printf("3. 전화번호 검색\n");
    printf("4. 이름순 정렬\n");
    printf("5. 생년월일순 정렬\n");
    printf("6. 전화번호부 저장하기\n");
    printf("7. 전화번호부 불러오기\n");
    printf("8. 전화번호 삭제\n");
    printf("9. 종료\n");
    printf("0. 전체 출력\n");
    printf("메뉴 선택: ");
}

void print_list(struct phone_book list) {
    printf("이름 : %-20s 전화번호 : %-15s 생년월일 : %d\n", list.name, list.phone, list.birth); //입력한 이름, 전화번호, 생년월일 출력
}

void add(struct phone_book* list) { // 추가
    if (qty == 100) { //전화번호부가 다 찼는지 확인
        printf("더 이상 추가할 수 없습니다.\n");
        return;
    }

    printf("이름(영어): ");
    fgets(list->name, sizeof(list->name), stdin); //이름 입력 받기. 표준 입력(stdin)에서 문자열을 최대 입력한 길이(list->name)만큼 읽어와서 구조체 포인터 list가 가리키는 name 배열에 저장
    list->name[strcspn(list->name, "\n")] = '\0'; // 개행 문자 제거(strcspn()으로 마지막에 따라오는 \n (엔터)을 널 문자 \0로 바꿔서 문자열 끝을 표시)

    if (strlen(list->name) == 0) { // 이름이 비었는지 확인(입력 안 하고 엔터만 치면 입력 취소로 간주하고 빠져나감)
        printf("전화번호 추가 취소\n");
        return;
    }

    printf("전화번호(xxx-xxxx-xxxx): "); //전화번호 입력 받고 \n 제거
    fgets(list->phone, sizeof(list->phone), stdin);
    list->phone[strcspn(list->phone, "\n")] = '\0';

    printf("생년월일(예: 20030228): "); //생년월일 입력
    scanf("%d", &list->birth);
    getchar(); // 버퍼 클리어(getchar()로 엔터키(\n) 를 제거해서 다음 입력에 방해 안 되도록 버퍼를 비워줌)

    print_list(*list); //방금 입력한 정보 출력
    qty++; //사람 한 명 추가했으니까 총 개수 +1 해줌
}

void search(struct phone_book list[], int kind) { // 검색
    int i;
    char n_tmp[20]; // 검색할 이름 또는 전화번호를 저장할 변수

    if (kind == NAME) printf("검색할 이름: ");
    else if (kind == PHONE) printf("검색할 전화번호: ");

    fgets(n_tmp, sizeof(n_tmp), stdin); //입력 받기, 표준 입력에서 문자열을 최대 입력한 길이(배열의 길이)만큼 읽어와서 n_tmp배열에 저장
    n_tmp[strcspn(n_tmp, "\n")] = '\0'; //개행 문자 제거

    for (i = 0; i < qty; i++) { // 등록된 학생 수만큼 읽기
        if ((kind == NAME && strcmp(list[i].name, n_tmp) == 0) || //기준이 NAME이고 현재 i번째 사람의 이름과 사용자가 입력한 이름(n_tmp)을 비교(strcmp())해서 같다면
            (kind == PHONE && strcmp(list[i].phone, n_tmp) == 0)) { //기준이 PHONE이고 현재 i번째 사람의 전화번호와 사용자가 입력한 전화번호(n_tmp)를 비교해서 같다면
            print_list(list[i]); // 위 조건 중 하나라도 만족하면 해당 정보를 출력
        }
    }
}

void sort(struct phone_book list[], int kind) {
    if (qty == 0) {
        printf("정렬할 데이터가 없습니다.\n");
        return;
    }

    // qsort()를 사용하여 정렬 수행. 
    if (kind == NAME) {
        qsort(list, qty, sizeof(struct phone_book), compare_name); // 이름 기준 정렬
    }
    else if (kind == BIRTH) {
        qsort(list, qty, sizeof(struct phone_book), compare_birth); // 생년월일 기준 정렬
    }
    // "이 함수(compare_name, birth)를 사용해서 정렬 기준을 정해주세요!"라고 qsort()에게 알려주는 거다.
    // 그래서 qsort가 이렇게 내부에서 호출한다. -> compare_name(&list[i], &list[j])

    for (int i = 0; i < qty; i++) print_list(list[i]);
}

void save(struct phone_book list[]) {
    char fname[20]; //파일 이름을 입력받을 배열
    FILE* fp; //파일 포인터

    printf("저장할 파일 이름: ");
    fgets(fname, sizeof(fname), stdin); //파일 이름 입력받기. 표준입력에서 문자열을 최대 입력한 길이만큼 읽어와서 fname배열에 저장
    fname[strcspn(fname, "\n")] = '\0'; //개행 문자 제거

    fp = fopen(fname, "w"); //쓰기 모드로 파일 열기
    if (fp == NULL) {  // 파일 열기에 성공하면 fp에는 유효한 주소가 저장됨. 실패하면 NULL이다.
        printf("파일 열기 실패\n");
        return; // 함수 종료
    }

    // 등록된 qty만큼 반복하면서 파일에 출력
    for (int i = 0; i < qty; i++) {
        fprintf(fp, "%s %s %d\n", list[i].name, list[i].phone, list[i].birth);
    }
    fclose(fp); //파일 닫기
}

void load(struct phone_book list[]) {
    char fname[20]; // 파일 이름 저장할 문자열
    FILE* fp; // 파일 포인터(파일을 열고 다룰 때 사용)

    printf("불러올 파일 이름: "); //파일 이름 입력
    fgets(fname, sizeof(fname), stdin); // 표준 입력(stdin)에서 파일 이름을 읽어 fname에 저장
    fname[strcspn(fname, "\n")] = '\0'; // 입력한 문자열 끝에 있는 개행 문자('\n')를 제거

    fp = fopen(fname, "r"); // 해당 이름의 파일을 읽기 모드("r")로 연다
    if (fp == NULL) { // 파일 열기에 실패했을 경우
        printf("파일 열기 실패\n");
        return; // 함수 종료
    }

    qty = 0; // 배열에 새로 데이터를 덮어쓰기 위해 등록된 수를 0으로 초기화
    // 파일에서 한 줄씩 정보를 읽어와서 배열 list[qty]에 저장
    // fscanf는 한 줄에서 문자열 2개(name, phone)와 정수 1개(birth)를 읽음
    while (fscanf(fp, "%s %s %d", list[qty].name, list[qty].phone, &list[qty].birth) == 3) {
        qty++; // 한 사람 정보를 성공적으로 읽었으니 등록 수 증가
    }
    fclose(fp); // 파일 닫기 (사용이 끝났으면 꼭 닫아야 함)
}

void del(struct phone_book list[]) {
    int i, j;
    char n_tmp[20];

    printf("삭제할 이름: ");
    fgets(n_tmp, sizeof(n_tmp), stdin); //삭제할 이름 입력받기
    n_tmp[strcspn(n_tmp, "\n")] = '\0'; // 개행 문자 제거

    for (i = 0; i < qty; i++) { // 등록된 qty만큼 반복
        if (strcmp(list[i].name, n_tmp) == 0) { //배열 내 이름과 입력한 이름 비교
            // 삭제할 데이터를 찾으면 뒤에 있는 데이터들을 앞으로 땡김
            for (j = i; j < qty - 1; j++) list[j] = list[j + 1]; //삭제된 위치 이후 데이터들 한 칸씩 앞으로 당기기
            qty--; // 전체 수 하나 감소
            memset(&list[qty], 0, sizeof(struct phone_book)); // 마지막 남은 찌꺼기 데이터 초기화
            break; // 하나만 삭제하고 종료
        }
    }
}

void all(struct phone_book list[]) {
    for (int i = 0; i < qty; i++) print_list(list[i]); //qty만큼 반복 (등록된 사람 수만큼) -> 각 구조체 요소(연락처 정보)를 출력
}
