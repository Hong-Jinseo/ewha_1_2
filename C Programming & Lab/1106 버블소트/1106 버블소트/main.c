#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void show(int ar[], int size);		//�� �����ֱ�
void make_nums(int ar[], int i);	//���� �����
void swap(int num1, int num2);		//�� ���� �ٲٱ�
void bubble(int ar[], int size);	//�����Ʈ


int main()
{
	int ar[SIZE] = {0};

	make_nums(ar,SIZE);
	printf("** bubble sort ���� ��\n");
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
		if (i==size-1) printf("= = [ ���� ��� ] = =\n");
		else printf("==[%d�� SORTING]==\n",i+1);
		for (j=0; j<size-1; j++){
			//ū ���� �տ������� swap ���ֱ�
			if (ar[j]>ar[j+1]) swap(&ar[j],&ar[j+1]);
		}
		show(ar,SIZE);
	}
}