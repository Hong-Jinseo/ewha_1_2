///////////// 앞 파일이랑 합치기



Person *makePerson1(int size){
	return (Person*) malloc(sizeof(Person)*size);
}	//성공실패 여부 메인에서 한번 더 확인해야함

void makePerson2(Person**p_addr, int size){
	*p_addr = (Person*) malloc(sizeof(Person)*size);
	
	if (*p_addr==NULL){
		printf("할당실패 \n");
		return NULL;
	}
	return 1;
}


int main(void){
	int signal;

	signal = makePerson2(&p, how_many);

	if (signal==NULL){
		printf("할당 실패\n");
		exit(1);
}