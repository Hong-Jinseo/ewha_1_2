typedef struct Birthday{
	int year, month, day;
}Birth;

typedef struct classes{
	char title[20];
	char prof[9];
	char grade[3];
}Classes;

typedef struct student{
	//�а� �й� �̸�
	char dept[30];
	char sid[8];
	char name[9];
	Birth B;
	Classes C[3];	
}Student;