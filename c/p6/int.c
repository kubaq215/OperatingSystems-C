#include <stdio.h>
#include "printbit.h"


int main()
{
	int c;
	printf("c = ");
	scanf("%i", &c);
	int i;
	for(i=31; i>=0; i--)
	{
		printf("%i",printbit(c, i));
		if(i%8 == 0)
			printf(" ");
	}
	printf("\n");
	return 0;
}