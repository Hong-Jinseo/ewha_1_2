typedef struct weapon{
	char *name;			//�����̸�		//�����Ҵ��� �̿��� ������ ��
	int power;			//���� �ɷ�ġ
}Weapon;

typedef struct palyer{
	char *name;			//����� �̸�
	Weapon *w;			//struct weapon ������	//�����ͷ� �ᵵ ��
	int power;			//����� �ɷ�ġ
	int defensivePower;	//����� ����	//�ִ� 10
	int hp;				//����� ü��
}Player;