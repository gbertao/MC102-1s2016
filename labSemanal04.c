//Giovanni Bertão - ra173325 - Turma: Y
#include<stdio.h>
#include<string.h>

typedef char string[60];
//Contatos Pessoais
string nomePessoal[10], endPessoal[10];
int cpfPessoal[10], fone1Pessoal[10], fone2Pessoal[10];
//Contatos Profissionais
string nomeProfissional[10], endProfissional[10];
int cpfProfissional[10], fone1Profissional[10], fone2Profissional[10];

for(int i = 0; i < 10; i++) {
	nomePessoal[i] = '\0';
	nomeProfissional[i] = '\0';
}

int main (void) {
	//Declaração de variaveis
	int op, tipo, resposta;
	int cpf, fone1, fone2;
	char nome[60], endereco[60];

	//Menu
	scanf("%d", &op);

	switch (op) {
		case 1:
			scanf("%d", &tipo);
			scanf(" %[^\n]s", nome);
			scanf(" %d", &cpf);
			scanf(" %[^\n]s", endereco);
			scanf(" %d", &fone1);
			scanf(" %d", &fone2);

			resposta = inserir(tipo, nome, cpf, endereco, fone1, fone2);
			
			if(respsota == 0) {
				printf("Desculpe, agenda lotada!\n");
			} else {
				printf("Inserido com sucesso!\n");
			}
			break;
		case 2:
			excluir();
			break;
		case 3:
			alterar();
			break;
		case 4:
			buscar();
			break;
		case 5:
			listarPessoais();
			break;
		case 6:
			listarProfissionais();
			break;
		case 7:
			listarTodos();
			break;
		case 0:
			printf("Obrigado!\n");
			break;
	}

	return 0;
}

//Funções
int inserir (int tipo, char nome[], int cpf, char endereco[], int fone1, int fone2) {
	int  cont, r;
	//Verificar agenda e inserir
	if (tipo = 1) {
		for (cont = 0; cont < 10; cont++) {
			if(nomePessoal[cont] == '\0') {
				strcpy(nomePessoal[cont], nome);
				cpfPessoal[cont] = cpf;
				strcpy(endPessoal[cont], endereco);
				fone1Pessoal[cont] = fone1;
				fone2Pessoal[cont] = fone2;
				r = 1;
				break;
			} else {
				r = 0;
			}
		}
	} else {
		for (cont = 0; cont < 10; cont++) {
			if(nomeProfissional[cont] == '\0') {
				strcpy(nomeProfissional[i], nome);
				cpfProfissional[cont] = cpf;
				strcpy(endProfissional[cont], endereco);
				fone1Profissional[cont] = fone1;
				fone2Profissional[cont] = fone2;
				r = 1;
				break;
			} else {
				r = 0;
			}
		}
	}
	return r;
}
