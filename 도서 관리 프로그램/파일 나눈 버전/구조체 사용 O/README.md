# 📚 도서 관리 프로그램 (구조체 + 멀티 파일 버전)

C 언어 구조체와 여러 소스 파일 분리를 연습하기 위해 만든 **콘솔 기반 도서 관리 프로그램**입니다.  
책 정보를 `Book` 구조체 배열로 관리하고, 기능별로 파일을 분리했습니다.

---

## ✨ 주요 기능

- 책 등록  
  - 책 이름, 저자, 출판사 입력  
- 책 검색  
  - 제목 / 지은이 / 출판사 기준 선택  
  - 부분 문자열 포함 검색 (예: `one` → `Everyone` 에서 검색됨)
- 책 대출 / 반납  
  - 책 번호로 대출 / 반납 처리  
  - 잘못된 번호 / 이미 대출·반납된 경우 안내 메시지 출력  

---

## 📁 파일 구조

```text
도서 관리 프로그램
└── 파일 나눈 버전 (구조체)
    ├── 소스 파일
    │   ├── BookManageProgramStruct_file.c        // main 함수
    │   ├── BookManageProgramStructFunc_file.c    // 도서 관리 기능 (추가/검색/대출/반납 등)
    │   └── BookManageProgramStructStr_file.c     // 문자열 비교 함수 compare
    │
    └── 헤더 파일
        ├── BookManageProgramStructFunc_file.h    // Book 구조체 정의 + 도서 관리 함수 선언
        └── BookManageProgramStructStr_file.h     // compare 함수 선언
