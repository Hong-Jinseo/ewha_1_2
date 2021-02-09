//나의 "행복회로" 만들기
#include <stdio.h>
#define max_warning 90
#define min_warning 10

void show_menu()
{	
	printf("~~~~#~~~~#~~~~#~~~~\n");
	printf("1. 과제하기\n");
	printf("2. 먹기\n");
	printf("3. 잠자기\n");
	printf("4. 집에 가기\n");
	printf("5. 유튜브 보기\n");
	printf("~~~~#~~~~#~~~~#~~~~\n\n");}

void 과제하기(int *tired, int*happy){	
	//피로도 +20, 행복도 -10
	*tired+=20;
	*happy-=10;
	printf("피로도가 20 증가하고, 행복도가 10 감소했습니다.\n");
}
void 먹기(int *happy, int *full){
	//포만감 +30, 행복도 +15
	*full += 30;
	*happy -= 10;
	printf("포만감이 30 증가하고, 행복도가 15 증가했습니다.\n");
}
void 수업듣기(int *full, int* tired, int *happy){
	//포만감 -10, 피로도 +20, 행복도 -15
	*full -= 10;
	*tired += 20;
	*happy -=15;
	printf("피로도가 20 증가하고, 행복도가 15 감소하고, 포만감이 10 감소했습니다.\n");
}
void 잠자기(int *tired, int *happy){
	//피로도 -20, 행복도 +20
	*tired -= 20;
	*happy += 20;
	printf("피로도가 20 감소하고, 행복도가 20 감소했습니다.\n");
}
void 집에_가기(int *happy, int *tired){
	//행복감 +20, 피로도 +10
	*happy +=20;
	*tired +=10;
	printf("피로도가 10 증가하고, 행복도가 20 증가했습니다.\n");
}

int main(void)
{
	int act;
	int happy=50;
	int full=50;
	int tired=50;

	show_menu();
	
	printf("========나의 상태========\n");
	printf("행복도 : %d\n",happy);
	printf("포만감 : %d\n",full);
	printf("피로도 : %d\n",tired);
	printf("========================\n\n");

	while(1)
	{

		printf("원하는 활동 번호를 입력하세요(숫자만) : ");
		scanf("%d",&act);

		if (act==1) 과제하기(&tired, &happy);
		if (act==2) 먹기(&happy, &full);
		if (act==3) 수업듣기(&full, &tired, &happy);
		if (act==4) 잠자기(&tired, &happy);
		if (act==5) 집에_가기(&happy,&tired);


		printf("\n\n================나의 상태================\n");
		printf("              행복도 : %d\n",happy);
		printf("              포만감 : %d\n",full);
		printf("              피로도 : %d\n",tired);
		if (happy<=min_warning) printf("[주의]행복도가 10 미만으로 떨어졌습니다. 우울증에 걸릴지도 몰라요!\n");
		if (tired>=max_warning) printf("[주의]피로도가 90을 초과했습니다. 힘들어서 쓰러질지도 몰라요!\n");
		if (full<=min_warning) printf("[주의]포만감이 10 미만으로 떨어졌습니다. 배가 고파서 쓰러질지도 몰라요!\n");
		if (full<=min_warning) printf("[주의]포만감이 90을 초과했습니다. 배가 터질지도 몰라요!\n");
		
		printf("========================================\n\n");

		if ((happy<=0) || (tired>=100) || (full<=0) || (full>=100)) break;

		show_menu();
	
	}

	if (happy<=0) printf("행복도가 너무 낮아져 우울증에 걸렸습니다.\n\n"); 
	if (tired>=100) printf("너무 피곤해서 움직일 수 없습니다.\n\n");
	if (full<=0) printf("배가 너무 고파서 쓰러졌습니다.\n\n"); 
	if (full>=100) printf("배가 너무 불러서 움직일 수 없습니다.\n\n");
		
}