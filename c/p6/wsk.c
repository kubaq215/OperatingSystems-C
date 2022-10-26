#include <stdio.h>
#include "printbit3.h"

int main()
{
	union {double d; char c[8];} u;

	printf("c = ");
	scanf("%lf",&u.d);
	int i, j;
	for (i=8; i>=0; i--)
	{
		char *a = u.c[i];
		
		for(j=8; j>=0; j--)
			printf("%i", printbit(a, i));
		printf(" ");
	}
	return 0;
}