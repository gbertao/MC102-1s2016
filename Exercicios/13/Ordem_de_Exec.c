#include<stdio.h>
int main (void) {
	int n;
	float opAux1,opAux2;
	printf("Digite um número maior que 0: ");
	scanf("%d",&n);
	/*Original:
	1 + 2 * 30 / (n % 4 * -5)
	Execução na ordem: () > * > / > % > + > - */
	
	//Parentese
	opAux1= n % 4;
	opAux1= opAux1 * -5;

	opAux2= 2 * 30;
	opAux1= opAux2/opAux1;
	opAux1= 1+opAux1;
	
	printf("O Valor da expressao eh: %f\n",opAux1);

	return 0;	
}
