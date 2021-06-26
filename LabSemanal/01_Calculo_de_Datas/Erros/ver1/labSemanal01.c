//Lab Semanal 01 - Cálculo de Datas - Giovanni Bertão - ra173325
//Descrição: Dados: A data de acesso ao site(dia/mes/ano);
//		    O formato do calendário(N e M, onde N=dias no mês e M=meses no ano);
//		    A quantidade de dias restantes para o envento(em base 6 e de no máximo 8 digitos).
//	     Função:O programa irá calcular e retornar a data do evento perante a configuração do calendario proposto(diaf/mesf/anof).

#include<stdio.h>
int main(void){
	//Declaração de variaveis
	int dia,mes,ano;
	int N,M;
	long long int qnt_dias;
	long long int diaf,mesf,anof;
	long long int a0,a1,a2,a3,a4,a5,a6,a7;

	//Entrada
	scanf("%d/%d/%d %d %d %lld",&dia,&mes,&ano,&N,&M,&qnt_dias);

	//Processamento:
	//1-Converter qnt_dias em decimal
	//--Separar os digitos de qnt_dias, onde a7 = o maior digito(1º) e a0=menor digito(8º)
	a7=qnt_dias/10000000;
	a6=qnt_dias%10000000/1000000;
	a5=qnt_dias%10000000%1000000/100000;
	a4=qnt_dias%10000000%1000000%100000/10000;
	a3=qnt_dias%10000000%1000000%100000%10000/1000;
	a2=qnt_dias%10000000%1000000%100000%10000%1000/100;
	a1=qnt_dias%10000000%1000000%100000%10000%1000%100/10;
	a0=qnt_dias%10000000%1000000%100000%10000%1000%100%10;

	//--Converter os digitos em decimal
	a7=a7*6*6*6*6*6*6*6;
	a6=a6*6*6*6*6*6*6;
	a5=a5*6*6*6*6*6;
	a4=a4*6*6*6*6;
	a3=a3*6*6*6;
	a2=a2*6*6;
	a1=a1*6;	
	a0=a0;
	
	//--Somar os digitos(fim da conversão da base 6)
	qnt_dias=a0+a1+a2+a3+a4+a5+a6+a7;

	//2-Encontrar a data do evento
	//--Encontrar o Dia
	diaf=(dia+qnt_dias)%N;
	//--Encontrar o Mês
	mesf=(((dia+qnt_dias)/N)+mes)%M;
	//--Encontrar o Ano
	anof=((((dia+qnt_dias)/N)+mes)/M)+ano;

	//Saída:
	//A data final do evento no formato dia/mes/ano
	printf("%lld/%lld/%lld",diaf,mesf,anof);
}
