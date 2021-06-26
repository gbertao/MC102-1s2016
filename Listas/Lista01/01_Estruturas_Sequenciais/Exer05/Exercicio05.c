#include<stdio.h>

int main (void) {
	char a;

	a = '6';

	printf("%c\n", a);

	a = 6;	

	printf("%c\n", a);

	return 0;
}
/*A diferenca em a = '6' e a = 6 é: 
 *								
 *			No primeiro a recebe o caracter 6
 *			No segundo a recebe o caracter de codigo 6
 */
