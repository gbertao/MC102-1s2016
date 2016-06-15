//Giovanni Bertão
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Estruturas
struct doenca {
	char cod[4];
	char nome[101];
};

struct medico {
	char crm[7];
	char nome[101];
};

struct consulta {
	char nome[101];
	char data[11];
	char cod_Doenca[4];
	char crm[7];
};

enum opcoes {sair = 0, add = 1, rm = 2, altdiag = 3, altdata = 4, altmed = 5}; 

//Assinatura de Funções
int leropcao (void);

int main (void) {
	//Declaração de Variaveis
	int n, m, i;
	char letra;
	enum opcoes op;

	//Doenças
	scanf(" %d", &n);
	//Criar vetor para armazenar as doenças utilizando alocação de memória dinâmica
	struct doenca * doencas;
	doencas = (struct doenca*) malloc(sizeof(struct doenca) * n);
	//Tratamento de Erro
	if(doencas == NULL) {
		printf("ERRO AO ALOCAR MEMÓRIA PARA O VETOR: doencas\n");
		return 1;
	}
	//Completar vetor
	for(i = 0; i < n; i ++) {
		scanf(" %s", doencas[i].cod);
		scanf(" %[^ \n]s", doencas[i].nome);
	}

	//Médicos
	scanf(" %d", &m);
	//Criar vetor para Médicos
	struct medico * medicos;
	medicos = (struct medico*) malloc(sizeof(struct medico) * m);
	//Tratamento de Erro
	if(medicos == NULL) {
		printf("ERRO AO ALOCAR MEMÓRIA PARA O VETOR: medicos\n");
		return 1;
	}
	//Completar Vetor
	for(i = 0; i < m; i++) {
		scanf(" %s", medicos[i].crm);
		scanf(" %[^ \n]s", medicos[i].nome);
	}

	//Letra que deve ser iniciada a impressão do relatório
	scanf("%c", &letra);

	//Comandos
	do{
		op = leropcao();
		switch(op) {
			case add:
				break;
			case rm:
				break;
			case altdiag:
				break;
			case altdata:
				break;
			case altmed:
				break;
			case sair:
				break;
		}
	}while(op != sair);

	//Liberar memória Alocada
	free(doencas);
	free(medicos);

	return 0;
}

int leropcao (void) {
	int op;
	char opcao[8];

	scanf(" %s", opcao);

	if(strcmp(opcao, "sair") == 0) {
		op = 0;
	} else if(strcmp(opcao, "add") == 0) {
		op = 1;
	} else if(strcmp(opcao, "rm") == 0) {
		op = 2;
	} else if(strcmp(opcao, "altdiag") == 0) {
		op = 3;
	} else if(strcmp(opcao, "altdata") == 0) {
		op = 4;
	} else if(strcmp(opcao, "altmed") == 0) {
		op = 5;
	}

	return op;
}
