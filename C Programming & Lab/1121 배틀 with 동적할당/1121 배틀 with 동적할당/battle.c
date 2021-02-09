#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dataType.h"
#include "battle.h"
#define MAX 10

void show_Player(Player p){
	printf("\n이름 : %s\n", p.name);
	printf("무기 : %s (능력치 %d)\n", p.w->name, p.w->power);	//포인터를 참조하는 방식 : -> or (*w) 사용
	printf("능력치 : %d\n", p.power);
	printf("방어력 : %d\n", p.defensivePower);
	printf("체력 : %d\n\n", p.hp);
	printf("=============================================\n");
}
/*
void defense(Player *target, int power){
	if ((rand()%(10-target->defensivePower))==1)	//방어력이 3이면, 1/7 확률로 공격 막음.
		printf("'%s'가 방어에 성공했습니다.\n", target->name);
	else{
		printf("'%s'가 방어에 실패해 체력이 깎였습니다.\n", target->name);
		target->hp-=power;
	}
}
*/

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