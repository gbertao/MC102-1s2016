/*Programa que inverte a ordem de uma sequencia de 3 inteiros sem espaço*/
#include<stdio.h>
int main(void){
	int a,b,c;

	printf("Digite os 3 numeros: ");
	scanf("%d %d %d",&a,&b,&c);

	printf("Invertendo a ordem sem espaço: %d%d%d\n",c,b,a);

	return 0;
}
