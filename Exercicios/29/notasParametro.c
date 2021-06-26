#include<stdio.h>
float mediaProvas(int numProvas);

int main (void) {
	
	int numProvas;
	float media;

	printf("Digite o numero de provas: ");
	scanf("%d", &numProvas);

	media = mediaProvas(numProvas);

	printf("A media das provas é: %0.2f\n", media);

	return 0;
}

float mediaProvas (int numProvas) {

	int questoes, prova, contador;
	float valorQuestao, total = 0;	
	
	for(prova = 1; prova <= numProvas; prova++) {

		printf("Prova %d:\n", prova);
		printf("Digite o numero de questões: ");
		scanf("%d", &questoes);

		for(contador = 1; contador <= questoes; contador++) {

			printf("Digite o valor da questão %d: ", contador);
			scanf("%f", &valorQuestao);
			
			total = total + valorQuestao;
		}

	}
	
	total = total / numProvas;

	return total;

}
