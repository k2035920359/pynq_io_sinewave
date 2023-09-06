#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double a, b, c;
	scanf("%lf", &a);
	scanf("%lf", &b);
	c = a + b;
	printf("%.2f\n", c);
	
	return 0;
}
