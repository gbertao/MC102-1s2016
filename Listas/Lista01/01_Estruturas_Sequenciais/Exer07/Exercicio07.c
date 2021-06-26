#include<stdio.h>

int main (void) {
	//Declaração de variaveis
	int horasUsadas, total, acada3hr, acada1hr;
	
	//Ler o total de horas que a charrete foi usada
	printf("Digite o total de horas que a charrete foi usada: ");
	scanf("%d", &horasUsadas);

	//Calcular o total a pagar
	acada3hr = horasUsadas / 3;
	acada1hr = horasUsadas % 3;

	total = acada3hr * 10 + acada1hr * 5;

	printf("O total a pagar é: %d", total);	

	return 0;
}
