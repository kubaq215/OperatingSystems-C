#include <stdio.h>

double silnia_it(int n)
{
	if(n < 0) return -1;
	int i;
	double silnia = 1;
	for(i=1; i<=n; i++)
		silnia *= i;
	return silnia;
}

double silnia_rek(int n)
{
	if(n <= 1) return 1;
	return n*silnia_rek(n-1);
}

int main()
{
	int n, spr;
	printf("podaj n - ");
	spr = scanf("%d", &n);
	if(spr < 1) { printf("zle n\n"); return 1; }  
	printf("iteracyjnie - %lf , rekurencyjnie - %lf \n", silnia_it(n), silnia_rek(n));
	return 0;
}