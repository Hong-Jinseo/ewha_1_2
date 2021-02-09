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

//중복 안되는 집합 만들기//
void make_nums(int ar[], int size){
	int i,j,k;
	srand((unsigned)time(NULL));
	for (i=0; i<size; i++){
		ar[i] = rand()%100;			//여기까지만 쓰면 중복 있음
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

//오름차순 버블소트
void bubble_up(int ar[], int size){
	int i,j;
	for (i=0; i<size; i++){
		//if (i==size-1) printf("= = [ 최종 결과 ] = =\n");
		//else printf("==[%d차 SORTING]==\n",i+1);
		for (j=0; j<size-1; j++){
			//큰 수가 앞에있으면 swap 해주기
			if (ar[j]>ar[j+1]) swap(&ar[j],&ar[j+1]);
		}
	}
	show(ar,size);
}

//내림차순 버블소트
void bubble_down(int ar[], int size){
	int i,j;
	for (i=0; i<size; i++){
		for (j=0; j<size-1; j++){
			//작은 수가 앞에있으면 swap 해주기
			if (ar[j]<ar[j+1]) swap(&ar[j],&ar[j+1]);
		}
	}
	show(ar,size);
}