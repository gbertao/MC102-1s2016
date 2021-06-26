#include<stdio.h>

int main (void) {
	//Declaração de variaveis
	float M[6][6], V[36], A;
	int indice = 0, linha, coluna;

	//Ler uma matriz 6x6
	for (linha = 0; linha < 6; linha ++) {
		for (coluna = 0; coluna < 6; coluna++) {
			printf("Complete a linha %d, da matriz: ", linha);
			scanf("%f", &M[linha][coluna]);
		}
	}

	//multiplicar a matriz por A
	printf("Digite A: ");
	scanf("%f", &A);

	for (linha = 0; linha < 6; linha++) {
		for(coluna = 0; coluna < 6; coluna++) {
			V[indice] = A * M[linha][coluna];
			indice++;
		}
	}
	//armazenar o restultado em um vetor de 36 posicoes
	//retornar vetor
	printf("Vetor Resultante: ");
	for (indice = 0; indice < 36; indice ++) {
		printf("%f ", V[indice]);
	}
	printf("\n");

	return 0;
}
