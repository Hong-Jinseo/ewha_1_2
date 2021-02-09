#pragma once
#include "battle.h"	//battle.h 안에 다른 헤더파일 다 들어있어서 battle.h만 include 하면 됨

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