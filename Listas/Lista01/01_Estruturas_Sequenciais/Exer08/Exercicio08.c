#include<stdio.h>

int main (void){
	//Declaração de variaveis
	int anos, meses, dias;

	//ler a idade da pessoa em anos, meses e dias
	printf("Digite a idade em [anos, meses, dias]: ");
	scanf("%d, %d, %d", &anos, &meses, &dias);

	//calcular a idade somente em dias
	dias = anos * 365 + meses * 30 + dias;
	printf("A idade em dias é : %d", dias);
	
	return 0;

}
