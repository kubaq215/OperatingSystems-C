#include <stdio.h>
#include "funkcja.h"
#include "fzero.h"

int main()
{
	double a, b, x0, eps, spr;
	int metoda, czy_mozna;

	printf("Podaj lewa granice - ");
	spr = scanf("%lf", &a);
	if(spr == 0) { printf("Zle dane\n"); return 1; }

	printf("Podaj prawa granice - ");
	spr = scanf("%lf", &b);
	if(spr == 0) { printf("Zle dane\n"); return 2; }

	printf("Wybierz metode 0 - sieczne, 1 - bisekcja\n");
	spr = scanf("%d", &metoda);
	if(spr == 0) { printf("Zle dane\n"); return 3; }

	printf("Podaj stopien dokladnosci - ");
	spr = scanf("%lf", &eps);
	if(spr == 0) { printf("Zle dane\n"); return 4; }

	czy_mozna = fzero(a, b, metoda, eps, &x0);
	if(czy_mozna == 0)	
		{ 
			printf("Nie mozna znalezc miejsca zerowego w tym przedziale\n");
			return 6;
		}

	printf("Miejsce zerowe wynosi %lf, zostalo znalezione w %d krokach.\nWartosc w tym punkcie wynosi %lf.\n", x0, czy_mozna, f(x0));
	return 0;

		

}