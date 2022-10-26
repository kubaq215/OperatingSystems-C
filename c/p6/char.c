#include <stdio.h>
#include "printbit.h"


int main()
{
	char *c;
	printf("c = ");
	scanf("%c", &c);
	int i;
	for(i=7; i>=0; i--)
	{
		printf("%i",printbit(c, i));
	}
	printf("\n");
	return 0;
}