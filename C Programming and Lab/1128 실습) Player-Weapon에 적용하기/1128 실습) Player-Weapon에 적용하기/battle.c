#pragma once
#include "battle.h"
#define STR_MAX 100

char *makeStr(){
	char *str = (char *)malloc(sizeof(char)*STR_MAX);
	if (str==NULL){
		printf("이름공간 할당 실패\n");
		//혹시나 할당 실패를 위한 대비. 이거 한줄 넣으면 더 좋은 코드
		//여기서 종료할 수도 있고 (exit(1);_
		//main에 이 상황 알릴 수 있음
	}

	memset(str, 0x0, sizeof(char)*STR_MAX);

	//이름받기
	printf("name : "); scanf("&s", str);

	//크기조정
	str = (char *)realloc(str, strlen(str)+1);

	printf("%s (%d) \n", str, _msize(str));

	return str;
}


void makeStr_void(char **str_addr){
	*str_addr = (char *)malloc(sizeof(char)*STR_MAX);		//*, **, X 셋중에 뭔지 그림그리면서 파악하기
	//스트링에 들어가는 주소를 포인팅 하여,

	if (*str_addr==NULL) printf("공간할당 실패\n\n");
		//여기서 종료 or main에 이 상황 알리기. but..

	memset(*str_addr, 0x0, sizeof(char)*STR_MAX);

	//이름받기
	printf("name : "); scanf("&s", *str_addr);	//**쓰지 않는 이유 : s가 필요한 건 이 값의 주소이기 떄문에

	//크기조정
	*str_addr = (char *)realloc(*str_addr, strlen(*str_addr)+1);
	printf("%s (%d) \n", *str_addr, _msize(*str_addr));

}

