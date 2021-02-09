#include <stdio.h>

int main(void)
{
	char str[30]="abcdefg1234567890!@#$%^&*";
	int i=0;

	printf("char str[50] = %s\n\n",str);
	while(i<sizeof(str)) 
		printf("%s\n",&str[i++]);
}
