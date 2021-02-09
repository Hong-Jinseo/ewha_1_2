#include <stdio.h>
#include <malloc.h>

int main(void)
{
	char *str = "abc";
	int i=0;

	printf("할당 전 : str : %p	%s \n", str, str);
	str = (char *)malloc(1000);
	memset(str, 0x0, 1000);
	printf("할당 후 : str : %p	%s	크기 : %d 바이트, 길이 : %d \n", str, str, _msize(str), _msize(str)/sizeof(str));

	printf("input : "); scanf("%s", &


	str = (char *)realloc(str, strlen(str)+1);
	printf("재할당 : str : %p	%s	크기 : %d 바이트, 길이 : %d \n", str, str, _msize(str), _msize(str));




	///////


}