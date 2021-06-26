#include<stdio.h>

int main (void) {
	//Declaração de variaveis
	int totalNumeros, numerosMaiores = 0, indice, ordem = -1, sequencia = 0;
	float fracionarios[100], X, media = 0;

	//1- Ler um numero inteiro N
	printf("Digite o total de numeros fracionarios: ");
	scanf("%d", &totalNumeros);

	//2- Ler uma sequencia de numeros fracionarios
	for (indice = 0; indice < totalNumeros; indice++) {

		printf("Digite um número fracionario: ");
		scanf("%f", &fracionarios[indice]);

	}

	//3- Ler um numero fracionario(X)
	printf("Digite um número fracionario(X): ");
	scanf("%f", &X);

	//4-Verificar se o X esta na sequencia, se sim: verificar a ordem
	for(indice = 0; indice < totalNumeros; indice++) {

		if(X == fracionarios[indice]) {
			
			sequencia = 1;
			ordem = indice + 1;
			break;

		}
	
	}

	//5- Verificar quantos numeros da sequencia são maiores que X
	for (indice = 0; indice < totalNumeros; indice++) {
	
		if( fracionarios[indice] > X) {

			numerosMaiores++;		
			media = media + fracionarios[indice];
		}

	}
	//6- Calcular a média dos numeros maiores
	media = media / numerosMaiores;

	//7- Imprimir: Se pertence a sequencia, a ordem,
	//             quantos são maiores e a média dos maiores.
	printf("%f", X);

	if(sequencia == 1) {

		printf("\nPertence a sequencia: Sim\nOrdem: %d\nNumeros maiores: %d\n", ordem, numerosMaiores);

		if(numerosMaiores != 0) {
		
			printf("Média dos numeros maiores: %f\n",media);

		}

	} else {
	
		printf("\nPertence a sequencia: Não\n");

	}

	return 0;
}
