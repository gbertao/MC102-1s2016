/*Lab Semanal 02- Giovanni Bertão - ra173325 - Turma Y
 *
 *Função do programa: Dado as configurações da maquete,
 *					  o preço do galão de agua, o dia do aniversario da
 *					  cidade e o ultimo ano da exposição. O programa
 *					  irá calcular o total que deve ser gasto para 
 *				      manter a exibição.
 *
 *Entradas: Número de ilhas(K); Cordenada polares dos vértices das ilhas;
 *			Aniversário da cidade(diaANI/mesANI); Ultimo ano da exibição(ANO);
 *			Quantidade de fornecedores(F); Capacidade de litros por galão 
 *			de cada forneceder(c0); Preço do Galão de cada fornecedor(p0).
 *
 *Saída:	Total dos gastos durante todo o período da exibição(X).
*/

#include<stdio.h>

int main (void) {

	//Declaração de variaveis
	int K, F;
	double X0, Y0, Xu, Yu, Xn, Yn;
	int c0, ci, numeroGaloes = 0;
	double p0, pi, galoes;
	double restoDiv;
	int quocienteDiv;
	double diasGastos, X, newX;
	int diaANI, mesANI, diasEvento = 0, aniversarioProximo = 0, aniversario = 0;
	int diaSemana = 3, dia = 13, mes = 1, ano = 2016, anoBissexto = 1;
	int ANO;
	int contador = 0;	
	double bordaSuperior = -10000, bordaInferior = 10000, bordaEsquerda = 10000, bordaDireita = -10000, eixoX, eixoY, areaSuperficie;
	double determinante, op1 = 0.0, op2 = 0.0, op3 = 0.0, op4 = 0.0, areaIlhas = 0.0, volume;

	//Número de ilhas na maquetei
	scanf("%d",&K);

	//Primeiro par polar
	scanf(" (%lf , %lf)", &X0, &Y0);
	Xu = X0;
	Yu = Y0;

	//Ajustar bordas do primeiro par
	bordaDireita = X0 + 0.5;
	bordaEsquerda = X0 - 0.5;
	bordaSuperior = Y0 + 0.5;
	bordaInferior = Y0 - 0.5;

	while (contador < K) {
	
		if (contador != 0) {

			scanf(" (%lf , %lf)", &X0, &Y0);

			if (X0 < bordaEsquerda + 0.5) {
					
				bordaEsquerda = X0 - 0.5;

			} else if (X0 > bordaDireita - 0.5) {

				bordaDireita = X0 + 0.5;
				
			}
			
			if (Y0 < bordaInferior + 0.5) {
					
				bordaInferior = Y0 - 0.5;
				
			} else if (Y0 > bordaSuperior - 0.5) {
			
				bordaSuperior = Y0 + 0.5;

			}

			Xu = X0;
			Yu = Y0;
		}

	//Loop infinito até terminar as coordenadas do poligono
	//Durante o Looping a soma dos valores da Área das ilhas será efetuada
	while(!0) {
	
		scanf(" (%lf , %lf)", &Xn, &Yn);

		if (Xn == X0 && Yn == Y0) {
			
				op2 = Xu * Y0;
				op4 = Yu * X0;
			
				determinante = op1 + op2 - op3 - op4;

				if (determinante < 0) {
					
					determinante = determinante * -1;
				
				}

				areaIlhas = areaIlhas + determinante * 0.5;
			
				contador++;
				
				op1 = 0;
				op2 = 0;
				op3 = 0;
				op4 = 0;

				break;	

			} else {
				
				if (Xn < bordaEsquerda + 0.5) {
					
					bordaEsquerda = Xn - 0.5;

				} else if (Xn > bordaDireita - 0.5) {

					bordaDireita = Xn + 0.5;
				
				}
			
				if (Yn < bordaInferior + 0.5) {
					
					bordaInferior = Yn - 0.5;
				
				} else if (Yn > bordaSuperior - 0.5) {
			
					bordaSuperior = Yn + 0.5;
				}

				op1 = op1 + Xu * Yn;
				op3 = op3 + Yu * Xn;

				Xu = Xn;
				Yu = Yn;

			}
		}
	}
	//Calculo do Volume (em litros)
	if (bordaDireita < 0) {

		bordaDireita = -bordaDireita;

		if (bordaEsquerda < 0) {
		
			bordaEsquerda = -bordaEsquerda;
			eixoX = bordaDireita - bordaEsquerda;	

		} else {

			eixoX = bordaDireita + bordaEsquerda;

		}		

	} else {

		if (bordaEsquerda < 0) {
	
			bordaEsquerda = -bordaEsquerda;
			eixoX = bordaDireita + bordaEsquerda; 	

		} else {

			eixoX = bordaDireita - bordaEsquerda;

		}

	}
	
	if (bordaSuperior < 0) {

		bordaSuperior = -bordaSuperior;

		if (bordaInferior < 0) {
		
			bordaInferior = -bordaInferior;
			eixoY = bordaSuperior - bordaInferior;	

		} else {

			eixoY = bordaSuperior + bordaInferior;
		
		}

	} else {

		if (bordaInferior < 0) {
	
			bordaInferior = -bordaInferior;
			eixoY = bordaSuperior + bordaInferior; 	

		} else {

			eixoY = bordaSuperior - bordaInferior;

		}

	}
	
	areaSuperficie = eixoX * eixoY;

	if (areaSuperficie < 0 ) {

		areaSuperficie = -areaSuperficie;

	}

	volume = (areaSuperficie - areaIlhas) * 500;

	//Calcular as datas dos eventos (Aniversário e ultimo ano)
	scanf("%d/%d", &diaANI, &mesANI);
	scanf("%d", &ANO);

	//Calcular a quantidade de dias do evento
	while ( ano <= ANO){
		
		if ((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes== 10) || (mes == 12)) {	

			diaSemana = diaSemana + 3;
			mes++;

			if (mes > 12) {

				if ((diaANI == 29) && (mesANI == 2) && (anoBissexto == 0)) {

					aniversario = aniversario;

				} else {

				aniversario++;
		
				}
				ano++;
				mes = mes - 12;

				if  ((ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0))) {
			
					anoBissexto = 1;
			
				} else {

					anoBissexto = 0;
				}

			}
			
		} else if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)) {

			diaSemana = diaSemana + 2;
			mes++;			

		} else if ((mes == 2)) {

			if(anoBissexto == 1) {

			diaSemana = diaSemana + 1;

			}

			mes++;

		}

		if (diaSemana > 6) {

			diaSemana = diaSemana - 7;
		}

		if (diaSemana == 5) {

			if (((diaANI == dia - 1) || (diaANI == dia) || (diaANI == dia + 1)) && (mesANI == mes)) {
		
				aniversarioProximo++;

			}
			if (ano<=ANO){

				diasEvento++;
		
			}
		}

	}

	//Calcular os dias em que existirá gastos
	diasGastos = diasEvento + aniversario - aniversarioProximo;

	//Encontrar melhor custo/benefício
	scanf("%d",&F);
	scanf("%d $%lf", &c0, &p0);
	
	galoes = volume / c0;
	quocienteDiv = galoes / 1;
	restoDiv = galoes - quocienteDiv;
	//Calcular valor inteiro de galões
	if( restoDiv != 0 ) {
	
	numeroGaloes = galoes - restoDiv + 1;
	
	} else {

	numeroGaloes = galoes;	

	}

	X = numeroGaloes * p0 * diasGastos;

	for ( contador = 1; contador < F; contador++) {

		scanf("%d $%lf", &ci, &pi);

		galoes = volume / ci;
		quocienteDiv = galoes /1;
		restoDiv = galoes - quocienteDiv;

		if (restoDiv != 0 ) {

			numeroGaloes = galoes - restoDiv + 1;

		} else {

			numeroGaloes = galoes;

		}

		newX = numeroGaloes * pi * diasGastos;

		if (newX < X) {

			X = newX;

		}
	}	

	printf("A manutencao da maquete custara $%.2f aos cofres publicos.\n", X);
	
	return 0;
}
