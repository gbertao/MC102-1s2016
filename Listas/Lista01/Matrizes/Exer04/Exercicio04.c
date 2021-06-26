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
	for(linha = 0; linha < 6; linha++) {
		aux[linha][0] = matriz[linha][1];
		aux[linha][1] = matriz[linha][0];
	}

	//trocar 3 c com 4c
	for(linha = 0; linha < 6; linha++) {
		aux[linha][2] = matriz[linha][3];
		aux[linha][3] = matriz[linha][2];
	}
	
	//trocar 5c com 6c
	for(linha = 0; linha < 6; linha++) {
		aux[linha][4] = matriz[linha][5];
		aux[linha][5] = matriz[linha][4];
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
