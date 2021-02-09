#pragma once
#include "battle.h"


#define 이름길이 100
 
int main(){
	int playerNum, weaponNum;
    int i,k;
    int signal;
    int random;
    int fighter1;
	int fighter2;
    Player *p=NULL;
    Weapon *w=NULL;
    Player *killer, *target;
 
    signal=makePlayers(&p);
    if(signal==NULL){
        printf("인원 할당 작업 실패");
        exit(1);
    }
 
    playerNum = _msize(p)/sizeof(Player);
    for(i=0; i<playerNum; i++){
        setPlayer(&p[i]);
        weaponNum = _msize(p[i].w)/sizeof(Weapon);
        for(k=0; k<weaponNum; k++){
            setWeapon(&p[i].w[k]);
        }
    }
 
    showPlayer(p, w, playerNum, weaponNum);

	///////////////////////////////////////////////
    
    srand((unsigned)time(NULL));
    
    fighter1=rand()%playerNum;
    fighter2=rand()%playerNum;
    
    while(fighter1==fighter2){//fighter1과 fighter2가 다를때까지 반복
    
        fighter2=rand()%playerNum;} //fighter 2 다시 랜덤수 형성
    
    
    printf("%s와 %s가 출전합니다.",p[fighter1].name,p[fighter2].name); 
 




    while(1){
        if(p[fighter1].hp<=0 || p[fighter2].hp<=0){
            printf("게임이 끝났습니다\n");
            break;
}
 
        if(rand()%2==1) {
            attack(p[fighter1],&p[fighter2]);
            showPlayer(p[fighter2]);
        }
        else attack(p[fighter2],&p[fighter1]);
            showPlayer(p[fighter1]);
        }
    
 
           getchar();
    }
 





/*
int main(void){
	Player *p = NULL;		//할당받아서 쓰면 됨. 공간 사용 효율적
	int a=3;
	char *str = "ab";
	Player pp={0};

	//공간할당
	str = (char *)malloc(sizeof(char)*100);
	memset(str, 0x0, sizeof(char)*100);


	printf("input name : ");
	scanf("%s", str);
	
	//공간 재할당
	str = (char *)realloc(str, strlen(str)+1); //str의 길이 + NULL 공간 하나
	printf("str : %s, 크기 : \n",str);
	
	
	//둘 다 만들어보기
	str = makeStr(); //name공간 할당받고 입력받고 줄이기
	if (str==NULL){
		printf("이름공간할당 실패 - main\n");
	}
	signal = mekeStr_void(&str);
	if (signal==NULL) 

	return 0;
}
*/