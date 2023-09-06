#include<stdio.h>
int main()
{
	int m, n;
	for(m=1; m<=9; m++)
	{
		for(n=1; n<=9; n++)
		{
			printf("%d*%d=%2d  ", n, m, m*n);
		}
		printf("\n");
	}
}
