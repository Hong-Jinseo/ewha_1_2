#include <stdio.h>
#define N 10
int main(void)
{
	int i,j,k=0;
	int num[N] = {0};
	
	while(1){
		printf(" %d-input : ",k);	// "0-input :" ���
		scanf("%d",&i);				//��ĵ�޾Ƽ� i �ʱ�ȭ

		if (i%10 == 0) continue;	//i�� 10�� ����̸� �ٽ� �Է¹ޱ�

		num[k]=i;					//i�� 10�� ��� �ƴ϶��, �迭 num�� k��° ĭ�� i �ֱ� 
		for (j=0; j<i; j++)			//�� i�� ¦���� �ƴ� ���, *�� i�� ��ŭ ���
		{
			if (i%2 == 0) break;
			else printf("*");
		}
		k++;						//i�� 10�� ��� �ƴ� ���, k�� 1 ��ŭ ������Ű��

		for (j=0; j<10; j++)		//�迭 num�� index 0���� 9���� ���
			printf("%d ",num[j]);
		printf("\n##################\n");
	}
	return 0;
}