#include <stdio.h>
#include "printbit2.h"


int main()
{
	union {double d; int i[2];} u;
	
	printf("c = ");
	scanf("%lf",&u.d);
	void *c, *d;
	c = &u.i[1];
	d = &u.i[0];
	int i;
	for(i=31; i>=0; i--)
	{
		printf("%i", printbit(c, i));
		if(i%8 == 0)
			printf(" ");
	}
	printf("\n");
	for(i=31; i>=0; i--)
	{
		printf("%i", printbit(d, i));
		if(i%8 == 0)
			printf(" ");
	}
	
	printf("\n");
	return 0;

}