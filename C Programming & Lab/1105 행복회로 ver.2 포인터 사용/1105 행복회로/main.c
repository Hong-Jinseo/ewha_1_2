//���� "�ູȸ��" �����
#include <stdio.h>
#define max_warning 90
#define min_warning 10

void show_menu()
{	
	printf("~~~~#~~~~#~~~~#~~~~\n");
	printf("1. �����ϱ�\n");
	printf("2. �Ա�\n");
	printf("3. ���ڱ�\n");
	printf("4. ���� ����\n");
	printf("5. ��Ʃ�� ����\n");
	printf("~~~~#~~~~#~~~~#~~~~\n\n");}

void �����ϱ�(int *tired, int*happy){	
	//�Ƿε� +20, �ູ�� -10
	*tired+=20;
	*happy-=10;
	printf("�Ƿε��� 20 �����ϰ�, �ູ���� 10 �����߽��ϴ�.\n");
}
void �Ա�(int *happy, int *full){
	//������ +30, �ູ�� +15
	*full += 30;
	*happy -= 10;
	printf("�������� 30 �����ϰ�, �ູ���� 15 �����߽��ϴ�.\n");
}
void �������(int *full, int* tired, int *happy){
	//������ -10, �Ƿε� +20, �ູ�� -15
	*full -= 10;
	*tired += 20;
	*happy -=15;
	printf("�Ƿε��� 20 �����ϰ�, �ູ���� 15 �����ϰ�, �������� 10 �����߽��ϴ�.\n");
}
void ���ڱ�(int *tired, int *happy){
	//�Ƿε� -20, �ູ�� +20
	*tired -= 20;
	*happy += 20;
	printf("�Ƿε��� 20 �����ϰ�, �ູ���� 20 �����߽��ϴ�.\n");
}
void ����_����(int *happy, int *tired){
	//�ູ�� +20, �Ƿε� +10
	*happy +=20;
	*tired +=10;
	printf("�Ƿε��� 10 �����ϰ�, �ູ���� 20 �����߽��ϴ�.\n");
}

int main(void)
{
	int act;
	int happy=50;
	int full=50;
	int tired=50;

	show_menu();
	
	printf("========���� ����========\n");
	printf("�ູ�� : %d\n",happy);
	printf("������ : %d\n",full);
	printf("�Ƿε� : %d\n",tired);
	printf("========================\n\n");

	while(1)
	{

		printf("���ϴ� Ȱ�� ��ȣ�� �Է��ϼ���(���ڸ�) : ");
		scanf("%d",&act);

		if (act==1) �����ϱ�(&tired, &happy);
		if (act==2) �Ա�(&happy, &full);
		if (act==3) �������(&full, &tired, &happy);
		if (act==4) ���ڱ�(&tired, &happy);
		if (act==5) ����_����(&happy,&tired);


		printf("\n\n================���� ����================\n");
		printf("              �ູ�� : %d\n",happy);
		printf("              ������ : %d\n",full);
		printf("              �Ƿε� : %d\n",tired);
		if (happy<=min_warning) printf("[����]�ູ���� 10 �̸����� ���������ϴ�. ������� �ɸ����� �����!\n");
		if (tired>=max_warning) printf("[����]�Ƿε��� 90�� �ʰ��߽��ϴ�. ���� ���������� �����!\n");
		if (full<=min_warning) printf("[����]�������� 10 �̸����� ���������ϴ�. �谡 ���ļ� ���������� �����!\n");
		if (full<=min_warning) printf("[����]�������� 90�� �ʰ��߽��ϴ�. �谡 �������� �����!\n");
		
		printf("========================================\n\n");

		if ((happy<=0) || (tired>=100) || (full<=0) || (full>=100)) break;

		show_menu();
	
	}

	if (happy<=0) printf("�ູ���� �ʹ� ������ ������� �ɷȽ��ϴ�.\n\n"); 
	if (tired>=100) printf("�ʹ� �ǰ��ؼ� ������ �� �����ϴ�.\n\n");
	if (full<=0) printf("�谡 �ʹ� ���ļ� ���������ϴ�.\n\n"); 
	if (full>=100) printf("�谡 �ʹ� �ҷ��� ������ �� �����ϴ�.\n\n");
		
}