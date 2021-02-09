#include <stdio.h>

//malloc가 들어있는 헤더파일들. 셋 중에 하나만 쓰면 됨
#include <stdlib.h>
#include <memory.h>		//이 안에 memset 있음
//#include <malloc.h>

int main(void)
{
	int *p = NULL;
	int size = 1000000;		//개수
	int c = 0;
	unsigned int total = 0;

	printf("p의 주소 : %p \n", &p);
	printf("p의 값 : %p \n", p);
	//printf("할당할 크기 : "); scanf("%d", &size);		//엄청 큰 값 주면 실패의 의미로 NULL 반환. 값 0000으로 뜸


	while(1){
	
		p = (int *)malloc(sizeof(int)*size);		//int의 크기만큼의 공간 size개를 줘!!!
		memset(p, 0x0, sizeof(int)*size);	//memory를 set 해라. 주소(어디있는 걸) 이걸로 셋팅해줘. 얼마만큼? 크기만큼!
		//p에 있는 걸 NULL/0로 초기화해줘. 싹 밀어줘.
		//0x0 16진수 형태로 이건 진짜 확실한 0이다! 라는 의미
		total += _msize(p);

	
		printf("[%d]",c+1);
		printf("할당받은 크기(할당할 크기*정수형 바이트) : %d\n", _msize(p));

		printf("\n할당 후\n");
		printf("p의 주소 : %p // p의 값 : %p // *p : %d \n\n", &p,p,*p);
		printf("할당받은 총 크기 : %d 바이트\n", total);
		printf("======================================================\n\n");
		if (p==NULL) break;
		c++;
		free(p);	//얘 덕분에 무한루프 돈다
	}

	return 0;
}