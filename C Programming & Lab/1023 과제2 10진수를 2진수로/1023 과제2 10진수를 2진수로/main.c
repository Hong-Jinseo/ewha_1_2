#include <stdio.h>
#define N 32

int main(void)
{
	int bit[N] = {0};
	int num, j, i;

	while(1)
	{
		printf("input : ");
		scanf("%d",&num);
		printf("16���� : 0x%p\n",num);

		for (i=N-1; i>=0; i--)
		{
			if (num==0) break;
			bit[i]=num%2;
			num/=2;
		}
	
		printf("2���� : ");
		for(j=0; j<N; j++)
			printf("%d ",bit[j]);
		printf("\n\n");
	}
}