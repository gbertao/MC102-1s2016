#include<stdio.h>

int main (void) {

	//Declaração de variaveis
	double custoFabrica, custoDistribuidor, custoImpostos, custosConsumidor;
	
	//Ler o custo de fabrica
	printf("Digite o custo de fabrica: ");
	scanf("%lf", &custoFabrica);

	//Calcular a porcentagem do Distribuidor e Impostos
	custoDistribuidor = custoFabrica * 12/100;
	custoImpostos = custoFabrica * 30/100;

	//Imprimir Custo ao consumidor
	custosConsumidor = custoFabrica + custoDistribuidor + custoImpostos;
	printf("Custo ao consumidor: %0.2f\n", custosConsumidor);
}
