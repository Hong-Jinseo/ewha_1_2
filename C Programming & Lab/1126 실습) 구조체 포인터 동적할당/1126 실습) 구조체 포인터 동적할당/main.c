#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

typedef struct person{
	//char name[100];
	char *name;
	int age;
}Person;


int main(void){
	//한 사람일 때	Person p;
	//10사람일 때	Person par[10];

	//몇 사람인지 모를 때
	Person *pp;
	int how_many;
	int i, k;



	printf("몇 사람입니까? : "); scanf("%d",&how_many);

	pp = (Person*)malloc(sizeof(Person)*how_many);		//앞에 (Person*) : 이 주소에 가면 뭐 있어~ Person 있어~ 의 의미
														//pp의 타입과, 할당받은 주소의 타입이 같아야 함. => Person*
	if (pp==NULL){
		printf("할당 실패 \n");
		exit(1);	//0이 아닌 수 넣으면 됨. stdlib.h 쓰면 빨간줄 안 뜸
	}

	memset(pp, 0x0, sizeof(Person)*how_many);	//pp에 size만큼 0을 넣어주세요	//헤더파일 memory.h에 들어 있음
	printf("Person의 크기 : %d 바이트 \n",sizeof(Person));
	printf("pp의 주소 : %p \n", pp);
	printf("pp에 할당받은 크기 : %d 바이트 \n",_msize(pp));
	printf("pp에 %d 명이 들어갈 수 있습니다\n\n",_msize(pp)/sizeof(Person));

	//////////////////////////////////////////////////////////////////////////////////////

	printf("\n(인원 변경)몇명이 더 들어오나요? : "); scanf("%d", &how_many);	 //기존공간 플러스 알파
	pp = (Person*)realloc(pp, sizeof(Person)*how_many);
	
	printf("pp의 주소 : %p\n", pp);
	printf("pp에 할당받은 크기 : %d 바이트 \n",_msize(pp));
	printf("pp에 %d 명이 들어갈 수 있습니다\n\n",_msize(pp)/sizeof(Person));


	//printf("변경된 최종 인원은 몇명인가요? : "); //리셋하고 다시 받으란 소리







	//입력받기
	for (i=0; i<how_many; i++){		//how_many = _msize(pp)/sizeof(Person)
		//공간 할당
		pp[i].name = (char*)malloc(sizeof(char)*100);
		
		printf("[%d] - 이름 : ", i+1);
		scanf("%s", pp[i].name);

		//공간 변경	
		k = strlen(pp[i].name)+1;	//이름 길이+1 만큼		//string.h 에 들어있음
		pp[i].name = (char*)realloc(pp[i].name, k);
		
		
		printf("[%d] - 나이 : ", i+1);
		scanf("%d", &pp[i].age);
	}
	printf("\n");
	for (i=0; i<how_many; i++){
		printf("[%d] : %s(%d 바이트) %d \n", i+1, pp[i].name, _msize(pp[i].name), pp[i].age);
	}
}