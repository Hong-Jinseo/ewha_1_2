///////////// �� �����̶� ��ġ��



Person *makePerson1(int size){
	return (Person*) malloc(sizeof(Person)*size);
}	//�������� ���� ���ο��� �ѹ� �� Ȯ���ؾ���

void makePerson2(Person**p_addr, int size){
	*p_addr = (Person*) malloc(sizeof(Person)*size);
	
	if (*p_addr==NULL){
		printf("�Ҵ���� \n");
		return NULL;
	}
	return 1;
}


int main(void){
	int signal;

	signal = makePerson2(&p, how_many);

	if (signal==NULL){
		printf("�Ҵ� ����\n");
		exit(1);
}