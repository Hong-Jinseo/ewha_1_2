#pragma once
#include "battle.h"
#define STR_MAX 100

char *makeStr(){
	char *str = (char *)malloc(sizeof(char)*STR_MAX);
	if (str==NULL){
		printf("�̸����� �Ҵ� ����\n");
		//Ȥ�ó� �Ҵ� ���и� ���� ���. �̰� ���� ������ �� ���� �ڵ�
		//���⼭ ������ ���� �ְ� (exit(1);_
		//main�� �� ��Ȳ �˸� �� ����
	}

	memset(str, 0x0, sizeof(char)*STR_MAX);

	//�̸��ޱ�
	printf("name : "); scanf("&s", str);

	//ũ������
	str = (char *)realloc(str, strlen(str)+1);

	printf("%s (%d) \n", str, _msize(str));

	return str;
}


void makeStr_void(char **str_addr){
	*str_addr = (char *)malloc(sizeof(char)*STR_MAX);		//*, **, X ���߿� ���� �׸��׸��鼭 �ľ��ϱ�
	//��Ʈ���� ���� �ּҸ� ������ �Ͽ�,

	if (*str_addr==NULL) printf("�����Ҵ� ����\n\n");
		//���⼭ ���� or main�� �� ��Ȳ �˸���. but..

	memset(*str_addr, 0x0, sizeof(char)*STR_MAX);

	//�̸��ޱ�
	printf("name : "); scanf("&s", *str_addr);	//**���� �ʴ� ���� : s�� �ʿ��� �� �� ���� �ּ��̱� ������

	//ũ������
	*str_addr = (char *)realloc(*str_addr, strlen(*str_addr)+1);
	printf("%s (%d) \n", *str_addr, _msize(*str_addr));

}

