#include <stdio.h>
#include <malloc.h>

typedef struct person{
	char *name;
	int age;
}Person;


int main(void)
{
	Person building1[5][10];
	Person *building2[5];		//5행마다 각각 n열을 받을 수 있음
	Person **building3;			//n행마다 각각 m열을 받을 수 있음
	Person ***building4;		//이건 무슨 뜻? : 방 한칸에 여러명의 사람. 결국에는 3차. 또는 빌딩3을 여러개 갖고 있는 것

	//3번

	int 층, 방;
	int i,j,size;

	printf("층 몇개 : "); scanf("%d", &층);
	building3 = (Person **)malloc(sizeof(Person *)*층);				//층마다 방을 가리키는 주소가 들어가기 때문에 * 붙이기. (층마다 사람이 들어간다 X)

	if (building3==NULL) {printf("할당 실패!\b"); exit(1); }

	printf("할당된 바이트 : %d , 층 : %d\n\n", _msize(building3), _msize(building3)/sizeof(building3));

	for (i=0; i<층; i++){
		printf("%d층에 방 몇개? : ",i+1); 
		scanf("%d", &방);
		building3[i] = (Person *)malloc(sizeof(Person)*방);
	}

	
	for (i=0; i<층; i++){
		size = _msize(building3[i])/sizeof(*building3[i]);						// *building[i] == **building ???
		//printf("%d, %d\n\n",_msize(building3[i]),sizeof(*building3[i]));

		printf("[%d]층 : ",i+1);
		for (j=0; j<size; j++) 
			if (size==0) printf("방 없음");
			else printf("■");
		printf("\n");
	}
	printf("\n\n");
}