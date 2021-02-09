#include <stdio.h>

int main(void)
{
	int ar[3][5] = {0};
	int i,j,k=1;

	for(i=0; i<3; i++)
        for(j=0; j<5; j++)
			ar[i][j]=k++;

	printf("  이름             주소            값(10진수)       type          size   \n");
	printf("---------------------------------------------------------------------------\n");
	printf("        ar  :    %10d    %10d         int[3][5] %5d bytes \n", &ar[3][5], ar, sizeof(ar));

	for (i=0; i<3; i++){
		printf("     ar[%d]  :    %10d    %10d         int[5]     %5d bytes \n", i, &ar[i], ar[i], sizeof(ar[i]));
		for (j=0; j<5; j++){
			printf("  ar[i][j]  :    %10d    %10d         int       %5d bytes \n", &ar[i][j], ar[i][j], sizeof(ar[i][j]));
		}
	}
}