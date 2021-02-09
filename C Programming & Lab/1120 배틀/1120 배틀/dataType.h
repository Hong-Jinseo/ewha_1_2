typedef struct weapon{
	char name[100];		//무기이름
	int power;			//무기 능력치
}Weapon;

typedef struct palyer{
	char name[100];		//사용자 이름
	Weapon *w;			//struct weapon 가져옴	//포인터로 써도 됨
	int power;			//사용자 능력치
	int defensivePower;	//사용자 방어력	//최대 10
	int hp;				//사용자 체력
}Player;