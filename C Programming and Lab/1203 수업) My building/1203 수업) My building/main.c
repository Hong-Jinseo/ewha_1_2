#include <stdio.h>
#include <malloc.h>

typedef struct person{
	char *name;
	int age;
}Person;


int main(void)
{
	Person building1[5][10];
	Person *building2[5];		//5�ึ�� ���� n���� ���� �� ����
	Person **building3;			//n�ึ�� ���� m���� ���� �� ����
	Person ***building4;		//�̰� ���� ��? : �� ��ĭ�� �������� ���. �ᱹ���� 3��. �Ǵ� ����3�� ������ ���� �ִ� ��

	//3��

	int ��, ��;
	int i,j,size;

	printf("�� � : "); scanf("%d", &��);
	building3 = (Person **)malloc(sizeof(Person *)*��);				//������ ���� ����Ű�� �ּҰ� ���� ������ * ���̱�. (������ ����� ���� X)

	if (building3==NULL) {printf("�Ҵ� ����!\b"); exit(1); }

	printf("�Ҵ�� ����Ʈ : %d , �� : %d\n\n", _msize(building3), _msize(building3)/sizeof(building3));

	for (i=0; i<��; i++){
		printf("%d���� �� �? : ",i+1); 
		scanf("%d", &��);
		building3[i] = (Person *)malloc(sizeof(Person)*��);
	}

	
	for (i=0; i<��; i++){
		size = _msize(building3[i])/sizeof(*building3[i]);						// *building[i] == **building ???
		//printf("%d, %d\n\n",_msize(building3[i]),sizeof(*building3[i]));

		printf("[%d]�� : ",i+1);
		for (j=0; j<size; j++) 
			if (size==0) printf("�� ����");
			else printf("��");
		printf("\n");
	}
	printf("\n\n");
}