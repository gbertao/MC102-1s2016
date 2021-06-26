/*Laboratório 00c - Médias de Notas - Giovanni Bertao*/
#include<stdio.h>
int main (void){
	int nota1,nota2,nota3;
	float media;
	
	scanf("%d %d %d",&nota1, &nota2, &nota3);

	media =(float)(nota1+nota2+nota3)/3;

	if(media>=5){
		printf("Aprovado com media %.1f\n",media);
	}else{
		printf("Reprovado com media %.1f\n",media);
	}

	return 0;
}
