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
		printf("�Ҵ� ����\n");
		return -1;
	}
	return 1;
}

void enter_information2(Player *p, int n){
	int num_weapon, i, j;
	printf("\n");
	for (j=0; j<n; j++)
	{
		printf("%d�� �÷��̾� ������ �Է��ϼ���\n",j+1);
        printf("<�÷��̾� ���� �Է�>\n");
		p[j].name = (char *)malloc(sizeof(char)*100);
		memset(p[j].name, 0x0, sizeof(char)*100);
		printf("�̸� �Է�:"); scanf("%s",p[j].name);
		p[j].name = (char *)realloc(p[j].name, strlen(p[j].name)+1);

		p[j].power = get_number("Player power :");
		p[j].hp = get_number("Player hp :");

		num_weapon = get_number("���� ���� �Է� :");
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
	printf("<���� ���� �Է�>\n");
	w->name=(char*)calloc(sizeof(char),100);
    printf("���� �̸�:");scanf("%s",w->name);
    w->name=(char*)realloc(w->name,strlen(w->name)+1);
    w->power=get_number("Weapon power");
}

void show_start(){
    printf("\n");
    printf("=============================================\n");
    printf("             Enter Ű�� ��������!            \n");
    printf("=============================================\n");
    getchar();
    getchar();
}

void attack(Player hunter,Player *target){
    //���� ������ ���ݷ� ���ϱ�
    int num,i;
    int hap=0,power=0;
    num=_msize(hunter.w)/sizeof(Weapon);
    for(i=0;i<num;i++) hap+=hunter.w[i].power;
 
    power=hunter.power+hap;
    printf("%s �÷��̾ %s �÷��̾ �����մϴ�\n",hunter.name,target->name);
    target->hp-=power;
}

void show_information2(Player *p,int n){ //n�� �迭�� ����
    int i,j,num_weapon;
    printf("\n");
    for(j=0;j<n;j++){
        printf("�̸�: %s, power: %d, hp: %d\n",p[j].name,p[j].power,p[j].hp);
        num_weapon=_msize(p[j].w)/sizeof(Weapon);
        printf("��������\n");
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
            printf("�й��ڴ� %s�Դϴ�\n",p[i].name);
            break;
        }
    }
}
