#include<stdio.h>

int main (void) {
	//Declaração de Variaveis
	char tabuleiro[5][5], configuracao[441];
	char alvo;
	int linha, coluna, N, M, indice = 0;
	int tiroL, tiroC;

	//Gerar matriz NxM(tabuleiro)
	scanf("%d %d", &N, &M);
	
	//Configurar tabuleiro apartir das posições
	scanf("%s", configuracao);	
	for(linha = 0; linha < N; linha++) {
		for(coluna = 0; coluna < M; coluna++) {
			tabuleiro[linha][coluna] = configuracao[indice];
			indice++;			
		}
	}
	
	//Verificar se os tiros encontraram algum navio
	while(!0) {
		scanf(" L%dC%d", &tiroL, &tiroC);
		if(tiroL == -1 && tiroC==-1) {
			break;
		}
		tiroL--;
		tiroC--;
		alvo = tabuleiro[tiroL][tiroC];
		//Se acertar um alvo trazer a coordenada dele
		if(alvo == 'B') {
			for(linha = 0; linha < N; linha++) {
				for(coluna = 0; linha < N; coluna++) {
					if(tabuleiro[linha][coluna] == alvo){
						if(linha != tiroL && coluna != tiroC) {
							printf("L%dC%d ", linha+1, coluna+1);
						}
					}
				}
			}
		}

	}


	return 0;
}
