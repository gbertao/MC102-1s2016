#include<stdio.h>

int main (void) {
	//Declaração de Variavel
	float vetor[20], elemento;
	int indice, ordem;
	
	//Ler um vetor de 20 posicoes
	for (indice = 0; indice < 20; indice++) {
		printf("Digite os elementos do vetor: ");
		scanf("%f", &vetor[indice]);
	}	

	//Verificar elementos
	elemento = vetor[0];
	ordem = 0;
	for(indice = 1; indice < 20; indice ++) {
		if (vetor[indice] < elemento) {
			elemento = vetor[indice];
			ordem = indice;
		}
	}

	//Saida
	printf("O menor elemento de N é, %f, e sua posição dentro do vetor é: %d\n", elemento, ordem);

	return 0;
}
