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

void �����ϱ�(int status[]){	
	//�Ƿε� +20, �ູ�� -10
	status[0]-=10;
	status[2]+=20;
	printf("�Ƿε��� 20 �����ϰ�, �ູ���� 10 �����߽��ϴ�.\n");
}
void �Ա�(int status[]){
	//������ +30, �ູ�� +15
	status[0] += 10;
	status[1] += 20;
	printf("�������� 30 �����ϰ�, �ູ���� 15 �����߽��ϴ�.\n");
}
void �������(int status[]){
	//������ -10, �Ƿε� +20, �ູ�� -15
	status[0] -= 15;
	status[1] -= 10;
	status[2] += 20;
	printf("�Ƿε��� 20 �����ϰ�, �ູ���� 15 �����ϰ�, �������� 10 �����߽��ϴ�.\n");
}
void ���ڱ�(int status[]){
	//�Ƿε� -20, �ູ�� +20
	status[0] += 20;
	status[2] -= 20;
	printf("�Ƿε��� 20 �����ϰ�, �ູ���� 20 �����߽��ϴ�.\n");
}
void ����_����(int status[]){
	//�ູ�� +20, �Ƿε� +10
	status[0] += 20;
	status[2] += 10;
	printf("�Ƿε��� 10 �����ϰ�, �ູ���� 20 �����߽��ϴ�.\n");
}

int main(void)
{
	int act;
	int status[3] = {50,50,50}; //�ູ��, ������, �Ƿε�

	show_menu();
	
	printf("========���� ����========\n");
	printf("�ູ�� : %d\n",status[0]);
	printf("������ : %d\n",status[1]);
	printf("�Ƿε� : %d\n",status[2]);
	printf("========================\n\n");

	while(1)
	{

		printf("���ϴ� Ȱ�� ��ȣ�� �Է��ϼ���(���ڸ�) : ");
		scanf("%d",&act);

		if (act==1) �����ϱ�(status);
		if (act==2) �Ա�(status);
		if (act==3) �������(status);
		if (act==4) ���ڱ�(status);
		if (act==5) ����_����(status);


		printf("\n\n================���� ����================\n");
		printf("              �ູ�� : %d\n",status[0]);
		printf("              ������ : %d\n",status[1]);
		printf("              �Ƿε� : %d\n",status[2]);
		if (status[0]<=min_warning) printf("[����]�ູ���� 10 �̸����� ���������ϴ�. ������� �ɸ����� �����!\n");
		if (status[2]>=max_warning) printf("[����]�Ƿε��� 90�� �ʰ��߽��ϴ�. ���� ���������� �����!\n");
		if (status[1]<=min_warning) printf("[����]�������� 10 �̸����� ���������ϴ�. �谡 ���ļ� ���������� �����!\n");
		if (status[1]<=min_warning) printf("[����]�������� 90�� �ʰ��߽��ϴ�. �谡 �������� �����!\n");
		
		printf("========================================\n\n");

		if ((status[0]<=0) || (status[2]>=100) || (status[1]<=0) || (status[1]>=100)) break;

		show_menu();
	
	}

	if (status[0]<=0) printf("�ູ���� �ʹ� ������ ������� �ɷȽ��ϴ�.\n\n"); 
	if (status[2]>=100) printf("�ʹ� �ǰ��ؼ� ������ �� �����ϴ�.\n\n");
	if (status[1]<=0) printf("�谡 �ʹ� ���ļ� ���������ϴ�.\n\n"); 
	if (status[1]>=100) printf("�谡 �ʹ� �ҷ��� ������ �� �����ϴ�.\n\n");
		
}