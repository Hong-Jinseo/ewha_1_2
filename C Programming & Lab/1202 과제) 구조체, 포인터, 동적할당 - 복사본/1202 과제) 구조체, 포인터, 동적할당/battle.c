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
    size=get_number("����� �� ���ΰ���?;");
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
    int i, k, j, fp=0;
	for (i=0; i<playerNum; i++){
		printf("\n�̸� : %s\n", p[i].name);
		printf("�ɷ�ġ : %d\n", p[i].power);
		printf("���� : %d\n", p[i].defensivePower);
		printf("ü�� : %d\n\n", p[i].hp);
		for (j=0; j<weaponNum; j++){
			printf("���� : %s (�ɷ�ġ %d)\n", p[i].w->name, p[i].w->power);
		}
		printf("=============================================\n");
	}
}
 
void attact(Player hunter, Player *target, int n){
	int power = hunter.power + hunter.w->power;
	printf("!! %d�� ���� !! '%s' --> '%s' \n", n, hunter.name, target->name);
	
	if ((rand()%(MAX-target->defensivePower))==1)	//������ 3�̸�, 1/7 Ȯ���� ���� ����.
		printf("'%s'�� �� �����߽��ϴ�.\n", target->name);
	else{
		printf("'%s'�� �� ������ ü���� �𿴽��ϴ�.\n", target->name);
		target->hp-=power;
	}
}

void showPlayersHp(Player p1, Player p2){
	int i;
	printf("\n[%s] : ", p1.name);
	for (i=0; i<p1.hp; i+=2) printf("��");
	if (p1.hp%2 != 0) printf("��");
	printf("(%d)\n", p1.hp);

	printf("[%s] : ", p2.name);
	for (i=0; i<p2.hp; i+=2) printf("��");
	if (p2.hp%2 != 0) printf("��");
	printf("(%d)\n", p2.hp);

	printf("\n---------------------------------------------\n");
}