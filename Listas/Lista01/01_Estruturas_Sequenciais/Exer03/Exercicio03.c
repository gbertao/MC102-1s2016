#include<stdio.h>
#include<math.h>

int main (void) {
	//Declarar variaveis
	double L1, L2, L3;
	double T, area;

	//Ler os 3 lados do triangulo
	printf("Digite os 3 lados do triangulo: ");
	scanf ("%lf %lf %lf", &L1, &L2, &L3);

	//Calcular o Semiperimetro(T)
	T = (L1 + L2 + L3) / 2;

	//Imprimir a area
	area = T * (T - L1) * (T - L2) * (T - L3);
	area = sqrt(area);

	printf("A Área do triangulo vale: %f", area);

	return 0;
}
