#pragma once
#include "battle.h"

int main(){
	int playerNum, weaponNum;
    int i,k;
    int signal;
	int num1, num2;
    Player *p=NULL;
    Weapon *w=NULL;
    Player *killer, *target;
 
    signal=makePlayers(&p);
    if(signal==NULL){
        printf("인원 할당 작업 실패");
        exit(1);
    }
	
	//어떤 목적인지 모르겠음
    playerNum = _msize(p)/sizeof(Player);
    for(i=0; i<playerNum; i++){
        setPlayer(&p[i]);
        weaponNum = _msize(p[i].w)/sizeof(Weapon);
        for(k=0; k<weaponNum; k++){
            setWeapon(&p[i].w[k]);
        }
    }

    showPlayer(p, w, playerNum, weaponNum);

	/////////////////////////////////////////////////
	//배틀 시작

	srand((unsigned)time(NULL));
	num1 = rand()%playerNum;
	num2 = rand()%playerNum;
	while (num1 == num2) num2=rand()%playerNum;

	while(1){
		if(p[num1].hp<=0 || p[num2].hp<=0){
			printf("\n GAME OVER \n\n");
			if (p[num1].hp<=0) printf("%s가 승리했습니다!\n\n",p[num2].name);
			if (p[num2].hp<=0) printf("%s가 승리했습니다!\n\n",p[num1].name);
			break;
		}
		
		attack(p[num1], &p[num2]);
		for (i=0; i<playerNum; i++){
			showPlayersHp(&p[i], playerNum);
		}
		printf("----------------------------------------\n\n");

		if(p<=0){
			printf("\n GAME OVER \n\n");
			break;
		}
		getchar();
	}
}