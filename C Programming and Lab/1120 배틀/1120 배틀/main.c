#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dataType.h"
#include "battle.h"

int main(void)
{
	int i=1;
	Weapon w1 = {"�����",2};
	Weapon w2 = {"��ġ",3};

	//����� �̸�, &����, ���ݷ�, ����, ü��
	Player p1 = {"��ȭ����", &w1, 7, 4, 30};	//�����ʹϱ� &�����
	Player p2 = {"���Ͽ���", &w2, 5, 3, 45};

	show_Player(p1);
	show_Player(p2);

	srand((unsigned)time(NULL));

	while(1){
		if(p1.hp<=0 || p2.hp<=0){
			printf("\n GAME OVER \n\n");
			if (p1.hp<=0) printf("%s�� �¸��߽��ϴ�!\n\n",p2.name);
			if (p2.hp<=0) printf("%s�� �¸��߽��ϴ�!\n\n",p1.name);
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

	