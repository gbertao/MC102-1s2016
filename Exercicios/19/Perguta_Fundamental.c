//Este programa ira julgar se uma dada expressão é uma pergunta fundamental. Ou seja, se o seu resultado é igual a 42

#include<stdio.h>
int main (void){
	
	int num1,num2;
	char op;
	float res;

		printf("Digite uma pergunta fundamental: ");
	do{
		scanf("%d %c %d",&num1,&op,&num2);

		switch (op) {
			case '+':
				res=num1+num2;
				break;
			case '-':
				res=num1-num2;
				break;
			case '*':
				res=num1*num2;
				break;
			case '/':
				res=num1/num2;
				break;
		}
		if (res==42) {
			printf("Obrigado!\n");
		} else {
			printf("Esta não é uma pergunta fundamental, tente denovo: ");
		}
	}while(res!=42);
}
