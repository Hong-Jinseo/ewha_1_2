#pragma once
#include "battle.h"


#define �̸����� 100
 
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
        printf("�ο� �Ҵ� �۾� ����");
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
    
    while(fighter1==fighter2){//fighter1�� fighter2�� �ٸ������� �ݺ�
    
        fighter2=rand()%playerNum;} //fighter 2 �ٽ� ������ ����
    
    
    printf("%s�� %s�� �����մϴ�.",p[fighter1].name,p[fighter2].name); 
 




    while(1){
        if(p[fighter1].hp<=0 || p[fighter2].hp<=0){
            printf("������ �������ϴ�\n");
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
	Player *p = NULL;		//�Ҵ�޾Ƽ� ���� ��. ���� ��� ȿ����
	int a=3;
	char *str = "ab";
	Player pp={0};

	//�����Ҵ�
	str = (char *)malloc(sizeof(char)*100);
	memset(str, 0x0, sizeof(char)*100);


	printf("input name : ");
	scanf("%s", str);
	
	//���� ���Ҵ�
	str = (char *)realloc(str, strlen(str)+1); //str�� ���� + NULL ���� �ϳ�
	printf("str : %s, ũ�� : \n",str);
	
	
	//�� �� ������
	str = makeStr(); //name���� �Ҵ�ް� �Է¹ް� ���̱�
	if (str==NULL){
		printf("�̸������Ҵ� ���� - main\n");
	}
	signal = mekeStr_void(&str);
	if (signal==NULL) 

	return 0;
}
*/