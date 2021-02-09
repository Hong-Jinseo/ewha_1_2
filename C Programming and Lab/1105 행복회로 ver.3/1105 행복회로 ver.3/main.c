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

void 과제하기(int status[]){	
	//피로도 +20, 행복도 -10
	status[0]-=10;
	status[2]+=20;
	printf("피로도가 20 증가하고, 행복도가 10 감소했습니다.\n");
}
void 먹기(int status[]){
	//포만감 +30, 행복도 +15
	status[0] += 10;
	status[1] += 20;
	printf("포만감이 30 증가하고, 행복도가 15 증가했습니다.\n");
}
void 수업듣기(int status[]){
	//포만감 -10, 피로도 +20, 행복도 -15
	status[0] -= 15;
	status[1] -= 10;
	status[2] += 20;
	printf("피로도가 20 증가하고, 행복도가 15 감소하고, 포만감이 10 감소했습니다.\n");
}
void 잠자기(int status[]){
	//피로도 -20, 행복도 +20
	status[0] += 20;
	status[2] -= 20;
	printf("피로도가 20 감소하고, 행복도가 20 감소했습니다.\n");
}
void 집에_가기(int status[]){
	//행복감 +20, 피로도 +10
	status[0] += 20;
	status[2] += 10;
	printf("피로도가 10 증가하고, 행복도가 20 증가했습니다.\n");
}

int main(void)
{
	int act;
	int status[3] = {50,50,50}; //행복도, 포만감, 피로도

	show_menu();
	
	printf("========나의 상태========\n");
	printf("행복도 : %d\n",status[0]);
	printf("포만감 : %d\n",status[1]);
	printf("피로도 : %d\n",status[2]);
	printf("========================\n\n");

	while(1)
	{

		printf("원하는 활동 번호를 입력하세요(숫자만) : ");
		scanf("%d",&act);

		if (act==1) 과제하기(status);
		if (act==2) 먹기(status);
		if (act==3) 수업듣기(status);
		if (act==4) 잠자기(status);
		if (act==5) 집에_가기(status);


		printf("\n\n================나의 상태================\n");
		printf("              행복도 : %d\n",status[0]);
		printf("              포만감 : %d\n",status[1]);
		printf("              피로도 : %d\n",status[2]);
		if (status[0]<=min_warning) printf("[주의]행복도가 10 미만으로 떨어졌습니다. 우울증에 걸릴지도 몰라요!\n");
		if (status[2]>=max_warning) printf("[주의]피로도가 90을 초과했습니다. 힘들어서 쓰러질지도 몰라요!\n");
		if (status[1]<=min_warning) printf("[주의]포만감이 10 미만으로 떨어졌습니다. 배가 고파서 쓰러질지도 몰라요!\n");
		if (status[1]<=min_warning) printf("[주의]포만감이 90을 초과했습니다. 배가 터질지도 몰라요!\n");
		
		printf("========================================\n\n");

		if ((status[0]<=0) || (status[2]>=100) || (status[1]<=0) || (status[1]>=100)) break;

		show_menu();
	
	}

	if (status[0]<=0) printf("행복도가 너무 낮아져 우울증에 걸렸습니다.\n\n"); 
	if (status[2]>=100) printf("너무 피곤해서 움직일 수 없습니다.\n\n");
	if (status[1]<=0) printf("배가 너무 고파서 쓰러졌습니다.\n\n"); 
	if (status[1]>=100) printf("배가 너무 불러서 움직일 수 없습니다.\n\n");
		
}