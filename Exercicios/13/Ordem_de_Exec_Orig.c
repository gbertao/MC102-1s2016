#include<stdio.h>
int main (void) {
	int n;
	float res;
	printf("Digite um número maior que 0: ");
	scanf("%d",&n);
	/*Original:
	1 + 2 * 30 / (n % 4 * -5)
	Execução na ordem: () > * > / > % > + > - */
	res=1 + 2 * 30 / (n % 4 * -5);
	printf("O Valor da expressao eh: %f\n",res);

	return 0;	
}
