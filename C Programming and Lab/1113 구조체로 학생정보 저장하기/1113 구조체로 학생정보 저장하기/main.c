#include <stdio.h>
#include "pratice.h"

int main(void)
{
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	Student s[100];
	int i=0, j, n;

	fp1 = fopen("C:\\홍진서\\test.txt", "r");
	fp2 = fopen("C:\\홍진서\\result.txt", "w");

	printf("파일을 가져오는 중\n\n");

	if (fp1!=NULL){
		while (!feof(fp1)){
			fscanf(fp1, "%s", s[i].dept);
			fscanf(fp1, "%s", s[i].sid);
			fscanf(fp1, "%s", s[i].name);
		
			fscanf(fp1, "%d", &s[i].B.year);
			fscanf(fp1, "%d", &s[i].B.month);
			fscanf(fp1, "%d", &s[i].B.day);

			for (j=0; j<3; j++){
				fscanf(fp1, "%s", s[i].C[j].title);
				fscanf(fp1, "%s", s[i].C[j].prof);
				fscanf(fp1, "%s", s[i].C[j].grade);}
			i++;
		}
	}
	else {
		printf(" !! 파일 열기 실패 !!\n");
		exit(1);
	}
	
	printf("파일 열기 완료\n\n");

	n=i;
	for(i=0;i<n; i++){
		fprintf(fp2, "num.%d \n", i+1);
		fprintf(fp2, "%s  %s  %s\n", s[i].dept, s[i].sid, s[i].name);
		fprintf(fp2, "%d년 %d월  %d일 생\n", s[i].B.year, s[i].B.month, s[i].B.day);
		fprintf(fp2, "                     [과목명]             [교수님]             [성적]\n");
		for(j=0; j<3; j++)
			fprintf(fp2, "과목 %d : %20s       %s 교수님        %s \n", j+1, s[i].C[j].title, s[i].C[j].prof, s[i].C[j].grade);
		fprintf(fp2, "===========================================\n");
	}

	printf("파일 저장 완료\n\n");

	fclose(fp1);
	fclose(fp2);
	return 0;
}