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
	//�� ����� ��	Person p;
	//10����� ��	Person par[10];

	//�� ������� �� ��
	Person *pp;
	int how_many;
	int i, k;



	printf("�� ����Դϱ�? : "); scanf("%d",&how_many);

	pp = (Person*)malloc(sizeof(Person)*how_many);		//�տ� (Person*) : �� �ּҿ� ���� �� �־�~ Person �־�~ �� �ǹ�
														//pp�� Ÿ�԰�, �Ҵ���� �ּ��� Ÿ���� ���ƾ� ��. => Person*
	if (pp==NULL){
		printf("�Ҵ� ���� \n");
		exit(1);	//0�� �ƴ� �� ������ ��. stdlib.h ���� ������ �� ��
	}

	memset(pp, 0x0, sizeof(Person)*how_many);	//pp�� size��ŭ 0�� �־��ּ���	//������� memory.h�� ��� ����
	printf("Person�� ũ�� : %d ����Ʈ \n",sizeof(Person));
	printf("pp�� �ּ� : %p \n", pp);
	printf("pp�� �Ҵ���� ũ�� : %d ����Ʈ \n",_msize(pp));
	printf("pp�� %d ���� �� �� �ֽ��ϴ�\n\n",_msize(pp)/sizeof(Person));

	//////////////////////////////////////////////////////////////////////////////////////

	printf("\n(�ο� ����)����� �� ��������? : "); scanf("%d", &how_many);	 //�������� �÷��� ����
	pp = (Person*)realloc(pp, sizeof(Person)*how_many);
	
	printf("pp�� �ּ� : %p\n", pp);
	printf("pp�� �Ҵ���� ũ�� : %d ����Ʈ \n",_msize(pp));
	printf("pp�� %d ���� �� �� �ֽ��ϴ�\n\n",_msize(pp)/sizeof(Person));


	//printf("����� ���� �ο��� ����ΰ���? : "); //�����ϰ� �ٽ� ������ �Ҹ�







	//�Է¹ޱ�
	for (i=0; i<how_many; i++){		//how_many = _msize(pp)/sizeof(Person)
		//���� �Ҵ�
		pp[i].name = (char*)malloc(sizeof(char)*100);
		
		printf("[%d] - �̸� : ", i+1);
		scanf("%s", pp[i].name);

		//���� ����	
		k = strlen(pp[i].name)+1;	//�̸� ����+1 ��ŭ		//string.h �� �������
		pp[i].name = (char*)realloc(pp[i].name, k);
		
		
		printf("[%d] - ���� : ", i+1);
		scanf("%d", &pp[i].age);
	}
	printf("\n");
	for (i=0; i<how_many; i++){
		printf("[%d] : %s(%d ����Ʈ) %d \n", i+1, pp[i].name, _msize(pp[i].name), pp[i].age);
	}
}