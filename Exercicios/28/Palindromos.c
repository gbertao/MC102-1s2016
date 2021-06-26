#include<stdio.h>
#include<string.h>

int main (void) {
	//declaração de variaveis
	char texto[80], textoEspelhado[80], temp;
	int resultado, letras, indice, indice2 = 0;

	//Receber palavra
	printf("Digite a palavra: ");
	scanf("%s", texto);

	//Inverter palavra
	for(indice = 0; texto[indice] != '\0'; indice++) {

		letras = indice + 1;	

	}

	for (indice2 = 0; indice2 < letras; indice2++) {
	
		indice--;	
		textoEspelhado[indice2] = texto[indice];

	} 

	textoEspelhado[indice2]=texto[letras];

	//Comparar as duas palavras
	for(indice = 0; indice < letras; indice++) {

		if (texto[indice] == textoEspelhado[indice]) {

			resultado = 0;

		} else {

			resultado = 1;			

		}

	}	
		
	if (resultado == 0) {

		printf("É Palindromo\n");

	} else {

		printf("Não é palindromo\n");

	}

	return 0;
}
