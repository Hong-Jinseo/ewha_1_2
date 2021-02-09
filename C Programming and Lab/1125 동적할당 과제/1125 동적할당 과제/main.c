#include <stdio.h>
#include <malloc.h>

int main(void){
	char *p;
	int size = 100000;
	int i=1, total=0;

	while(1){
		p = (char*)malloc(sizeof(char)*size);
	
		if (p==NULL){	//반환값이 NULL 이면 break
			printf("할당 실패\n");
			break;
		}

		total += _msize(p);
		printf("[num %d] ",i);
		printf("&p : %p, p : %p, p에 할당된 공간 : %d bytes, 지금까지 할당된 공간의 크기 : %d bytes\n\n",&p,p,_msize(p),i*size);
		i++;

		printf("할당 크기 : ");
		scanf("%d",&size);
		realloc(p, sizeof(int)*size);

		printf("&p : %p, p : %p, p에 할당된 공간 : %d bytes, 지금까지 할당된 공간의 크기 : %d bytes\n",&p,p,_msize(p),i*size);
		printf("할당된 공간 크기 : %d bytes\n",_msize(p));
		printf("할당받은 총 크기 : %d bytes\n\n",total);
		free(p);

		//free(p);
	}
}