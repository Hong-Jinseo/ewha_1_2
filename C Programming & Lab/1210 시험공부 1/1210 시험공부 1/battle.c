#pragma once
#include "battle.h"
#define STR_MAX 100

int get_number(char *str)
{
	int n;
	printf("%s :",str); scanf("%d",&n);
	return n;
}

int mallocPlayer(Player **par, int n)
{
	*par = (Player *)malloc(sizeof(Player)*n);
	if (*par)==NULL{
		printf("할당 실패\n");
		return -1;
	}
	return 1;
}

void enter_information2(Player *p, int n){
	int num_weapon, i, j;
	printf("\n");
	for (j=0; j<n; j++)
	{
		printf("%d번 플레이어 정보를 입력하세요\n",j+1);
        printf("<플레이어 정보 입력>\n");
		p[j].name = (char *)malloc(sizeof(char)*100);
		memset(p[j].name, 0x0, sizeof(char)*100);
		printf("이름 입력:"); scanf("%s",p[j].name);
		p[j].name = (char *)realloc(p[j].name, strlen(p[j].name)+1);

		p[j].power = get_number("Player power :");
		p[j].hp = get_number("Player hp :");

		num_weapon = get_number("무기 개수 입력 :");
		p[j].w = (Weapon *)malloc(sizeof(Weapon)*num_weapon);
		for (i=0; i<num_weapon; i++)
		{
			enter_weapon(&p[j].w[i]);
		}
		printf("\n");
	}
}


void enter_weapon(Weapon *w)
{
	printf("<무기 정보 입력>\n");
	w->name=(char*)calloc(sizeof(char),100);
    printf("무기 이름:");scanf("%s",w->name);
    w->name=(char*)realloc(w->name,strlen(w->name)+1);
    w->power=get_number("Weapon power");
}

void show_start(){
    printf("\n");
    printf("=============================================\n");
    printf("             Enter 키를 누르세요!            \n");
    printf("=============================================\n");
    getchar();
    getchar();
}

void attack(Player hunter,Player *target){
    //보유 무기의 공격력 더하기
    int num,i;
    int hap=0,power=0;
    num=_msize(hunter.w)/sizeof(Weapon);
    for(i=0;i<num;i++) hap+=hunter.w[i].power;
 
    power=hunter.power+hap;
    printf("%s 플레이어가 %s 플레이어를 공격합니다\n",hunter.name,target->name);
    target->hp-=power;
}

void show_information2(Player *p,int n){ //n은 배열의 개수
    int i,j,num_weapon;
    printf("\n");
    for(j=0;j<n;j++){
        printf("이름: %s, power: %d, hp: %d\n",p[j].name,p[j].power,p[j].hp);
        num_weapon=_msize(p[j].w)/sizeof(Weapon);
        printf("보유무기\n");
        for(i=0;i<num_weapon;i++){
            printf("       %s    %d\n",p[j].w[i].name,p[j].w[i].power);
        }
        printf("\n");
    }
}

int find_min(Player *p,int n){
    int i,min;
    min=p[0].hp;
    for(i=0;i<n-1;i++){
        if(p[i].hp>p[i+1].hp) min=p[i+1].hp;
    }
    return min;
}
 
void find_loser(Player* p,int n){
    int i;
    for(i=0;i<n;i++){
        if(p[i].hp<=0){
            printf("패배자는 %s입니다\n",p[i].name);
            break;
        }
    }
}
