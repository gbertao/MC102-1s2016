#include<stdio.h>

int main (void) {
	//Declaração de variaveis
	int A, linha, coluna, valoresIguais = 0;
	float V[10][10], X[10][10];

	//Ler o inteiro A
	printf ("Digite um valor de A: ");
	scanf("%d", &A);

	//Completar uma matriz V 10x10
	for(linha = 0; linha < 10; linha++) {
		for (coluna = 0; coluna < 10; coluna++) {
			printf("Complete a linha %d: ", linha);
			scanf("%f", &V[linha][coluna]);
			
	//Procurar valores iguas a A e
	//Criar uma Matriz X com os valores diferentes de A
			if(V[linha][coluna] == A) {
				valoresIguais++;
				X[linha][coluna] = '\0';
			} else {
				X[linha][coluna] = V[linha][coluna];
			}
		}
	}

	//Resultados
	for(linha = 0; linha < 10; linha++) {
		for(coluna = 0; coluna < 10; coluna++) {
			printf("%.2f ", X[linha][coluna]);
		}
		printf("\n");
	}
	printf("A Matriz V tem %d valores iguais\n", valoresIguais);

	return 0;
}
