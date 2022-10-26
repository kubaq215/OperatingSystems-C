#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char a[] = "ŻZĄAŚSĆCŹZĘEŃNÓOŁL";
	int i;
	for(i=0; i<strlen(a); i++)
		printf("%i\n", a[i]);
	
	
}