#include<stdio.h>

int main (void) {

	//declaração de variaveis
	int horas, minutos, segundos;

	//Ler a duração de um evento em segundos
	printf("Digite a duração em segundos: ");
	scanf("%d", &segundos);

	//Expressar ele em horas: minutos : segundos
	horas = segundos / 3600;
	minutos = segundos % 3600 / 60;
	segundos = segundos % 3600 % 60;

	printf("%d : %d : %d", horas, minutos, segundos);
	
	return 0;

}
