typedef struct weapon{
	char name[100];		//�����̸�
	int power;			//���� �ɷ�ġ
}Weapon;

typedef struct palyer{
	char name[100];		//����� �̸�
	Weapon *w;			//struct weapon ������	//�����ͷ� �ᵵ ��
	int power;			//����� �ɷ�ġ
	int defensivePower;	//����� ����	//�ִ� 10
	int hp;				//����� ü��
}Player;