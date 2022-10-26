#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct student
{
	char imie[30]; 
	char nazwisko[30]; 
	char ocena[30][5]; 
	int liczba_ocen;
};

void norm(char *a, char *b)
{
	a[0] = toupper(a[0]);
	b[0] = toupper(b[0]);
	int i;
	for (i = 1; i < 30; i++)
	{
		a[i] = tolower(a[i]);
		b[i] = tolower(b[i]);
	}
}

int comp(const void *p1, const void *p2)
{
    struct student d1 = *(struct student *)p1;   
    struct student d2 = *(struct student *)p2;
    
    int nz = strcmp(d1.nazwisko, d2.nazwisko);
    if(nz)
        return nz;
	else
    {
        int n = strcmp(d1.imie, d2.imie);
        if(n)
            return n;
    }
    return 0;
}

float zamiana(char *a)
{	
	float x;
	x = atof(a);
	if(*a != '0' && x == 0)
		return -1;
	if(x == 0 || x == 2 || x == 3 || x == 4 || x == 5 || x == 6)
	{	
		int i;
		for(i=0; i<5; i++)
		{	
			if(a[i] == '-')
				x = x - 0.25;
			if(a[i] == '+')
				x = x + 0.25;
		}
		return x;
	} 
	return -1;
}


int main(int arg, char *plik[])
{	
	int I;
	float srednia = 0;
	for(I=1; I<arg; I++)
	{
		struct student *tab;
		int rozmiar = 80, war = 30, n = 0;
		char *line, imie[30], nazwisko[30], ocena[5];
		
		

		line = malloc(sizeof *line * rozmiar);
		tab = malloc(sizeof *tab * war);

		FILE *fp = fopen(plik[I], "r");
		if(fp == NULL) { fprintf(stderr, "Nie mozna otworzyc pliku\n"); return -2; }

		while (fgets(line, 80, fp) != NULL)
		{
			int S = sscanf(line, "%s %s %s", &*imie, &*nazwisko, &*ocena);
			if(S != 3) { fprintf(stderr, "błąd"); }

			norm(imie, nazwisko);
			int k = 0;
			int i;
			for(i=0; i<30; i++)
			{
				if(strcmp(tab[i].imie, imie) != 0 || strcmp(tab[i].nazwisko, nazwisko) != 0)
				{
					k++;
				}
				else
				{
					if(zamiana(ocena) != -1)
					{
						strcpy(tab[i].ocena[tab[i].liczba_ocen], ocena);
						tab[i].liczba_ocen++;
					}
					break;
				}
			}	
			if(k == 30)
			{
				strcpy(tab[n].imie, imie);
				strcpy(tab[n].nazwisko, nazwisko);

				if(zamiana(ocena) != -1)
				{
					strcpy(tab[n].ocena[0], ocena);
					tab[n].liczba_ocen = 1;
				}
				n++;
			}
		}
		fclose(fp);
		
		qsort((void *)tab, n, sizeof(struct student), comp);
		
		float suma = 0;
		int ilosc = 0, i;
		printf("Grupa %d\n", I);
		for(i=0; i<n; i++)
		{
			
			printf("%s %s ", tab[i].nazwisko, tab[i].imie);
			ilosc += tab[i].liczba_ocen;
			int j;
			for(j=0; j<tab[i].liczba_ocen; j++)
			{	
				printf("%.2f ", zamiana(tab[i].ocena[j]));
				suma += zamiana(tab[i].ocena[j]);
			}	
			printf("\n");
		}
		printf("Srednia klasy - %.2f\n\n", suma/ilosc);
		srednia += suma/ilosc;
	}
	printf("Srednia wszystkich grup %.2f\n", srednia/(I - 1));
	return 0;
}