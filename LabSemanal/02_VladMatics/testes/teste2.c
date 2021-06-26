#include<stdio.h>
int main (void){
	int i,n,op;
		printf("Opção seguida de repetições");
		scanf("%d",&op);
	while(op!=0){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			int ai;
			printf("valor de a%d: ",i);
			scanf("%d",&ai);
			printf("\na%d: %d\n",i,ai);		
		}
		printf("Opção seguida de repetições");
		scanf("%d",&op);
	}
	return 0;
}
