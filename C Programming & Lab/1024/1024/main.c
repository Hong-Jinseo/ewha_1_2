#include <stdio.h>

int main(void)
{
	int i=0,c;
	char str[];

	printf("enter number : ");

	while(1)
	{
		scanf("%c",&c);

		if (c=='\n') break;
		if (c>='0' && c<='9')
			str[i++]=c;
	}
	str[i]='\0';
	for (j=0; j<sig; j++)
		{
			sum += (str[j]-'0')*(power(10,sig-j));
		}

		printf("�迭�� ũ�� : %d\n", sig);
		printf("�Էµ� �� : %d\n\n", sum);	
}