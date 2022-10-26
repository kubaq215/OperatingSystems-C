#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct student
{
	char imie[30]; char nazwisko[30]; char ocena[30][5]; int liczba_ocen;
}tab[30];

int comp(const void *c, const void *d)
{
	int x;
	x = strcmp(c, d);
	if(x != 0)
		return x;
	return 0;
}

int main()
{
	char a[30] = "1";
	char b[30] = "2";
	char c[30] = "3";
	char tab[] = {*a, *b, *c};
	int x = comp(a, b);
	printf("%d\n", x);
	qsort(tab, 3, 30, comp);
	int i;
	for(i = 0; i<3; i++)
	{
	
		printf("%\n", tab[i]);
	}
	

}