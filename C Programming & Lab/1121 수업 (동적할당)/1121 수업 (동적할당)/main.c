#include <stdio.h>

//malloc�� ����ִ� ������ϵ�. �� �߿� �ϳ��� ���� ��
#include <stdlib.h>
#include <memory.h>		//�� �ȿ� memset ����
//#include <malloc.h>

int main(void)
{
	int *p = NULL;
	int size = 1000000;		//����
	int c = 0;
	unsigned int total = 0;

	printf("p�� �ּ� : %p \n", &p);
	printf("p�� �� : %p \n", p);
	//printf("�Ҵ��� ũ�� : "); scanf("%d", &size);		//��û ū �� �ָ� ������ �ǹ̷� NULL ��ȯ. �� 0000���� ��


	while(1){
	
		p = (int *)malloc(sizeof(int)*size);		//int�� ũ�⸸ŭ�� ���� size���� ��!!!
		memset(p, 0x0, sizeof(int)*size);	//memory�� set �ض�. �ּ�(����ִ� ��) �̰ɷ� ��������. �󸶸�ŭ? ũ�⸸ŭ!
		//p�� �ִ� �� NULL/0�� �ʱ�ȭ����. �� �о���.
		//0x0 16���� ���·� �̰� ��¥ Ȯ���� 0�̴�! ��� �ǹ�
		total += _msize(p);

	
		printf("[%d]",c+1);
		printf("�Ҵ���� ũ��(�Ҵ��� ũ��*������ ����Ʈ) : %d\n", _msize(p));

		printf("\n�Ҵ� ��\n");
		printf("p�� �ּ� : %p // p�� �� : %p // *p : %d \n\n", &p,p,*p);
		printf("�Ҵ���� �� ũ�� : %d ����Ʈ\n", total);
		printf("======================================================\n\n");
		if (p==NULL) break;
		c++;
		free(p);	//�� ���п� ���ѷ��� ����
	}

	return 0;
}