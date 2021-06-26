#include<stdio.h>
#include<math.h>
#include<string.h>

int main (void) {
	//Declaração de variaveis
	char string[100], matriz[10][10];
	int raiz, tamanhoString, indice = 0, linha, coluna;
	
	//Ler tamanho da string e a string
	printf("Digite a mensagem: ");
	scanf("%s", string);

	//ver a raiz do tamanho da string
	tamanhoString = strlen(string);
	raiz = sqrt(tamanhoString);	

	//criar uma matriz NxN onde N é a raiz anterior
	//Prencher a matriz com a string
	for (linha = 0; linha < raiz; linha++) {
		for(coluna = 0; coluna < raiz; coluna++) {
			matriz[linha][coluna] = string[indice];
			indice++;
		}
	}
	
	//Transformar as colunas das matrizes em strings
	indice = 0;
	for (coluna = 0; coluna < raiz; coluna++) {
		for (linha = 0; linha < raiz; linha++) {
			string[indice] = matriz[linha][coluna];
			indice++;
		}
	}

	//Imprimir a mensagem
	printf("%s\n", string);

	return 0;
}
