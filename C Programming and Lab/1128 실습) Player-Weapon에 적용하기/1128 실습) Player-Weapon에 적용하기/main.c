#pragma once
#include "battle.h"	//battle.h �ȿ� �ٸ� ������� �� ����־ battle.h�� include �ϸ� ��

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