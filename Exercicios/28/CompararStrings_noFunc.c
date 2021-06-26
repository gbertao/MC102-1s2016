#include<stdio.h>
#include<string.h>

int main (void) {
	//Declaração de variaveis
	char texto1[80], texto2[80];
	int r, letraT1, letraT2, a;

	//Completar as strings
	printf("Texto1: ");
	scanf("%s", texto1);

	printf("Texto2: ");
	scanf("%s", texto2);

	//Comparar Textos
	for( r = 0; a == 0; r++) {
			
		letraT1 = texto1[r];
		letraT2 = texto2[r];
		a = letraT1 - letraT2;

		if(a < 0) {

			printf("%s vem antes de %s", texto1, texto2); break;
		}else if(a>0) {
			printf("%s vem antes de %s", texto2, texto1);break;
		}
		
	}
			
	return 0;

}
