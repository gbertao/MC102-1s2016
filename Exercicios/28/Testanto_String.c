#include<stdio.h>
#include<string.h>

int main (void) {
	char texto[20];
	
	printf("Texto: ");
	scanf("%s", texto);

	/*Não funciona, A seria uma variavel
	texto[0] = A;

	printf("%s\n", texto);	
	*/

	texto[3] = 'A';

	printf("%s\n", texto);	

	/*Não funciona char so aceita 1 caracter '51' tem 2
	texto[0] = '51';

	printf("%s\n", texto);	
	*/

	return 0;
}
