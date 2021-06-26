#include<stdio.h>
int main(void){
	char * vet [20];
	vet[5]="abcd";
	int i=0;
	for(i=0;i<20;++i){
		printf("vet[%d]: %s\n",i,vet[i]);
	}
	return 0;
}
