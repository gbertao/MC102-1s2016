#include<stdio.h>

int main (void) {
	//Declaração de Variaveis
	int pesoSaco, qtdGato1, qtdGato2, qtdGasta, resto;

	//Receber o peso do saco de racao, a quantidade que para cada gato
	printf("Digite o peso do saco, a quantidade dia dos gatos: ");
	scanf("%d %d %d", &pesoSaco, &qtdGato1, &qtdGato2);

	//mostre a quantidade de ração que restara após 5 dias
	qtdGasta = 5 * (qtdGato1 + qtdGato2);
	resto = (pesoSaco * 1000) - qtdGasta;

	printf("Após 5 dias restará: %dg\n", resto);

	return 0;

}
