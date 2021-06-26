#include<stdio.h>

int main (void) {
	//Declaração de variaveis
	int x, y;

	//Ler dois valores inteiros
	printf("Digite X e Y: ");
	scanf("%d %d", &x, &y);
	
	//inverter os valores
	y = y - x;
	x = y + x;
	y = x - y;

	printf("X: %d Y: %d\n", x, y);
	
	return 0;
}
