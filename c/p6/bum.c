#include <stdio.h>
#include "printbit.h"


int main()
{
	char c;
	printf("c = ");
	scanf("%c", &c);
	int i;
	for(i=7; i>=0; i--)
	{
		printf("%i",printbit(c, i));
	}
	printf("\n");
	int a, b, d;

	printf("ktory wyzerowac - ");
	scanf("%i", &a);
	for(i=7; i>=a; i--) 
		printf("%i",printbit(c, i));

	printf("%i",zerobit(c, a));

	for(i=a-2; i>=0; i--) 
		printf("%i",printbit(c, i));
	printf("\n");

	printf("ktory ustawic na 1 - ");
	scanf("%i", &b);
	for(i=7; i>=b; i--) 
		printf("%i",printbit(c, i));

	printf("%i",setbit(c, b));

	for(i=b-2; i>=0; i--) 
		printf("%i",printbit(c, i));
	printf("\n");
	
	printf("ktory przerzucic - ");
	scanf("%i", &d);
	for(i=7; i>=d; i--) 
		printf("%i",printbit(c, i));

	printf("%i",flipbit(c, d));
	
	for(i=d-2; i>=0; i--) 
		printf("%i",printbit(c, i));
	printf("\n");
	return 0;
}