/*Lab Semanal 05 - Análise de Dados - Giovanni Bertão - ra173325 - Turma: Y
 *
 * Objetivo: O programa recebe a data de um dia, o número de alunos, nome dos alunos, data de nascimento, gênero do aluno e
 * 			 o gênero de interesse do aluno.
 * 			 Todos os dados de entrada são armazenados no formato de grafo, com Vértices e Arrestas.
 * 			 O programa utiliza funções que permitem calcular a sintonia de cada aluno em relação ao aluno mais popular.
 * 			 O programa irá retornar o par, o qual é composto do aluno mais popular e o aluno com maior sintonia, e um 
 * 			 número de 0 a 1 indicando o nível de sintonía.
 *
 * Funções:        Organizar Dados: Prepara o grafo....................(l 112)
 * 			Verificar Centralidade: Encontra o aluno mais popular......(l 149)
 * 			               Soundex: Encontra o Código do nome..........(l 173)
 * 			           Numerologia: Encontra o Código de Nascimento....(l 257)
 * 			              Sintonía: Encontra a maior sintonia..........(l 305)
 *
 *
 *
 */
#include<stdio.h>
#include<math.h>

//Estruturas
typedef struct{
  		int dia;
		int mes;
		int ano;
		}DATA;

typedef struct{
  		char nomeCompleto[201];
		DATA dNasc;
		char genero;
		char preferencia;
		}PESSOA;

typedef struct{
		PESSOA *origem;
		PESSOA *extremidade;
		float afinidade;
		}ARRESTA;

//Assinatura de funções
void organizarDados (PESSOA v[], ARRESTA a[][40], DATA diaH, int nA);
int verificarCentralidade(ARRESTA a[][40], int nA);
void soundex (int iNome, char cod[][4], PESSOA v[], int iCod);
void numerologia (int iNome, char mNuml[][3], PESSOA v[], int iCod, DATA dHj);
void sintonia (int indC, int indiceCod, int numA, int *indExt, char codNome[][4],
			   char mNuml[][3], ARRESTA a[][40], float *sin);

int main (void) {
	//Declaração de Variaveis
	int numA, indiceCentro, cont, indiceCod = 0, indExtremo, linha, coluna;
	float maiorSintonia = 0;
	char codNome[40][4], matrizNumerologia[40][3];

	//Data Atual
	DATA diaHoje;
	scanf(" %d/%d/%d", &diaHoje.dia, &diaHoje.mes, &diaHoje.ano);

	scanf("%d", &numA);

	//Criando o Grafo
	PESSOA vertices[40];
	ARRESTA arrestas[40][40];

	//Zerar matrizes
	for(linha = 0; linha < 40; linha++) {
		for(coluna = 0; coluna < 4; coluna++) {
			codNome[linha][coluna] = 0;
		}
	}
	for(linha = 0; linha < 40; linha++) {
		for(coluna = 0; coluna < 3; coluna++) {
			matrizNumerologia[linha][coluna] = 0;
		}
	}

	//Preencher Grafo
	organizarDados(vertices, arrestas, diaHoje, numA);

	//Aluno mais popular
	indiceCentro = verificarCentralidade(arrestas, numA);

	//Soundex, Numerologia e Sintonia
	//Codigo do Nome e do Nascimento do mais popular
	soundex(indiceCentro, codNome, vertices, indiceCod);
	numerologia(indiceCentro, matrizNumerologia, vertices, indiceCod, diaHoje);
	indiceCod++;

	//Nomes compativeis com o elemento do centro
	for(cont = 0; cont < numA; cont++) {
		//Condição permite que as funções Soundex, Numerologia e Sintonia. Sejam usadas somente com as arrestas válidas
		if(arrestas[indiceCentro][cont].afinidade >= 5.0) {
			if((*arrestas[indiceCentro][cont].origem).preferencia == (*arrestas[indiceCentro][cont].extremidade).genero) {
				soundex(cont, codNome, vertices, indiceCod);
				numerologia(cont, matrizNumerologia, vertices, indiceCod, diaHoje);
				sintonia(indiceCentro, indiceCod, cont, &indExtremo, codNome, matrizNumerologia, arrestas, &maiorSintonia);
				indiceCod++;
			}
		}
	}

	//Saída
	printf("%s combina com %s com %.2f de sintonia s2\n", (*arrestas[indiceCentro][indExtremo].origem).nomeCompleto,
														  (*arrestas[indiceCentro][indExtremo].extremidade).nomeCompleto,
														   maiorSintonia);

	return 0;
}

//=========Funções=========
//====Organizar Dados======
void organizarDados (PESSOA v[], ARRESTA a[][40], DATA diaH, int nA) {
	int i, j;
	float matrizAfinidade[40][40], mediaAfinidade;

	//Preenche os dados dos vértices
	for(i = 0; i < nA; i++) {
		scanf(" %[^\n]s", v[i].nomeCompleto);
		scanf(" %d/%d/%d", &v[i].dNasc.dia, &v[i].dNasc.mes, &v[i].dNasc.ano);
		scanf(" %c %c", &v[i].genero, &v[i].preferencia);
		//Preencherá uma matriz auxiliar, que calculará a existencia da arresta
		for(j = 0; j < nA; j++) {
			if(i == j) {
				continue;
			} else {
				scanf(" %f", &matrizAfinidade[i][j]);
			}
		}
	}
	//Verificar existencia de Arrestas
	for(i = 0; i < nA; i++) {
		for(j = 0; j < nA; j++) {
			if(j == i) {
				continue;
			} else {
				mediaAfinidade = sqrt(matrizAfinidade[i][j] * matrizAfinidade[j][i]);
				if(mediaAfinidade >= 5.0) {
					a[i][j].origem = &v[i];
					a[i][j].extremidade = &v[j];
					a[i][j].afinidade = mediaAfinidade;
				}
			}
		}
	}
	return;
}

//=== Verificar Centralidade ===
int verificarCentralidade(ARRESTA a[][40], int nA) {
	int indice = 0, i, j, grau = 0, maiorG = -1;
	//Contar o numero de Arrestas de cada Vértice
	for(i = 0; i < nA; i++) {
		for(j = 0; j < nA; j++) {
			if(i == j) {
				continue;
			} else {
				//Uma arresta só existe se o seu valor entre os vértices for maior ou igual a 5
				if(a[i][j].afinidade >= 5.0) {
					grau++;
				}
			}
		}
		if(grau > maiorG) {
			maiorG = grau;
			indice = i;
		}
		grau = 0;
	}
	return indice;
}

//===Soundex===
void soundex (int iNome, char cod[][4], PESSOA v[], int iCod) {
	int i = 0, j=0;

	//Código do primeiro nome
	while(j < 4) {
		//Primeira Letra
		if(i == 0) {
			cod[iCod][j] = v[iNome].nomeCompleto[i];
			j++;
			i++;

		//Demais Letras do primeiro Nome
		} else if(v[iNome].nomeCompleto[i] >= 'a' && v[iNome].nomeCompleto[i] <= 'z') {

			if(v[iNome].nomeCompleto[i] == 'a' || v[iNome].nomeCompleto[i] == 'e' ||
			   v[iNome].nomeCompleto[i] == 'i' || v[iNome].nomeCompleto[i] == 'o' ||
			   v[iNome].nomeCompleto[i] == 'u' || v[iNome].nomeCompleto[i] == 'y' ||
			   v[iNome].nomeCompleto[i] == 'h' || v[iNome].nomeCompleto[i] == 'w' ) {
			
				i++;
				
			} else {
				switch(v[iNome].nomeCompleto[i]){
					case 'g':
					case 'j':
						cod[iCod][j] = 1;
						break;
					case 's':
					case 'z':
					case 'x':
						cod[iCod][j] = 2;
						break;
					case 'c':
					case 'k':
					case 'q':
						cod[iCod][j] = 3;
						break;
					case 'b':
					case 'p':
						cod[iCod][j] = 4;
						break;
					case 'm':
					case 'n':
						cod[iCod][j] = 5;
						break;
					case 'd':
					case 't':
						cod[iCod][j] = 6;
						break;
					case 'f':
					case 'v':
						cod[iCod][j] = 7;
						break;
					case 'l':
						cod[iCod][j] = 8;
						break;
					case 'r':
						cod[iCod][j] = 9;
						break;
				}
				j++;
				i++;
			}
		} else {
			break;
		}
	}

	//Codificação repetida
	if(cod[iCod][1] == cod[iCod][2]) {
		if(cod[iCod][2] == cod[iCod][3]) {
			cod[iCod][2] = 0;
			cod[iCod][3] = 0;
		} else {
			cod[iCod][2] = cod[iCod][3];
			cod[iCod][3] = 0;
		}
	} else if(cod[iCod][2] == cod[iCod][3]) {
		cod[iCod][3] = 0;
	}
	return;
}

//=== Numerologia ===
void numerologia (int iNome, char mNuml[][3], PESSOA v[], int iCod, DATA dHj) {
	int diaSmes, sAno, soma, idade, potD = 10, dig1, dig2;

	//Primeiro Digito do Código
	diaSmes = v[iNome].dNasc.dia + v[iNome].dNasc.mes;
	sAno = ((v[iNome].dNasc.ano) / 1000) + (((v[iNome].dNasc.ano) / 100) % 10) +
		   (((v[iNome].dNasc.ano) / 10) % 10) + ((v[iNome].dNasc.ano) % 10);

	soma = diaSmes + sAno;
	soma = (soma / 10) + (soma % 10);
	soma = (soma / 10) + (soma % 10);
	
	//Calcular Idade e Completar o código
	idade = (dHj.ano - v[iNome].dNasc.ano);
	if(dHj.mes < v[iNome].dNasc.mes) {
		idade--;
	} else if(dHj.mes == v[iNome].dNasc.mes && dHj.dia < v[iNome].dNasc.dia) {
		idade --;
	}

	//Separar digitos da idade
	//Casas decimais da idade
	while(!0) {
		if(idade >= potD) {
			potD = potD*potD;
		} else {
			potD = potD / 10;
			break;
		}
	}

	//Primeiro e Segundo digito
	dig1 = idade / potD;
	if(idade < 10) {
		dig2 = 0;
	} else {
		dig2 = (idade % potD) / (potD / 10);
	}
	
	//Código
	mNuml[iCod][0] = soma;
	mNuml[iCod][1] = dig1;
	mNuml[iCod][2] = dig2;

	return;
}

//Verificar Sintonia
void sintonia (int indC, int iCod, int numA, int *indExt, char codNome[][4], char mNuml[][3], ARRESTA a[][40], float *sin) {
	float newS, simCod, simNuml, igualdade = 0;
	int i;

	//Sintonia dos Codigos dos Nomes
	for(i = 0; i < 4; i++) {
		if(codNome[0][i] == codNome[iCod][i]) {
			igualdade++;
		}
	}
	simCod = igualdade / 4;

	//Sintonia da Numerologia
	igualdade = 0;
	for(i = 0; i < 3; i++) {
		if(mNuml[0][i] == mNuml[iCod][i]) {
			igualdade++;
		}
	}
	simNuml = igualdade / 3;

	//Calculo Sintonia
	newS = ((3 * simCod) + (5 * simNuml) + (2 * ((a[indC][numA].afinidade) / 10))) / 10;

	//Encontrar maior sintonia
	if(newS > (*sin)) {
		(*sin) = newS;
		(*indExt) = numA;
	}

	return;
}
