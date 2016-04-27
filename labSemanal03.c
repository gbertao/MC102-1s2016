//Giovanni Bertão - ra173325 - Turma: Y
#include<stdio.h>
#include<math.h>

int main (void) {
	//Declaração de variaveis
	unsigned char Red[600][600], Green[600][600], Blue[600][600], Cinza[600][600];
	int Filtro[10][10], matrizNova[600][600], divisor, op = 0, ordem;
	unsigned char Codigo[1080000]; 
	unsigned int linha, coluna, altura, largura, priPonto, linhaF, colunaF, h, k;
	unsigned int indice = 0, j = 0, multiplicador = 0, elemento = 0;

	scanf("%d", &divisor);
	scanf(" %d", &ordem);
	
	for(linhaF = 0; linhaF < ordem; linhaF++) {
		for(colunaF = 0; colunaF < ordem; colunaF++) {
			scanf(" %d", &Filtro[linhaF][colunaF]);
		}
	}

	scanf("%u %u", &largura, &altura);

	//1ºPasso: Descomprimir as matrizes Red, Green, Blue
	//Descomprimir RLE
	while(indice < largura * altura * 3) {
		scanf(" %u %u", &multiplicador, &elemento);
		
		for(j = 0; j < multiplicador; j++) {
			Codigo[indice] = elemento;
			indice++;
		}	
	}
	
	//Completar as Matrizes
	indice = 0;
	for(linha = 0; linha < altura; linha++) {
		for(coluna = 0; coluna < largura; coluna++) {
			Red[linha][coluna] = Codigo[indice];
			indice++;
		}
	}

	for(linha = 0; linha < altura; linha++) {
		for(coluna = 0; coluna < largura; coluna++) {
			Green[linha][coluna] = Codigo[indice];
			indice++;
		}
	}

	for(linha = 0; linha < altura; linha++) {
		for(coluna = 0; coluna < largura; coluna++) {
			Blue[linha][coluna] = Codigo[indice];
			indice++;
		}
	}
	
	//2ºPasso: Transformar em escala de Cinza
	for(linha = 0; linha < altura; linha++) {
		for(coluna = 0; coluna < largura; coluna++) {
			Cinza[linha][coluna] = (Red[linha][coluna] + Green[linha][coluna] + Blue[linha][coluna])/3;
		}
	}	
	
	//3ºPasso: Filtragem
	//encontrar 1º ponto a ser alterado 
	//!!!Não serão alteradas: Linhas e colunas < priPonto, linhas >= altura - priPonto e colunas >= largura - priPonto.
	priPonto = (ordem - 1) / 2;
	h = -priPonto;
	k = -priPonto;

	//Convolução
	for(linha = 0; linha < altura; linha++) {
		for(coluna = 0; coluna < largura; coluna++) {
			if(linha < priPonto || coluna < priPonto) {
				matrizNova[linha][coluna] = Cinza[linha][coluna];
			} else if(linha >= altura - priPonto) {
				matrizNova[linha][coluna] = Cinza[linha][coluna];
			} else if(coluna >= largura - priPonto) {
				matrizNova[linha][coluna] = Cinza[linha][coluna];
			} else {
				for(linhaF = 0; linhaF < ordem; linhaF++) {
					for(colunaF = 0; colunaF < ordem; colunaF++) {
						op = op + (Filtro[linhaF][colunaF] * Cinza[linha + h][coluna + k]);
						k++;
					}
					h++;
					k = -priPonto;
				}
				h = -priPonto;
				op = op / divisor;
				if(op < 0) {
					op = 0;
				} else if(op > 255) {
					op = 255;
				}
				matrizNova[linha][coluna] = op;
				op = 0;
			}
		}
	}
	
	//Saida
	printf("P2\n%d %d\n255\n", largura, altura);
	for(linha = 0; linha < altura; linha++) {
		for(coluna = 0; coluna < largura; coluna++) {
			printf("%d ", matrizNova[linha][coluna]);
		}
		printf("\n");
	}


	return 0;
}
