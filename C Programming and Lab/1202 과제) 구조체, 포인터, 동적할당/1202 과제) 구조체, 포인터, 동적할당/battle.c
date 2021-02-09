#pragma once
#include "battle.h"
#define STR_MAX 100


#define �̸����� 100
int get_number(char *str){
    int size;
    printf("%s: ",str);
    scanf("%d", &size);
    return size;
}
int makePlayers(Player **p_addr){
    int size;
    size=get_number("�÷��̾ ����ΰ���?");
    *p_addr = (Player *)malloc(sizeof(Player)*size);
    if(*p_addr==NULL){
        printf("�Ҵ� ���� \n");
        return -1;
    }
    return 1;
}
int *makeWeapons(Weapon **w_addr){
    int size;
    size=get_number("����� �� ���ΰ���?");
    *w_addr=(Weapon *)malloc(sizeof(Weapon) *size);
}
int makeName(char **name_addr){
    *name_addr = (char *)malloc(sizeof(char)*�̸�����);
}
void setPlayer(Player *p){
    int size;
    printf("==set player==\n");
    makeName(&p->name);
    printf("�̸� : ");
    scanf("%s",p->name);
    p->name = (char *)realloc(p->name, strlen(p->name)+1);
    p->power = get_number("���ݷ�");
	p->defensivePower = get_number("����");
    p->hp = get_number("ü��");
 
    makeWeapons(&(p->w));
}
void setWeapon(Weapon *p){
 
    printf("==set weapon==\n");
    makeName(&p->name);
    printf("�����̸� : ");
    scanf("%s",p->name);
    p->name=(char *)realloc(p->name, strlen(p->name)+1);
    p->power = get_number("�ɷ�ġ");
}
void showPlayer(Player *p,Weapon *w, int playerNum, int weaponNum){
    int i, j, power_sum = 0;
	printf("\n=============================================\n");
	for (i=0; i<playerNum; i++){
		printf("\n�̸� : %s\n", p[i].name);
		printf("�ɷ�ġ : %d , ���� : %d , ü�� : %d\n", p[i].power, p[i].defensivePower, p[i].hp);
		power_sum+=p[i].power;
		weaponNum = _msize(p[i].w) / sizeof(Weapon);
		printf("******* �������� ******** \n");
		for (j=0; j<weaponNum; j++){
			printf("%s (�ɷ�ġ %d)\n", p[i].w[j].name, p[i].w[j].power);
			power_sum += p[i].w[j].power;
		}
		printf("�� �ɷ�ġ : %d\n", power_sum);
		power_sum = 0;
		printf("\n=============================================\n");
	}
	printf("\n=============================================\n");
}
void attack(Player hunter, Player *target){
	int power = hunter.power;
	int i=0;

	for (i=0; i<(_msize(hunter.w)/sizeof(Weapon); i++){
		power_sum += hunter.w[i].power;
	}

	printf("!! ���� !! '%s' --> '%s' \n", hunter.name, target->name);
	
	if ((rand()%(MAX-target->defensivePower))==1)	//������ 3�̸�, 1/7 Ȯ���� ���� ����.
		printf("'%s'�� �� �����߽��ϴ�.\n", target->name);
	else{
		printf("'%s'�� �� ������ ü���� �𿴽��ϴ�.\n", target->name);
		target->hp -= power_sum;
	}
}
void showPlayersHp(Player *p, int playerNum){
	int i=0;
	printf("\n[%s] : ", p->name);
	for (i=0; i<p[i].hp; i+=2) printf("��");
	if (p[1].hp%2 != 0) printf("��");
	printf("(%d)\n", p[1].hp);
}
//���� ���� ���Ŀ� �����ִ� Hp

void selecePlayer(int playerNum){
	int hunter, target;
	srand((unsigned)time(NULL));
	hunter = rand()%playerNum;
	target = rand()%playerNum;
}