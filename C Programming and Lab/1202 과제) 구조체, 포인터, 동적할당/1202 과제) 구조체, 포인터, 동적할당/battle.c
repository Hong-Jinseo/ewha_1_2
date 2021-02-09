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
    size=get_number("무기는 몇 개인가요?");
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
    int i, j, power_sum = 0;
	printf("\n=============================================\n");
	for (i=0; i<playerNum; i++){
		printf("\n이름 : %s\n", p[i].name);
		printf("능력치 : %d , 방어력 : %d , 체력 : %d\n", p[i].power, p[i].defensivePower, p[i].hp);
		power_sum+=p[i].power;
		weaponNum = _msize(p[i].w) / sizeof(Weapon);
		printf("******* 보유무기 ******** \n");
		for (j=0; j<weaponNum; j++){
			printf("%s (능력치 %d)\n", p[i].w[j].name, p[i].w[j].power);
			power_sum += p[i].w[j].power;
		}
		printf("총 능력치 : %d\n", power_sum);
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

	printf("!! 공격 !! '%s' --> '%s' \n", hunter.name, target->name);
	
	if ((rand()%(MAX-target->defensivePower))==1)	//방어력이 3이면, 1/7 확률로 공격 막음.
		printf("'%s'가 방어에 성공했습니다.\n", target->name);
	else{
		printf("'%s'가 방어에 실패해 체력이 깎였습니다.\n", target->name);
		target->hp -= power_sum;
	}
}
void showPlayersHp(Player *p, int playerNum){
	int i=0;
	printf("\n[%s] : ", p->name);
	for (i=0; i<p[i].hp; i+=2) printf("■");
	if (p[1].hp%2 != 0) printf("□");
	printf("(%d)\n", p[1].hp);
}
//게임 시작 이후에 보여주는 Hp

void selecePlayer(int playerNum){
	int hunter, target;
	srand((unsigned)time(NULL));
	hunter = rand()%playerNum;
	target = rand()%playerNum;
}