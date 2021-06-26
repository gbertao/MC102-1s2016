//Lab Semanal 06 - Melhor Funcionário - Giovanni Bertão - ra173325 - Turma: Y
#include<string.h>
#include<math.h>
#include<stdio.h>
typedef struct funcionario {
	char nome[30];
	int prodAbs;
	char chefe[30];
	int subordinados;
	int nivel;
	float parteSalario;
	float salario;
	float prodRel;
	float indiceQld;
} FUNCIONARIO;

void preencherFunc(FUNCIONARIO v[], int n);
float produtividadeRelativa (FUNCIONARIO v[], int indice, int n);
float ptSalario (FUNCIONARIO v[], int indice, int n);
float constanteSalario (FUNCIONARIO v[], float total, int n);
void calcSalario (FUNCIONARIO v[], int n, float constante);
int nivelHierarquico (FUNCIONARIO v[], int n, int indice);
float qualidade (FUNCIONARIO v[], int indice, int iQld);
float logE (float nivel);
void ganhador (FUNCIONARIO v[], int indice, float *mQld, int *iGanha);

int main (void) {
	int i, indiceGanhador, fatorQuald, nFunc;
	float constante, maiorQualidade = 0, totalGasto;
	FUNCIONARIO vetFunc[100];

	//Zerando
	for(i = 0; i < 100; i ++) {
		strcpy(vetFunc[i].nome,"");
		vetFunc[i].prodAbs = 0;
		strcpy(vetFunc[i].chefe,"");
		vetFunc[i].subordinados = 0;
		vetFunc[i].prodRel = 0;
		vetFunc[i].indiceQld = 0;
	}

	scanf(" %f", &totalGasto);
	scanf(" %d", &fatorQuald);
	scanf(" %d", &nFunc);
	preencherFunc(vetFunc, nFunc);

	for(i = 0; i < nFunc; i++) {
		vetFunc[i].prodRel = produtividadeRelativa(vetFunc, i, nFunc);
		vetFunc[i].parteSalario = ptSalario(vetFunc, i, nFunc);
	}
	constante = constanteSalario(vetFunc, totalGasto, nFunc);
	calcSalario(vetFunc, nFunc, constante);
	for(i = 0; i < nFunc; i++) {
		vetFunc[i].nivel = nivelHierarquico(vetFunc, nFunc, i);
		vetFunc[i].indiceQld = qualidade(vetFunc, i, fatorQuald);
		ganhador(vetFunc, i, &maiorQualidade, &indiceGanhador);
	}

	printf("%s %0.2f\n", vetFunc[indiceGanhador].nome, vetFunc[indiceGanhador].indiceQld);

	return 0;
}

void preencherFunc(FUNCIONARIO v[], int n) {
	int i, j;
	char nome[30], chefe[30];
	//Nome Funcionario e Produtividade Absoluta
	for(i = 0; i < n; i++) {
		scanf(" %s %d", v[i].nome, &v[i].prodAbs);
	}

	//Relação Chefe - Funcionário
	for(i = 0; i < n - 1; i++) {
		scanf(" %s", nome);
			for(j = 0; j < n; j++) {
				if((strcmp(nome, v[j].nome)) == 0) {
						break;
				}
			}
		scanf(" %s", chefe);
		strcpy(v[j].chefe, chefe);
		for(j = 0; j < n; j++) {
			if((strcmp(v[j].nome, chefe)) == 0) {
				v[j].subordinados++;
			}
		}
	}

	return;
}

float produtividadeRelativa (FUNCIONARIO v[], int indice, int n) {
	int i;
	float somatoria = 0;

	//Caso Base: Funcionário sem subordinados
	if(v[indice].subordinados == 0) {
		return v[indice].prodAbs;
	} else {//Funcionario com subordinados
		for(i = 0; i < n; i++) {
			if(i == indice) {
				continue;
			} else {
				if((strcmp(v[i].chefe, v[indice].nome)) == 0) {
					somatoria = somatoria + produtividadeRelativa(v, i, n);
				}
			}
		}
		return (v[indice].prodAbs + ((somatoria / v[indice].subordinados))) / 2;
	}
}

float ptSalario (FUNCIONARIO v[], int indice, int n) {
	int i;
	float parte, quociente, parteSal;
	//Caso Base: Funcionário sem chefe(Presidente)
	if(strcmp(v[indice].chefe, "") == 0) {
		return 1;
	} else {//Funcionarios com chefe
		//Encontrar chefe
		for(i = 0; i < n; i++) {
			if(i == indice) {
				continue;
			} else {
				if((strcmp(v[i].nome, v[indice].chefe)) == 0) {
					quociente = (float) v[i].subordinados / (v[i].subordinados + 1);
					parteSal = ptSalario(v, i, n);
					parte = quociente * parteSal;
				}
			}
		}
	}
	return parte;
}

float constanteSalario (FUNCIONARIO v[], float total, int n) {
	int i;
	float constante = 0;

	for(i = 0; i < n; i++) {
		constante = constante + v[i].parteSalario;
	}

	return total / constante;
}

void calcSalario (FUNCIONARIO v[], int n, float constante) {
	int i;
	
	for(i = 0; i < n; i++) {
		v[i].salario = constante * v[i].parteSalario;
	}
	return;
}

int nivelHierarquico (FUNCIONARIO v[], int n, int indice) {
	int i, nivel;

	if(strcmp(v[indice].chefe, "") == 0) {
		return 1;
	} else { 
		for( i = 0; i < n; i++) {
			if( i == indice) { 
				continue;
			} else {
				if((strcmp(v[indice].chefe, v[i].nome)) == 0) {
					nivel = 1 + nivelHierarquico(v, n, i);
				}
			}
		}
	}
	return nivel;
}

float qualidade (FUNCIONARIO v[], int indice, int fator) {
	float iQld;

	iQld = (float) fator * ((logE(v[indice].nivel)) + 1) * v[indice].prodRel / log2f(v[indice].salario);

	return iQld;
}

float logE (float nivel) {

	if(nivel <= 1) {
		return 0;
	} else {
		return 1 + logE(log2f(nivel));
	}
}

void ganhador (FUNCIONARIO v[], int indice, float *mQld, int *iGanha) {
	if( v[indice].indiceQld > (*mQld) ) {
		(*mQld) = v[indice].indiceQld;
		(*iGanha) = indice;
	}
	return;
}
