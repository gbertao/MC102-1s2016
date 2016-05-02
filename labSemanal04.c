//Giovanni Bertão - ra173325 - Turma: Y
#include<stdio.h>
#include<string.h>

//Assinatura de Funcoes
int inserir (int tipo, char nome[60]);
int excluir (int tipo, char nome[60]);
int alterar (int tipo, char nome[60]);
int buscar (int tipo, char nome[60]);
int listarPessoais (void);
int listarProfissionais (void);
//int listarTodos(void);

typedef char string[60];

//Contatos Pessoais
string nomePessoal[10], endPessoal[10];
long long int cpfPessoal[10], fone1Pessoal[10], fone2Pessoal[10];

//Contatos Profissionais
string nomeProfissional[10], endProfissional[10];
long long int cpfProfissional[10], fone1Profissional[10], fone2Profissional[10];

int main (void) {
	//Declaração de variaveis
	char nome[60];
	int tipo, resposta, op;
	
	//Preparar matrizes(uso op para economizar variaveis)
	for(op = 0; op < 10; op++) {
		strcpy(nomePessoal[op], "\0");
		strcpy(nomeProfissional[op], "\0");		
	}

	//Menu
	do{
		scanf("%d", &op);

		switch (op) {
			case 1:
				scanf("%d", &tipo);
				scanf(" %[^\n]s", nome);

				resposta = inserir(tipo, nome);
				
				if(resposta == 0) {
					printf("Desculpe, agenda lotada!\n");
				} else {
					printf("Inserido com sucesso!\n");
				}
				break;
	
			case 2:
				scanf("%d", &tipo);
				scanf(" %[^\n]s", nome);

				resposta = excluir(tipo, nome);
	
				if(resposta == 0) {
					printf("Desculpe, contato %s nao existe!\n", nome);
				} else {
					printf("Excluido com sucesso!\n");
				}
				break;
	
			case 3:
				scanf("%d", &tipo);
				scanf(" %[^\n]s", nome);

				resposta = alterar(tipo, nome);
				
				if(resposta == 0) {
					printf("Desculpe, contato %s nao existe!\n", nome);
				} else {
					printf("Alterado com sucesso!\n");
				}
				break;
			case 4:
				scanf("%d", &tipo);
				scanf(" %[^\n]s", nome);

				resposta = buscar(tipo, nome);
			
				if(resposta == 0) {
					printf("Desculpe, contato %s nao existe!\n", nome);
				} else {
					printf("Buscado com sucesso!\n");
				}
				break;
			case 5:
				resposta = listarPessoais();
	
				if(resposta == 0) {
					printf("Desculpe, agenda vazia!\n");
				} else {
					printf("Listado com sucesso!\n");
				}
				break;
			case 6:
				resposta = listarProfissionais();
			
				if(resposta == 0) {
					printf("Desculpe, agenda vazia!\n");
				} else {
					printf("Listado com sucesso!\n");
				}
				break;
			case 7:
				resposta = listarPessoais();
				if(resposta == 0) {
					printf("Desculpe, agenda vazia!\n");
				} else {
					printf("Listado com sucesso!\n");
				}
				resposta = listarProfissionais();
				if(resposta == 0) {
					printf("Desculpe, agenda vazia!\n");
				} else {
					printf("Listado com sucesso!\n");
				}
				break;
			case 0:
				printf("Obrigado!\n");
				break;
		}
	}while(op!=0);
	return 0;
}

//----------------------------------------------Funções
//---Inserir
int inserir (int tipo, char nome[60]) {
	//Variaveis da função
	int indice, r;
	long long int cpf, fone1, fone2;
	char endereco[60];

	//Verificar agenda e inserir
	if (tipo == 1) {
		scanf(" %lld", &cpf);
		scanf(" %[^\n]s", endereco);
		scanf(" %lld %lld", &fone1, &fone2);

		for (indice = 0; indice < 10; indice++) {
			if(strcmp(nomePessoal[indice], "") == 0) {
				strcpy(nomePessoal[indice], nome);
				cpfPessoal[indice] = cpf;
				strcpy(endPessoal[indice], endereco);
				fone1Pessoal[indice] = fone1;
				fone2Pessoal[indice] = fone2;

				r = 1;
				break;
			} else {
				r = 0;
			}
		}
	} else {
		scanf(" %lld", &cpf);
		scanf(" %[^\n]s", endereco);
		scanf(" %lld %lld", &fone1, &fone2);

		for (indice = 0; indice < 10; indice++) {
			if(strcmp(nomeProfissional[indice], "") == 0) {
				strcpy(nomeProfissional[indice], nome);
				cpfProfissional[indice] = cpf;
				strcpy(endProfissional[indice], endereco);
				fone1Profissional[indice] = fone1;
				fone2Profissional[indice] = fone2;

				r = 1;
				break;
			} else {
				r = 0;
			}
		}
	}
	return r;
}

//---Excluir
int excluir (int tipo, char nome[60]) {
	//Variaveis da Função
	int r, indice, proximo;

	//Procurar na matriz pelo nome
	if(tipo == 1) {
		for(indice = 0; indice < 10; indice++) {
			//se nome digitado existe na lista
			if(strcmp(nomePessoal[indice], nome) == 0) {
				strcpy(nomePessoal[indice], "\0");
         		r = 1;
				//Reordenar
				for(proximo = indice + 1; proximo < 9; proximo++) {
					strcpy(nomePessoal[indice], nomePessoal[proximo]);
					cpfPessoal[indice] = cpfPessoal[proximo];
					strcpy(endPessoal[indice], endPessoal[proximo]);
					fone1Pessoal[indice] = fone1Pessoal[proximo];
					fone2Pessoal[indice] = fone2Pessoal[proximo];
					indice++;
				}
				strcpy(nomePessoal[9], "\0");
				break;
			} else {
				r = 0;
			}
		}
	} else {
		for(indice = 0; indice < 10; indice++) {
			if(strcmp(nomeProfissional[indice], nome) == 0) {
				strcpy(nomeProfissional[indice], "\0");
         		r = 1;
				//Reordenar
				for(proximo = indice + 1; proximo < 9; proximo++) {
					strcpy(nomeProfissional[indice], nomeProfissional[proximo]);
					cpfProfissional[indice] = cpfProfissional[proximo];
					strcpy(endProfissional[indice], endProfissional[proximo]);
					fone1Profissional[indice] = fone1Profissional[proximo];
					fone2Profissional[indice] = fone2Profissional[proximo];
					indice++;
				}
				strcpy(nomeProfissional[9], "\0");
				break;
			} else {
				r = 0;
			}
		}
	}
	return r;
}

//---Alterar
int alterar (int tipo, char nome[60]){
	int r, indice;
	long long int cpf, fone1, fone2;
	char endereco[60];

	//Procurar na lista pelo nome
	if (tipo == 1) {
		for (indice = 0; indice < 10; indice++) {
			if(strcmp(nomePessoal[indice], nome) == 0) {
				scanf(" %lld", &cpf);
				scanf(" %[^\n]s", endereco);
				scanf(" %lld %lld", &fone1, &fone2);

				cpfPessoal[indice] = cpf;
				strcpy(endPessoal[indice], endereco);
				fone1Pessoal[indice] = fone1;
				fone2Pessoal[indice] = fone2;
				r = 1;
				break;
			} else {
				r = 0;
			}
		}
	} else {
		for (indice = 0; indice < 10; indice++) {
			if(strcmp(nomeProfissional[indice], nome) == 0) {
				scanf(" %lld", &cpf);
				scanf(" %[^\n]s", endereco);
				scanf(" %lld %lld", &fone1, &fone2);

				cpfProfissional[indice] = cpf;
				strcpy(endProfissional[indice], endereco);
				fone1Profissional[indice] = fone1;
				fone2Profissional[indice] = fone2;
				r = 1;
				break;
			} else {
				r = 0;
			}
		}
	}

	return r;
}

//---Buscar
int buscar (int tipo, char nome[60]) {
	int r, indice;
	
	if(tipo == 1) {
		for (indice = 0; indice < 10; indice++) {
			if(strcmp(nomePessoal[indice], nome) == 0) {
				printf("%s\n", nomePessoal[indice]);
				printf("%011lld\n", cpfPessoal[indice]);
				printf("%s\n", endPessoal[indice]);
				printf("%lld\n", fone1Pessoal[indice]);
				printf("%lld\n", fone2Pessoal[indice]);
			
				r = 1;
				break;
			} else {
				r = 0;
			}
		}
	} else {
		for (indice = 0; indice < 10; indice++) {
			if(strcmp(nomeProfissional[indice], nome) == 0) {
				printf("%s\n", nomeProfissional[indice]);
				printf("%011lld\n", cpfProfissional[indice]);
				printf("%s\n", endProfissional[indice]);
				printf("%lld\n", fone1Profissional[indice]);
				printf("%lld\n", fone2Profissional[indice]);
			
				r = 1;
				break;
			} else {
				r = 0;
			}
		}
	}
	return r;
}

//---Listar contatos pessoais
int listarPessoais (void) {
	int indice, contVazios = 0, r;
	
	for(indice = 0; indice < 10; indice++) {
		if(strcmp(nomePessoal[indice], "") == 0) {
			contVazios++;
		} else {
			printf("%s\n", nomePessoal[indice]);
			printf("%011lld\n", cpfPessoal[indice]);
			printf("%s\n", endPessoal[indice]);
			printf("%lld\n", fone1Pessoal[indice]);
			printf("%lld\n", fone2Pessoal[indice]);
		}
	}
		
	if(contVazios == 10) {
		r = 0;
	} else {
		r = 1;
	}

	return r;
}

//---Listar contatos profissionais
int listarProfissionais (void) {
	int indice, contVazios = 0, r;
	
	for(indice = 0; indice < 10; indice++) {
		if(strcmp(nomeProfissional[indice], "") == 0) {
			contVazios++;
		} else {
			printf("%s\n", nomeProfissional[indice]);
			printf("%011lld\n", cpfProfissional[indice]);
			printf("%s\n", endProfissional[indice]);
			printf("%lld\n", fone1Profissional[indice]);
			printf("%lld\n", fone2Profissional[indice]);
		}
	}
		
	if(contVazios == 10) {
		r = 0;
	} else {
		r = 1;
	}

	return r;
}

/*---Listar todos os contatos
int listarTodos (void) {
	int indice, contVazios = 0, r;

	for(indice = 0; indice < 10; indice++) {
		if(strcmp(nomePessoal[indice], "") == 0) {
			contVazios++;
		} else {
			printf("%s\n", nomePessoal[indice]);
			printf("%lld\n", cpfPessoal[indice]);
			printf("%s\n", endPessoal[indice]);
			printf("%lld\n", fone1Pessoal[indice]);
			printf("%lld\n", fone2Pessoal[indice]);
		}
		if(contVazios == 10){
		} else {
			r = 1;
		}
	}
	for(indice = 0; indice < 10; indice++) {
		if(strcmp(nomeProfissional[indice], "") == 0) {
			contVazios++;
		} else {
			printf("%s\n", nomeProfissional[indice]);
			printf("%lld\n", cpfProfissional[indice]);
			printf("%s\n", endProfissional[indice]);
			printf("%lld\n", fone1Profissional[indice]);
			printf("%lld\n", fone2Profissional[indice]);
		}
		if(contVazios == 10) {
		
			r = 2;
		} else {
			r = 3;
		}
	}
	
	if(contVazios == 20) {
		r = 0;
	} else {
		r = 1;
	}

	return r;
}*/
