#include<stdio.h>
int main (void){
	int a,b;
	double c,d;

	scanf("%d %d %lf %lf",&a,&b,&c,&d);

	printf("%d\n",a/b);
	
	printf("%d\n",c/a);
	printf("%f\n",c/d);
	printf("%f\n",c/a);
	return 0;
}
