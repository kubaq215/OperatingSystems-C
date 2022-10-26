#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int comp(const void *a, const void *b)
{
	const char *q = a;
	const char *w = b;
	int x;
	x = strcmp(q, w);
	if(x < 0)
		return 1;
	else 
		if(x > 0)
			return -1;
	return 0;
}

int main()
{
	char *a[2];
	char *b[2];
	char *c[4];
	
	char *imie = "jacek";
	char *nazw = "was";
	char *imie1 = "aacek";
	char *nazw1 = "aas";
	
	a[0] = malloc(sizeof *a * 60);
	b[0] = malloc(sizeof *b * 30);
	strcpy(a[0], nazw);
	strcpy(b[0], imie);
	strcat(a[0], " ");
	strcat(a[0], b[0]);
	strcat(a[0], " ");
	printf("%s\n", a[0]);
	c[0] = strtok(a[0], " ");
	c[1] = strtok(NULL, " ");
	printf("%s \n%s \n", c[0], c[1]);
	a[1] = malloc(sizeof *a * 60);
	b[1] = malloc(sizeof *b * 30);
	strcpy(a[1], nazw1);
	strcpy(b[1], imie1);
	strcat(a[1], b[1]);


	qsort(a, 2, sizeof(a[0]), comp);
	
	
	
}