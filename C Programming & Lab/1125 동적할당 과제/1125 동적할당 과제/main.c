#include <stdio.h>
#include <malloc.h>

int main(void){
	char *p;
	int size = 100000;
	int i=1, total=0;

	while(1){
		p = (char*)malloc(sizeof(char)*size);
	
		if (p==NULL){	//��ȯ���� NULL �̸� break
			printf("�Ҵ� ����\n");
			break;
		}

		total += _msize(p);
		printf("[num %d] ",i);
		printf("&p : %p, p : %p, p�� �Ҵ�� ���� : %d bytes, ���ݱ��� �Ҵ�� ������ ũ�� : %d bytes\n\n",&p,p,_msize(p),i*size);
		i++;

		printf("�Ҵ� ũ�� : ");
		scanf("%d",&size);
		realloc(p, sizeof(int)*size);

		printf("&p : %p, p : %p, p�� �Ҵ�� ���� : %d bytes, ���ݱ��� �Ҵ�� ������ ũ�� : %d bytes\n",&p,p,_msize(p),i*size);
		printf("�Ҵ�� ���� ũ�� : %d bytes\n",_msize(p));
		printf("�Ҵ���� �� ũ�� : %d bytes\n\n",total);
		free(p);

		//free(p);
	}
}