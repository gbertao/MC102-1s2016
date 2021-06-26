#include<stdio.h>

int main (void) {
	//Declaração de variaveis
	int matriz[5][7], linha, coluna, elemento;
	int elemento[7], i = 0;

	//Criar matriz 5x7
	for(linha = 0; linha < 5; linha++) {
		for(coluna = 0; coluna < 7; coluna++) {
			printf("Complete a matriz 5x7: ");
			scanf("%d", &matriz[linha][coluna]);
		}
	}

	//Verificar o menor elemento de cada linha
	for(linha = 0; linha < 5; linha++) {
		elemento[i] = matriz[linha][0];
		for(coluna = 1; coluna < 7; coluna++) {
			if(elemento[i] >  matriz[linha][coluna]) {
				elemento[i] = matriz[linha][coluna];
			}
		}
		i++;
	}
	//Verificar se o elemento é o maior da coluna
	i = 0;
	for(linha = 0; linha < 5; linha++) {
		if(elemento[i] < matriz[linha][i]) {
			resposta = 0;
			break;
		} else {
			resposta = 1;
		}
	}

	return 0;
}	
