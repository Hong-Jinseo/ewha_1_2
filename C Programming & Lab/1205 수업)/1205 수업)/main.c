#include <stdio.h>
#include <malloc.h>

int main(void)
{
	char *str = "abc";
	int i=0;

	printf("�Ҵ� �� : str : %p	%s \n", str, str);
	str = (char *)malloc(1000);
	memset(str, 0x0, 1000);
	printf("�Ҵ� �� : str : %p	%s	ũ�� : %d ����Ʈ, ���� : %d \n", str, str, _msize(str), _msize(str)/sizeof(str));

	printf("input : "); scanf("%s", &


	str = (char *)realloc(str, strlen(str)+1);
	printf("���Ҵ� : str : %p	%s	ũ�� : %d ����Ʈ, ���� : %d \n", str, str, _msize(str), _msize(str));




	///////


}