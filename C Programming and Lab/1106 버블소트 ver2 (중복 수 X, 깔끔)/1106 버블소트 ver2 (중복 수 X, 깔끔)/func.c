#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

void show(int ar[], int size){
	int i;
	for (i=0; i<size; i++)
		printf("%2d ", ar[i]);
	printf("\n\n");
}

//�ߺ� �ȵǴ� ���� �����//
void make_nums(int ar[], int size){
	int i,j,k;
	srand((unsigned)time(NULL));
	for (i=0; i<size; i++){
		ar[i] = rand()%100;			//��������� ���� �ߺ� ����
		for (j=0; j<i; j++)
			if (ar[j]==ar[i]) i--;
	}
		
}

void swap(int *num1, int *num2){
	int trans;
	trans = *num1;
	*num1 = *num2;
	*num2 = trans;
}

//�������� �����Ʈ
void bubble_up(int ar[], int size){
	int i,j;
	for (i=0; i<size; i++){
		//if (i==size-1) printf("= = [ ���� ��� ] = =\n");
		//else printf("==[%d�� SORTING]==\n",i+1);
		for (j=0; j<size-1; j++){
			//ū ���� �տ������� swap ���ֱ�
			if (ar[j]>ar[j+1]) swap(&ar[j],&ar[j+1]);
		}
	}
	show(ar,size);
}

//�������� �����Ʈ
void bubble_down(int ar[], int size){
	int i,j;
	for (i=0; i<size; i++){
		for (j=0; j<size-1; j++){
			//���� ���� �տ������� swap ���ֱ�
			if (ar[j]<ar[j+1]) swap(&ar[j],&ar[j+1]);
		}
	}
	show(ar,size);
}