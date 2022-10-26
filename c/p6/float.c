#include <stdio.h>
#include "printbit.h"


int main()
{
	union {float f; int i;} u;
	printf("c = ");
	scanf("%f",&u.f);
	int i;
	for(i=31; i>=0; i--)
	{
		printf("%i",printbit(u.i, i));
		if(i%8 == 0)
			printf(" ");
	}
	printf("\n");

	return 0;
}