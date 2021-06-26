#include<stdio.h>
int main(void){
	int a,b,res=0;
	char op;
	scanf("%d %c %d",&a,&op,&b);
	if(op=='+')
		res=a+b;
	else if(op=='-')
		res=a-b;
	else if(op=='x')
		res=a*b;
	else if(b>0)
		res=a/b;
	if(res==42)
		printf("Esta pode ser a pergunta fundamental.\n");
	else
		printf("Esta nao pode ser a pergunta fundamental.\n");
return 0;
}
