#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dataType.h"
#include "battle.h"
#define MAX 10

void show_Player(Player p){
	printf("\n�̸� : %s\n", p.name);
	printf("���� : %s (�ɷ�ġ %d)\n", p.w->name, p.w->power);	//�����͸� �����ϴ� ��� : -> or (*w) ���
	printf("�ɷ�ġ : %d\n", p.power);
	printf("���� : %d\n", p.defensivePower);
	printf("ü�� : %d\n\n", p.hp);
	printf("=============================================\n");
}
/*
void defense(Player *target, int power){
	if ((rand()%(10-target->defensivePower))==1)	//������ 3�̸�, 1/7 Ȯ���� ���� ����.
		printf("'%s'�� �� �����߽��ϴ�.\n", target->name);
	else{
		printf("'%s'�� �� ������ ü���� �𿴽��ϴ�.\n", target->name);
		target->hp-=power;
	}
}
*/

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