//Giovanni Bertão -- parei na linha 180
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

struct consulta {//Elemento da lista ligada
	char nome[101];
	char data[11];
	char cod_Doenca[4];
	char crm[7];
	struct consulta *proximo;
};

enum opcoes {sair = 0, add = 1, rm = 2, altdiag = 3, altdata = 4, altmed = 5}; 

//Assinatura de Funções
int leropcao (void);
void Descriptografar_Matriz(int chave[][2], int chaveInv[][2]);
void inserir(struct consulta * inicio, int chaveInv[][2]);
void descriptografar(char nome[101], char nomeReal[101], int chaveInv[][2]);

int main (void) {
	//Declaração de Variaveis
	int n, m, i, matrizChave[2][2], mChaveInv[2][2];
	char letra;
	enum opcoes op;
	struct consulta *inicio_lista;
	
	//Lista Vazia
	inicio_lista = NULL;

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
		scanf(" %[^\n]s", doencas[i].nome);
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
		scanf(" %[^\n]s", medicos[i].nome);
	}
	
	//Completar Matriz Chave
	for(i = 0; i < 2; i++) {
		scanf(" %d %d", &matrizChave[i][0], &matrizChave[i][1]);
	}

	//Letra que deve ser iniciada a impressão do relatório
	scanf(" %c", &letra);

	//Encontrar Matriz para Descriptografar
	Descriptografar_Matriz(matrizChave, mChaveInv);

	//Comandos
	do{
		op = leropcao();
		switch(op) {
			case add:
				inserir(inicio_lista, mChaveInv);
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

/*Função: Irá ler a operação digitada e retornar um inteiro correspondente a lista opcoes*/
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

void Descriptografar_Matriz(int chave[][2], int chaveInv[][2]) {
	int det, d = 1, i, j;
	
	det = (chave[0][0] * chave[1][1]) - (chave[0][1] * chave[1][0]);
	while( (det * d) % 26 != 1) {
		d++;
	}
	
	chaveInv[0][0] = d * chave[1][1];
	chaveInv[0][1] = d * -1 * chave[0][1];
	chaveInv[1][0] = d * -1 * chave[1][0];
	chaveInv[1][1] = d * chave[0][0];

	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2; j++) {
			chaveInv[i][j] = chaveInv[i][j] % 26;
			if(chaveInv[i][j] < 0) {
				chaveInv[i][j] = chaveInv[i][j] + 26;
			}
		}
	}
	return;
}

void inserir(struct consulta * inicio, int chaveInv[][2]) {
	struct consulta *prox;
	struct consulta *anterior;
	struct consulta *nova;
	char nome[101], nomeReal[101], nomeProx[101];
	
	prox = inicio;

	//Ler Nome Criptografado
	scanf(" %s", nome);

	//Descriptografar o nome
	descriptografar(nome, nomeReal, chaveInv);
	
	//Alocar memória
	nova = (struct consulta*) malloc(sizeof(struct consulta));

	//Buscar na lista a posição
	if(inicio == NULL) {//Se a lista estiver vazia
		inicio = nova;
		nova->proximo = nova;//O elemento 1 aponta para ele mesmo - Lista Ligada ciclica.
	} else {//Inserir no meio da Lista
		while(!0) {
			descriptografar(prox->nome, nomeProx, chaveInv);
			if(strcmp(nomeReal, nomeProx) < 0) {
				break;
			} else {
				prox = prox->proximo;//Rodar pela lista
			}
		}
		//Encontrar o elemento que deve estar antes do novo elemento
		anterior = prox->proximo;
		while(!0) {
			if(anterior->proximo != prox) {
				anterior = anterior->proximo;
			} else {
				break;
			}		
		}

		//Alocar novo elemento
		anterior->proximo = nova;
		nova->proximo = prox;
	}
	
	//Preencher dados
	strcpy(nova->nome, nome);
	scanf(" %s", nova->data);
	scanf(" %s", nova->cod_Doenca);
	scanf(" %s", nova->crm);

	return;
}

void descriptografar(char nome[101], char nomeReal[101], int chaveInv[][2]) {
	int matrizNome[2], i = 0, k = 1;
	int elemento1, elemento2;
	while(nome[i] != '\0') {
		matrizNome[0] = nome[i] - 65;
		matrizNome[1] = nome[k] - 65;
		
		elemento1 = (chaveInv[0][0] * matrizNome[0]) + (chaveInv[0][1] * matrizNome[1]);
		elemento2 = (chaveInv[1][0] * matrizNome[0]) + (chaveInv[1][1] * matrizNome[1]);

		nomeReal[i] = elemento1 % 26;
		if(nomeReal[i] < 0) {
			nomeReal[i] += 26;
		}
		nomeReal[k] = elemento2 % 26;
		if(nomeReal[k] < 0) {
			nomeReal[k] += 26;
		}

		nomeReal[i] += 65;
		nomeReal[k] += 65;


		i+=2;
		k+=2;
	}
	nomeReal[i] = '\0';
	return;
}
