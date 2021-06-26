//ordene o vetor
#include<stdio.h>

int main (void) {
	int vetor[10], i, elemento, cont=0;

	for(i = 0; i< 5; i++) {
		scanf("%d", &vetor[i]);
	}
	
	for(i = 1; i < 5; i++) {
		elemento = vetor[0];
		if(elemento > vetor[i]) {
			vetor[i-cont] = vetor [i];
			vetor[i] = elemento;
			i = 0;
		}
		cont++;
	}
for(i=0; i < 5; i++){
printf("%d ", vetor[i]);
}
	return 0;
}
