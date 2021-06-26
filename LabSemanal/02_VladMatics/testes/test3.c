#include<stdio.h>
int main (void){
	int i,g,n,op;
		printf("Opção seguida de repetições");
		scanf("%d",&op);
	while(op!=0){
		scanf("%d",&n);
		for(i=0;i<=n;i++){
			int ai;
			printf("a%d: ",i);
			scanf("%d",&ai);
			if(i==n){
				printf("igual");
			} else {
				g=ai;
			}
		}
		printf("g:%d\n",g);
		printf("Opção seguida de repetições");
		scanf("%d",&op);
	}
	return 0;
}
