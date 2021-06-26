#include<stdio.h>

int main (void) {
	//delcaração de variaveis
	float vetor1[10], vetor2[10], vetor3[10];
	int indice;

	//Ler dois vetores de 10 posicoes
	for (indice = 0; indice < 10; indice++) {
		printf("Complete o primeiro vetor: ");
		scanf("%f", &vetor1[indice]);
	}
	for (indice =0; indice < 10; indice++) {
		printf("Complete o segundo vetor: ");
		scanf("%f", &vetor2[indice]);
	}

	//multiplicar elementos de mesmo indice e armazenar em outro vetor
	for (indice = 0; indice < 10; indice++) {
		vetor3[indice] = vetor1[indice] * vetor2[indice];
	}

	//Resultado
	printf("Vetor Resultante: {");
	for( indice = 0; indice < 10; indice++) {
		if(indice == 9) {
			printf("%.2f", vetor3[indice]);
		} else {
			printf("%.2f, ", vetor3[indice]);
		}
	}
	printf("}\n");

	return 0;
}
