#include<stdio.h>

int main (void) {
	//Declaração de variaveis
	int tamVetor, vetor[100], contador;
	int repete[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int numero = -1;

	//Definir tamanho de um vetor
	do{
		
		printf("Digite o tamanho do vetor(Max 100): ");
		scanf("%d", &tamVetor);
	
	}while(tamVetor > 100);

	//Ler um vetor de numeros(de 1 a 9)
	printf("Digite um vetor com %d elementos, que variam de 1 a 9: ", tamVetor);

	for(contador = 0; contador < tamVetor; contador++) {
	
		scanf(" %d,", &vetor[contador]);
		
	}

	//Checar quantas vezes um numero se repete
	for(contador = 0; contador <tamVetor; contador++) {

		switch(vetor[contador]) {

			case 1:
				repete[0]++;
				break;

			case 2:
				repete[1]++;
				break;

			case 3:
				repete[2]++;
				break;

			case 4:
				repete[3]++;
				break;

			case 5:
				repete[4]++;
				break;

			case 6:
				repete[5]++;
				break;

			case 7:
				repete[6]++;
				break;

			case 8:
				repete[7]++;
				break;

			case 9:
				repete[8]++;
				break;

		}
	}
	
	//Verificar qual numero mais se repete
	for(contador = 0; contador < 9; contador++) {
		
		if (repete[contador] > numero) {

			numero = repete[contador];

		}
	
	}

	//Linhas do histograma
	printf("+---------+\n");
	for(numero = numero; numero > 0; numero--) {
	
		printf("|");

		for(contador = 0; contador < 9; contador++) {
			
			if(repete[contador] >= numero) {

				printf("*");

			} else {

				printf(" ");

			}

		}

		printf("|\n");

	}
	printf("+---------+\n");	
	printf(" 123456789 \n");

	return 0;
}
