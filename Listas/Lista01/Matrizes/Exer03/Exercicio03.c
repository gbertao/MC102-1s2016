#include<stdio.h>

int main (void) {
	// Declaração de variaveis
	int matriz[5][5], linha, coluna, linha4 = 0, coluna2 = 0, diagonalP = 0, diagonalS = 0, total = 0;

	//Ler uma matriz 5x5
	for(linha = 0; linha < 5; linha++) {
		for(coluna = 0; coluna < 5; coluna++) {
			printf("Preencha a matriz 5x5: ");
			scanf(" %d", &matriz[linha][coluna]);
		}
	}

	//Calcular a soma da linha 4
	for(coluna = 0; coluna < 5; coluna++) {
		linha4 = linha4 + matriz[3][coluna];
	}	

	//Calcular a soma da coluna 2
	for(linha = 0; linha < 5; linha++) {
		coluna2 = coluna2 + matriz[linha][1];
	}

	//calcular a soma da diagonal principal
	//onde linha = coluna
	for(linha = 0, coluna = 0; linha < 5; linha++, coluna++) {
		diagonalP = diagonalP + matriz[linha][coluna];
	}

	//Calcular a soma da diagonal secundaria
	//onde [matriz]K x 4-k
	for(linha = 0, coluna = 4; linha < 5; linha++, coluna--) {
		diagonalS = diagonalS + matriz[linha][coluna];
	}
	
	//Calcular a soma de todos os elementos da matriz M
	for(linha = 0; linha < 5; linha++) {
		for(coluna = 0; coluna < 5; coluna++) {
			total = total + matriz[linha][coluna];
		}
	}
	
	//Saida
	printf("a) %d\n", linha4);
	printf("b) %d\n", coluna2);
	printf("c) %d\n", diagonalP);
	printf("d) %d\n", diagonalS);
	printf("e) %d\n", total);
	return 0;
}
