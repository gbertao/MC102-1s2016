#include<stdio.h>

int main (void) {
	//declaração de variaveis
	int matriz[6][6], aux[6][6], linha, coluna;
	
	//lEr uma matriz 6x6
	for(linha = 0; linha < 6; linha++) {
		for(coluna = 0; coluna < 6; coluna++) {
			printf("Preencha a matriz 6x6: ");
			scanf(" %d", &matriz[linha][coluna]);
		}
	}

	//trocar 1 coluna com 2 coluna
	for(coluna = 0; coluna < 6; coluna++) {
		aux[0][coluna]= matriz[1][coluna];
		aux[1][coluna]= matriz[0][coluna];
	}

	//trocar 3 c com 4c
	for(coluna = 0; coluna < 6; coluna++) {
		aux[2][coluna]= matriz[3][coluna];
		aux[3][coluna]= matriz[2][coluna];
	}
	
	//trocar 5c com 6c
	for(coluna = 0; coluna < 6; coluna++) {
		aux[4][coluna]= matriz[5][coluna];
		aux[5][coluna]= matriz[4][coluna];
	}

	//Saida
	for(linha = 0; linha < 6; linha++) {
		for(coluna = 0; coluna < 6; coluna++) {
			printf("%d ", aux[linha][coluna]);
		}
		printf("\n");
	}	

	return 0;
}
