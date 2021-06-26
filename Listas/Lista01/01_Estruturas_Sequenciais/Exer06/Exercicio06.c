#include<stdio.h>

int main (void) {
	//declaração de variaveis
	double a11, a12, a21, a22, determinante;

	//Ler valores da Matriz 2x@
	printf("Digite o elemento a11: ");
	scanf(" %lf", &a11);
	printf("Digite o elemento a12: ");
	scanf(" %lf", &a12);
	printf("Digite o elemento a21: ");
	scanf(" %lf", &a21);
	printf("Digite o elemento a22: ");
	scanf(" %lf", &a22);

	//Calcular a determinante
	determinante = (a11 * a22) - (a21 * a12);

	printf("Determinante: %lf", determinante);

	return 0;
}
