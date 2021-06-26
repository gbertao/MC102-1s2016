#include<stdio.h>
#include<string.h>

int main (void) {
	//Declaração de variaveis
	char texto1[80], texto2[80];
	int r;

	//Completar as strings
	printf("Texto1: ");
	scanf("%s", texto1);

	printf("Texto2: ");
	scanf("%s", texto2);

	//Comparar as strings
	r = strcmp(texto1, texto2);

	if(r == 0) {

		printf("São as mesmas palavras\n");
	
	} else if (r < 0) {
		
		printf("%s vem antes de %s\n", texto1, texto2);
	
	} else {
		
		printf("%s vem antes de %s\n", texto2, texto1);

	}

	return 0;

}
