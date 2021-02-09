#pragma once
#include "battle.h"
#define STR_MAX 100


#define 이름길이 100
int get_number(char *str){
    int size;
    printf("%s: ",str);
    scanf("%d", &size);
    return size;
}
 
int makePlayers(Player **p_addr){
    int size;
    size=get_number("플레이어가 몇명인가요?");
    *p_addr = (Player *)malloc(sizeof(Player)*size);
    if(*p_addr==NULL){
        printf("할당 실패 \n");
        return -1;
    }
    return 1;
}
 
int *makeWeapons(Weapon **w_addr){
    int size;
    size=get_number("무기는 몇 개인가요?;");
    *w_addr=(Weapon *)malloc(sizeof(Weapon) *size);
}
 
int makeName(char **name_addr){
    *name_addr = (char *)malloc(sizeof(char)*이름길이);
}
 
void setPlayer(Player *p){
    int size;
    printf("==set player==\n");
    makeName(&p->name);
    printf("이름 : ");
    scanf("%s",p->name);
    p->name = (char *)realloc(p->name, strlen(p->name)+1);
    p->power = get_number("공격력");
	p->defensivePower = get_number("방어력");
    p->hp = get_number("체력");
 
    makeWeapons(&(p->w));
}
 
void setWeapon(Weapon *p){
 
    printf("==set weapon==\n");
    makeName(&p->name);
    printf("무기이름 : ");
    scanf("%s",p->name);
    p->name=(char *)realloc(p->name, strlen(p->name)+1);
    p->power = get_number("능력치");
}
 
void showPlayer(Player *p,Weapon *w, int playerNum, int weaponNum){
    int i, k, j, fp=0;
	for (i=0; i<playerNum; i++){
		printf("\n이름 : %s\n", p[i].name);
		printf("능력치 : %d\n", p[i].power);
		printf("방어력 : %d\n", p[i].defensivePower);
		printf("체력 : %d\n\n", p[i].hp);
		for (j=0; j<weaponNum; j++){
			printf("무기 : %s (능력치 %d)\n", p[i].w->name, p[i].w->power);
		}
		printf("=============================================\n");
	}
}
 
void attact(Player hunter, Player *target, int n){
	int power = hunter.power + hunter.w->power;
	printf("!! %d차 공격 !! '%s' --> '%s' \n", n, hunter.name, target->name);
	
	if ((rand()%(MAX-target->defensivePower))==1)	//방어력이 3이면, 1/7 확률로 공격 막음.
		printf("'%s'가 방어에 성공했습니다.\n", target->name);
	else{
		printf("'%s'가 방어에 실패해 체력이 깎였습니다.\n", target->name);
		target->hp-=power;
	}
}

void showPlayersHp(Player p1, Player p2){
	int i;
	printf("\n[%s] : ", p1.name);
	for (i=0; i<p1.hp; i+=2) printf("■");
	if (p1.hp%2 != 0) printf("□");
	printf("(%d)\n", p1.hp);

	printf("[%s] : ", p2.name);
	for (i=0; i<p2.hp; i+=2) printf("■");
	if (p2.hp%2 != 0) printf("□");
	printf("(%d)\n", p2.hp);

	printf("\n---------------------------------------------\n");
}