#include <stdio.h>
#define N 10
int main(void)
{
	int i,j,k=0;
	int num[N] = {0};
	
	while(1){
		printf(" %d-input : ",k);	// "0-input :" 출력
		scanf("%d",&i);				//스캔받아서 i 초기화

		if (i%10 == 0) continue;	//i가 10의 배수이면 다시 입력받기

		num[k]=i;					//i가 10의 배수 아니라면, 배열 num의 k번째 칸에 i 넣기 
		for (j=0; j<i; j++)			//그 i가 짝수가 아닐 경우, *을 i개 만큼 출력
		{
			if (i%2 == 0) break;
			else printf("*");
		}
		k++;						//i가 10의 배수 아닐 경우, k를 1 만큼 증가시키기

		for (j=0; j<10; j++)		//배열 num의 index 0부터 9까지 출력
			printf("%d ",num[j]);
		printf("\n##################\n");
	}
	return 0;
}