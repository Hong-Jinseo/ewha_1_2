#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void show(int ar[], int size);		//수 보여주기
void make_nums(int ar[], int i);	//난수 만들기
void swap(int num1, int num2);		//수 서로 바꾸기
void bubble(int ar[], int size);	//버블소트


int main()
{
	int ar[SIZE] = {0};

	make_nums(ar,SIZE);
	printf("** bubble sort 시작 전\n");
	show(ar, SIZE);

    bubble(ar, SIZE);
}


void show(int ar[], int size){
	int i;
	for (i=0; i<size; i++)
		printf("%2d ", ar[i]);
	printf("\n\n");
}
void make_nums(int ar[], int size){
	int i;
	srand((unsigned)time(NULL));
	for(i=0; i<size; i++)
		ar[i] = rand()%100;
}
void swap(int *num1, int *num2){
	int trans;
	trans = *num1;
	*num1 = *num2;
	*num2 = trans;
}
void bubble(int ar[], int size){
	int i,j;
	for (i=0; i<size; i++){
		if (i==size-1) printf("= = [ 최종 결과 ] = =\n");
		else printf("==[%d차 SORTING]==\n",i+1);
		for (j=0; j<size-1; j++){
			//큰 수가 앞에있으면 swap 해주기
			if (ar[j]>ar[j+1]) swap(&ar[j],&ar[j+1]);
		}
		show(ar,SIZE);
	}
}