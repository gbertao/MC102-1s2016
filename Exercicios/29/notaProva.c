#include<stdio.h>

float nota_da_prova (void) {

	float questao, valorQuestao, valorProva = 0;
	int contador;

	printf("Digite o número de questão da prova: ");
	scanf("%f", &questao);

	for(contador = 1; contador <= questao; contador++) {

		printf("Digite o valor da questão %d: ", contador);
		scanf("%f", &valorQuestao);

		valorProva = valorProva + valorQuestao;

	}

	return valorProva;
}

int main (void) {

	float nota;

	nota = nota_da_prova();

	printf("A prova vale: %f\n", nota);

	return 0;
}
