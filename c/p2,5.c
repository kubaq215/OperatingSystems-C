#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (int arg, char *argv[])
{

	double a, b, c, x1, x2, d, k;

	if(arg != 4)
	{ printf("podaj dokladnie 3 argumenty\n"); return 4; }

	a = strtod(argv[1], NULL);
	if(*argv[1] != '0' && a == 0) 
	{ printf("nieprawidlowa wartosc pierwszego argumentu\n"); return 1; }

	b = strtod(argv[2], NULL);
	if(*argv[2] != '0' && b == 0)
	{ printf("nieprawidlowa wartosc drugiego argumentu\n"); return 2; }

	c = strtod(argv[3], NULL);
	if(*argv[3] != '0' && c == 0)
	{ printf("nieprawidlowa wartosc trzeciego argumentu\n"); return 3; }
	

	d = b*b - 4*a*c;
    if(d>0)
    {
        x1 = (-b - sqrt(d)) / (2*a);
        x2 = (-b + sqrt(d)) / (2*a);
        printf ("sa dwa rozwiazania rzeczywiste x1 i x2\nx1 = %lf, x2 = %lf ",x1,x2);
    }
    if(d==0)
    {
        x1 = -b / (2*a);
        printf ("jest jedno rozwiazanie podwojne x1\nx1 = %lf",x1);
    }
    if(d<0)
    {
        k = sqrt(-d) / (2*a);
        x1 = -b / (2*a);
        printf ("sa dwa rozwiazania zespolone x1 i x2\nx1 = %lf - %lfi, x2 = %lf + %lfi ",x1,k,x1,k);
    }
	return 0;
}