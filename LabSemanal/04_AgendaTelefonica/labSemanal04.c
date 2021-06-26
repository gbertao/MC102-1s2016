/*Lab Semanal 4 - Agenda Telefonica - Giovanni Bertão - ra173325 - Turma: Y
 *
 * Objetivo: O programa receberá a entrada contendo a opção da função que se deseja realizar, cada função receberá um conjunto de entradas diferentes.
 *			 A função retorna um inteiro para confirmar se a conclusão foi bem sucedida ou não.
 *			 O inteiro retornado pela função é utilizado nos testes condicionais para imprimir as mensagens ao usuário.
 *
 * Entradas: Nome, CPF, Endereço, Telefone Comercial/Residencial e Celular.
 * 
 *	  Saída: Depende da função que será executada. Contudo, de forma geral, todas as funções imprimem mensagens de sucesso ou falha.
 *
 *  Funções: Inserir: armazena os dados na matriz;............................(l. 156)
 *			 Excluir: remove os dados já inseridos na matriz;.................(l. 208)
 *			 Alterar: altera os dados(exceto o nome) de um contato;...........(l. 275)
 *			 Buscar: Imprime os dados de um contato;..........................(l. 327)
 *			 Listar Pessoais: Imprime todos os contatos pessoais;.............(l. 365)
 *			 Listar Profissionais: Imprime todos os contatos profissionais;...(l. 385)
 */
#include<stdio.h>
#include<string.h>

//Assinatura de Funcoes
int inserir (int tipo, char nome[61]);
int excluir (int tipo, char nome[61]);
int alterar (int tipo, char nome[61]);
int buscar (int tipo, char nome[61]);
int listarPessoais (void);
int listarProfissionais (void);

//Definição de tipo string, o vetor possui 61 possições, pois adimite 60 caracteres(posições 0...59) e o bit nulo '\0' na ultima posição
typedef char string[61];

//Contatos Pessoais
string nomePessoal[10], endPessoal[10];
long long int cpfPessoal[10], telPessoal[10], celPessoal[10];
int contPess = 0;//usado controlar o numero total de contatos na agenda

//Contatos Profissionais
string nomeProfissional[10], endProfissional[10];
long long int cpfProfissional[10], telProfissional[10], celProfissional[10];
int contProf = 0;

int main (void) {
	//Declaração de variaveis
	char nome[61];
	int tipo, resposta, op, i;
	
	//Preparar matrizes	
	for(i = 0; i < 10; i++) {
		strcpy(nomePessoal[i], "\0");
		strcpy(nomeProfissional[i], "\0");		
	}

	//Menu
	do{
		scanf(" %d", &op);

		switch (op) {
			case 1:
				scanf(" %d", &tipo);
				scanf(" %[^\n]s", nome);

				resposta = inserir(tipo, nome);
				
				if(resposta == 0) {
					printf("Desculpe, agenda lotada!\n");
				} else {
					printf("Inserido com sucesso!\n");
				}
				break;
	
			case 2:
				scanf(" %d", &tipo);
				scanf(" %[^\n]s", nome);

				resposta = excluir(tipo, nome);
	
				if(resposta == 0) {
					printf("Desculpe, contato %s nao existe!\n", nome);
				} else {
					printf("Excluido com sucesso!\n");
				}
				break;
	
			case 3:
				scanf(" %d", &tipo);
				scanf(" %[^\n]s", nome);

				resposta = alterar(tipo, nome);
				
				if(resposta == 0) {
					printf("Desculpe, contato %s nao existe!\n", nome);
				} else {
					printf("Alterado com sucesso!\n");
				}
				break;

			case 4:
				scanf(" %d", &tipo);
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
	} while(op!=0);
	return 0;
}

//----------------------------------------------Funções

//---Inserir
int inserir (int tipo, char nome[61]) {
	//Variaveis da função
	int indice, r;
	long long int cpf, tel, cel;
	char endereco[61];

	if (tipo == 1) { //Inserir um contato pessoal
		scanf(" %lld", &cpf);
		scanf(" %[^\n]s", endereco);
		scanf(" %lld %lld", &tel, &cel);

		if(contPess == 10) {
			r = 0;

		} else {
			indice = contPess; //contPess sempre será o ultimo indice não preenchido

			strcpy(nomePessoal[indice], nome);
			cpfPessoal[indice] = cpf;
			strcpy(endPessoal[indice], endereco);
			telPessoal[indice] = tel;
			celPessoal[indice] = cel;

			r = 1;
			contPess++;
		}
		
	} else if(tipo == 2) { //Inserir um contato Profissional
		scanf(" %lld", &cpf);
		scanf(" %[^\n]s", endereco);
		scanf(" %lld %lld", &tel, &cel);

		if(contProf == 10) {
			r = 0;

		} else {
			indice = contProf;

			strcpy(nomeProfissional[indice], nome);
			cpfProfissional[indice] = cpf;
			strcpy(endProfissional[indice], endereco);
			telProfissional[indice] = tel;
			celProfissional[indice] = cel;

			r = 1;
			contProf++;
		}
	}
	return r;
}

//---Excluir
int excluir (int tipo, char nome[61]) {
	//Variaveis da Função
	int r, indice, proximo;

	//Procurar na matriz pelo nome
	if(tipo == 1) {
		if(contPess == 0) {
			r = 0;
		} else {
			for(indice = 0; indice < 10; indice++) {
				if(strcmp(nomePessoal[indice], nome) == 0) {//função strcmp retornará 0 <---> as 2 strings do argumento forem iguais
					strcpy(nomePessoal[indice], "\0");
         			contPess--;
					r = 1;

					//Reordenar
					if(indice != 9) { //Se o contato excluído for o ultimo(posicao 9), não há necessidade de reordenar toda a lista
						for(proximo = indice + 1; proximo < 10; proximo++) {
							strcpy(nomePessoal[indice], nomePessoal[proximo]);
							cpfPessoal[indice] = cpfPessoal[proximo];
							strcpy(endPessoal[indice], endPessoal[proximo]);
							telPessoal[indice] = telPessoal[proximo];
							celPessoal[indice] = celPessoal[proximo];
							indice++;
						}
						//devido ao final da iteração os dados da posição 8(9º contato) serem os mesmo da posição 9(10º contato):
						strcpy(nomePessoal[9], "\0");					
					}
					break;
				} else if(indice == 9) {//Condição para contato inexistente
					r = 0;
				}
			}
		}
	} else if(tipo == 2) {
		if(contProf == 0) {
			r = 0;
		} else {
			for(indice = 0; indice < 10; indice++) {
				if(strcmp(nomeProfissional[indice], nome) == 0) {
					strcpy(nomeProfissional[indice], "\0");
					contProf--;
         			r = 1;

					//Reordenar
					if(indice !=9) {
						for(proximo = indice + 1; proximo < 10; proximo++) {
							strcpy(nomeProfissional[indice], nomeProfissional[proximo]);
							cpfProfissional[indice] = cpfProfissional[proximo];
							strcpy(endProfissional[indice], endProfissional[proximo]);
							telProfissional[indice] = telProfissional[proximo];
							celProfissional[indice] = celProfissional[proximo];
							indice++;
						}
						strcpy(nomeProfissional[9], "\0");
					}
					break;
				} else if(indice == 9) {
					r = 0;
				}
			}
		}
	}
	return r;
}

//---Alterar
int alterar (int tipo, char nome[61]){
	int r, indice;
	long long int cpf, tel, cel;
	char endereco[61];

	if (tipo == 1) {
		if(contPess == 0) {
			r = 0;
		} else {
			for (indice = 0; indice < 10; indice++) {
				if(strcmp(nomePessoal[indice], nome) == 0) {
					scanf(" %lld", &cpf);
					scanf(" %[^\n]s", endereco);
					scanf(" %lld %lld", &tel, &cel);

					cpfPessoal[indice] = cpf;
					strcpy(endPessoal[indice], endereco);
					telPessoal[indice] = tel;
					celPessoal[indice] = cel;
					r = 1;
					break;
				} else if(indice == 9) {
					r = 0;
				}
			}
		}
	} else if(tipo == 2) {
		if(contProf == 0) {
			r = 0;
		} else {
			for (indice = 0; indice < 10; indice++) {
				if(strcmp(nomeProfissional[indice], nome) == 0) {
					scanf(" %lld", &cpf);
					scanf(" %[^\n]s", endereco);
					scanf(" %lld %lld", &tel, &cel);

					cpfProfissional[indice] = cpf;
					strcpy(endProfissional[indice], endereco);
					telProfissional[indice] = tel;
					celProfissional[indice] = cel;
					r = 1;
					break;
				} else if(indice == 9){
					r = 0;
				}
			}
		}	
	}
	return r;
}

//---Buscar
int buscar (int tipo, char nome[61]) {
	int r, indice;
	
	if(tipo == 1) {
		for (indice = 0; indice < 10; indice++) {
			if(strcmp(nomePessoal[indice], nome) == 0) {
				printf("%s\n", nomePessoal[indice]);
				printf("%lld\n", cpfPessoal[indice]);
				printf("%s\n", endPessoal[indice]);
				printf("%lld\n", telPessoal[indice]);
				printf("%lld\n", celPessoal[indice]);
			
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
				printf("%lld\n", cpfProfissional[indice]);
				printf("%s\n", endProfissional[indice]);
				printf("%lld\n", telProfissional[indice]);
				printf("%lld\n", celProfissional[indice]);
			
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
	int indice, r;
	
	if(contPess == 0) {
		r = 0;
	} else {
		for(indice = 0; indice < contPess; indice++) {
			printf("%s\n", nomePessoal[indice]);
			printf("%lld\n", cpfPessoal[indice]);
			printf("%s\n", endPessoal[indice]);
			printf("%lld\n", telPessoal[indice]);
			printf("%lld\n", celPessoal[indice]);
		}
		r = 1;
	}

	return r;
}

//---Listar contatos profissionais
int listarProfissionais (void) {
	int indice, r;
	
	if(contProf == 0) {
		r = 0;
	} else {
		for(indice = 0; indice < contProf; indice++) {
			printf("%s\n", nomeProfissional[indice]);
			printf("%lld\n", cpfProfissional[indice]);
			printf("%s\n", endProfissional[indice]);
			printf("%lld\n", telProfissional[indice]);
			printf("%lld\n", celProfissional[indice]);
		}
		r = 1;
	}

	return r;
}
