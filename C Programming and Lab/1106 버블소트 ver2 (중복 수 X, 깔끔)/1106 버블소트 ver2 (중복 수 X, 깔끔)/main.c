#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"
#define SIZE 10

int main()
{
	int ar[SIZE] = {0};

	make_nums(ar,SIZE);
	show(ar, SIZE);
	printf("====������������ ����� ��====\n\n");
    bubble_up(ar, SIZE);
	printf("====������������ ����� ��====\n\n");
    bubble_down(ar, SIZE);
}