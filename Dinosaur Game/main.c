#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include <stdbool.h>
#define DINO_BOTTOM_Y 12 //공룡의 시작 Y좌표 (Y축은 높이가 커질수록 아래로 감)
#define TREE_BOTTOM_Y 20 //나무의 시작 Y좌표
#define TREE_BOTTOM_X 45 //나무의 시작 X좌표

//콘솔 창의 크기와 제목을 지정하는 함수
void SetConsoleView()
{
	system("mode con:cols=100 lines=25");
	system("title Google Dinosaurs. By gayeong.");
}

//커서의 위치를 x, y로 이동하는 함수
void GotoXY(int x, int y)
{
	COORD Pos; //좌표 정보를 담을 Pos 변수 선언
	Pos.X = 2 * x; //x좌표에 2를 곱함 :일반적인 영문자나 숫자는 가로 폭이 1칸이지만, 한글이나 특수문자(■, ★ 등)는 가로 폭이 2칸을 차지해서
	Pos.Y = y; //y좌표 설정
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); //콘솔 핸들을 가져와서 Pos 위치로 커서를 이동
	// COORD : 콘솔의 좌표 $(x, y)$를 저장하는 바구니
    // SetConsoleCursorPosition: 커서의 위치를 이동시키는 함수
	// GetStdHandle(STD_OUTPUT_HANDLE): 현재 실행 중인 콘솔 창의 '핸들'(제어권)을 가져오는 함수입니다. "내가 지금 보고 있는 이 창에 명령을 내리겠다"는 선언
}

//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int GetKeyDown()
{
	if (_kbhit() != 0) //키보드가 눌려 있는 상태인지 체크 - 눌려 있으면 0이 아닌 값을 반환
	{
		return _getch(); //눌린 키가 무엇인지 그 값 반환
	}
	return 0; //아무 키도 눌리지 않았으면 0 반환 -> 게임 멈추지 않고 계속 진행
}

//공룡을 그리는 함수 -> 공룡이 달리는 애니메이션 효과를 위해 다리 모양을 번갈아 출력함
void DrawDino(int dinoY)
{
	GotoXY(0, dinoY);
	static bool legFlag = true;
	printf("        $$$$$$$ \n");
	printf("       $$ $$$$$$\n");
	printf("       $$$$$$$$$\n");
	printf("$      $$$      \n");
	printf("$$     $$$$$$$  \n");
	printf("$$$   $$$$$     \n");
	printf(" $$  $$$$$$$$$$ \n");
	printf(" $$$$$$$$$$$    \n");
	printf("  $$$$$$$$$$    \n");
	printf("    $$$$$$$$    \n");
	printf("     $$$$$$     \n");
	if (legFlag)
	{
		printf("     $    $$$    \n");
		printf("     $$          ");
		legFlag = false;
	}
	else
	{
		printf("     $$$  $     \n");
		printf("          $$    ");
		legFlag = true;
	}
}

//나무를 그리는 함수
void DrawTree(int treeX)
{
	GotoXY(treeX, TREE_BOTTOM_Y); //커서를 나무의 x좌표와 y좌표로 이동
	printf("$$$$");
	GotoXY(treeX, TREE_BOTTOM_Y + 1);
	printf(" $$ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 2);
	printf(" $$ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 3);
	printf(" $$ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 4);
	printf(" $$ ");
}

//충돌 했을때 게임오버 그려줌
void DrawGameOver(const int score)
{
	system("cls"); //화면 깨끗하게 지우기
	int x = 18;
	int y = 8;
	GotoXY(x, y);
	printf("===========================");
	GotoXY(x, y + 1);
	printf("======G A M E O V E R======");
	GotoXY(x, y + 2);
	printf("===========================");
	GotoXY(x, y + 5);
	printf("SCORE : %d", score);

	printf("\n\n\n\n\n\n\n\n\n");
	system("pause"); //프로그램을 잠시 멈추고 "계속하려면 아무 키나 누르십시오..."라는 메시지를 출력하며 사용자의 입력을 기다리게 하는 명령어
}

//충돌했으면 true, 아니면 false
bool isCollision(const int treeX, const int dinoY)
{
	//트리의 X가 공룡의 몸체쪽에 있을때,
	//공룡의 높이가 충분하지 않다면 충돌로 처리
	GotoXY(0, 0); //화면의 맨 왼쪽 위 구석$(0, 0)$으로 커서를 이동
	printf("treeX : %d, dinoY : %d", treeX, dinoY); //그 자리에서 현재 나무의 X 좌표와 공룡의 Y 좌표를 출력
	if (treeX <= 8 && treeX >= 4 && dinoY > 8) //나무가 공룡의 몸통 위치(가로 범위 4~8)를 지날 때 && 공룡이 충분히 높이 점프하지 않았을 때(발의 높이가 8보다 클 때
	{
		return true;
	}
	return false;
}

int main()
{
	SetConsoleView();

	while (true)		//게임 루프
	{
		//게임 시작시 초기화
		bool isJumping = false; //캐릭터가 점프 중인가? false = 아니오
		bool isBottom = true; //캐릭터가 바닥에 있는가? true = 예
		const int gravity = 3; //중력값 (점프 속도 및 낙하 속도), 값이 커지면 금방 떨어진다.

		int dinoY = DINO_BOTTOM_Y; 
		int treeX = TREE_BOTTOM_X;

		int score = 0;
		clock_t start, curr;	//점수 변수 초기화(게임이 시작된 시간(start)과 현재 시간(curr)을 기억)
		start = clock();		//시작시간 초기화

		while (true)	//한 판에 대한 루프
		{
			//충돌체크 트리의 x값과 공룡의 y값으로 판단
			if (isCollision(treeX, dinoY))
				break;

			//z키가 눌렸고, 바닥이 아닐때 점프
			if (GetKeyDown() == 'z' && isBottom)
			{
				isJumping = true; //점프 상태로 변경
				isBottom = false; //바닥이 아님
			}

			//점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가.
			if (isJumping)
			{
				dinoY -= gravity; //Y가 작아질수록 위로 감(즉, 점프)
			}
			else
			{
				dinoY += gravity; //Y가 커질수록 아래로 감(즉, 낙하)
			}

			//Y가 계속해서 증가하는걸 막기위해 바닥을 지정.
			if (dinoY >= DINO_BOTTOM_Y)
			{
				dinoY = DINO_BOTTOM_Y;
				isBottom = true;
			}

			//나무가 왼쪽으로 (x음수) 가도록하고
			//나무의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.
			treeX -= 2;
			if (treeX <= 0)
			{
				treeX = TREE_BOTTOM_X; 
			}

			//점프의 맨위를 찍으면 점프가 끝난 상황.
			if (dinoY <= 3)
			{
				isJumping = false;
			}

			DrawDino(dinoY);		//draw dino
			DrawTree(treeX);		//draw Tree

			//
			curr = clock();			//현재시간 받아오기
			if (((curr - start) / CLOCKS_PER_SEC) >= 1)	//1초가 넘었을 때
			{
				score++;	//스코어 UP
				start = clock();	//시작시간 초기화 -> 처음으로 돌아감
			}
			Sleep(60); 
			system("cls");	//clear

			// 점수출력을 1초마다 해주는것이 아니라 항상 출력해주면서, 1초가 지났을때 ++ 해줍니다.
			GotoXY(22, 0);	//커서를 가운데 위쪽으로 옮긴다. 콘솔창이 cols=100이니까 2*x이므로 22정도 넣어줌
			printf("Score : %d ", score);	//점수 출력해줌.
		}

		//게임 오버 메뉴
		DrawGameOver(score);
	}
	return 0;
}
