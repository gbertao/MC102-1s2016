#include<stdio.h>

int main (void) {
	//declaração de variaveis
	double A, B, C, discriminante;

	//Ler Coeficientes
	printf("Digite os Coeficientes: ");
	scanf("%lf %lf %lf", &A, &B, &C);

	//Imprimir discriminante
	discriminante = (B * B) - (4 * A * C);

	printf("O discriminante vale: %f\n", discriminante);

	return 0;
}
