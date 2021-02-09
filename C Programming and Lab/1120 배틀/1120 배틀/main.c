#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dataType.h"
#include "battle.h"

int main(void)
{
	int i=1;
	Weapon w1 = {"방망이",2};
	Weapon w2 = {"망치",3};

	//사용자 이름, &무기, 공격력, 방어력, 체력
	Player p1 = {"이화여대", &w1, 7, 4, 30};	//포인터니까 &써야함
	Player p2 = {"상일여고", &w2, 5, 3, 45};

	show_Player(p1);
	show_Player(p2);

	srand((unsigned)time(NULL));

	while(1){
		if(p1.hp<=0 || p2.hp<=0){
			printf("\n GAME OVER \n\n");
			if (p1.hp<=0) printf("%s가 승리했습니다!\n\n",p2.name);
			if (p2.hp<=0) printf("%s가 승리했습니다!\n\n",p1.name);
			break;
		}

		if (rand()%2==1){
			attact(p1,&p2,i++);
			showPlayersHp(p1,p2);
		}
		else{
			attact(p2,&p1,i++);
			showPlayersHp(p1, p2);
		}

		getchar();
	}
}

	