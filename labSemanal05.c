//Giovanni Bertão - ra173325 - Turma: Y
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

int main (void) {
	//Declaração de Variaveis
	int numA, indiceCentro;

	//Data Atual
	DATA diaHoje;
	scanf(" %d/%d/%d", &diaHoje.dia, &diaHoje.mes, &diaHoje.ano);

	scanf("%d", &numA);

	//Criando o Grafo
	PESSOA vertices[40];
	ARRESTA arrestas[40][40];

	organizarDados(vertices, arrestas, diaHoje, numA);

	indiceCentro = verificarCentralidade(arrestas, numA);
printf("indiceCentro: %d\n", indiceCentro);
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
