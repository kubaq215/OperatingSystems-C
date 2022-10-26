#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "norm.h"

int menu()
{
    printf("\n---------------------------------");
    printf("\n1.Wczytaj dane z pliku do tablicy. \n");
    printf("2.Pokaz dane w postaci tabelki. \n");
    printf("3.Sortuj dane... \n");
    printf("4.Dodaj rekord do danych. \n");
    printf("5.Usun rekord z danych. \n");
    printf("6.Zapisz dane do pliku. \n");
    printf("7.Pomoc\n");
    printf("8.Koniec programu. \n");
    printf("---------------------------------\n");
    printf("\nDokonaj wyboru: ");

    int q = 8;
    int x = scanf("%d", &q);
    if(!x)
    {    
        printf("\nNieprawidlowy wybor... *konczenie pracy programu*\n");
        return 8;
    }  
    return q;
}


int menu2()
{
    printf("\n---------------------------------");
    printf("\n1. Sortuj w kolejnosci nazwisko, imie, wiek, zarobki.");
    printf("\n2. Sortuj w kolejnosci imie, nazwisko, wiek, zarobki.");
    printf("\n3. Sortuj w kolejnosci wiek, nazwisko, imie, zarobki.");
    printf("\n4. Sortuj w kolejnosci zarobki, nazwisko, imie, wiek.");
    printf("\n5. Powrot do menu. \n");
    printf("---------------------------------\n");
    printf("\nSortuj: ");

    int wyb = 5;
    int x = scanf("%d", &wyb);
    if(!x)
    {    
        printf("Nieprawidlowy wybor\n");
        return 5;
    }   
    return wyb; 
}

struct dane
{
    char imie[30];
    char nazwisko[30];
    int wiek;
    double zarobki;
    int lp;
};


int comp1(const void *p1, const void *p2)
{
    struct dane d1 = *(struct dane *)p1;   
    struct dane d2 = *(struct dane *)p2;
    
    int nz = strcmp(d1.nazwisko, d2.nazwisko);
    if(nz)
        return nz;

    else
    {
        int n = strcmp(d1.imie, d2.imie);
       
        if(n)
            return n;
        else 
        {
            int w = d1.wiek-d2.wiek;

            if(w)
                return w;
            else 
            {
                return d1.zarobki-d2.zarobki;
            }
        }
    }
}

int comp2(const void *p1, const void *p2)
{
    struct dane d1 = *(struct dane *)p1;   
    struct dane d2 = *(struct dane *)p2;
    int n = strcmp(d1.imie, d2.imie);

    if(n)
        return n;
    else
    {
        int nz = strcmp(d1.nazwisko, d2.nazwisko);
        if(nz)
            return nz;
        
        else 
        {
            int w = d1.wiek-d2.wiek;

            if(w)
                return w;
            else 
            {
                return d1.zarobki-d2.zarobki;
            }
        }
    }
}

int comp3(const void *p1, const void *p2)
{
    struct dane d1 = *(struct dane *)p1;   
    struct dane d2 = *(struct dane *)p2;
   
    int w = d1.wiek-d2.wiek;
    if(w)
        return w;
    else
    {
        int nz = strcmp(d1.nazwisko, d2.nazwisko);
       
        if(nz)
            return nz;
        else 
        {
            int n = strcmp(d1.imie, d2.imie);
            if(n)
                return n;
            else 
            {
                return d1.zarobki-d2.zarobki;
            }
        }
    }
}

int comp4(const void *p1, const void *p2)
{
    struct dane d1 = *(struct dane *)p1;   
    struct dane d2 = *(struct dane *)p2;

    int z = d1.zarobki-d2.zarobki;
    if(z)
        return z;
    else
    {
        int nz = strcmp(d1.nazwisko, d2.nazwisko);
        if(nz)
            return nz;
        else 
        {
            int n = strcmp(d1.imie, d2.imie);

            if(n)
                return n;
            else 
            {
                return d1.wiek-d2.wiek;
            }
        }
    }
}


int main(int arg, char *argv[])
{
    if(arg > 1)
        if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
        {
            printf("1.Plik wejsciowy nie powinien miec wiecej niz 100 rekordow.\n");
            printf("2.W pliku wejsciowym, w jednej linijce powinny byc dane w kolejnosci: imie, nazwisko, wiek, zarobki.\n");
            printf("3.W zapisie liczby, przedstawiajacej zarobki, nalezy uzyc kropki zamiast przecinka.\n");
            printf("4.Wczytanie pliku nastapi interaktywnie po wlaczeniu programu\n");
            printf("5.Jesli nie posiadasz takiego pliku, mozesz go stworzyc poprzez dodawanie rekordow recznie, przy uzyciu opcji 4.\n");
            printf("6.W programie możesz posortować swoje dane, dodawac i usuwac wybrane przez siebie rekordy oraz zapisac zmiany w osobnym pliku.\n");
            return 0;
        }

    FILE *fp;
    int er = 0;
    int wlp;
    struct dane *a;
    a = malloc(sizeof *a * 100);
    int k = 0;
    while(1)
    switch(menu())
    {
        case 1:

            printf("\nJaki plik chcesz przeczytac? Podaj jego pelna nazwe.\n");
            char nplik[20] = "";
            int x0 = scanf("%s", nplik);
            if(!x0)
            {    
                printf("Nieprawidlowe dane\n");
                break;
            }  
            printf("\n\n");
            FILE *fin = fopen(nplik,"r");
            
            if(!fin)
            {
                printf("Blad otwarcia pliku do czytania!\n");
                break;
            }

            if(k)
                k = 0;
            

            while(fscanf(fin,"%s %s %d %lg", a[k].imie, a[k].nazwisko, &a[k].wiek, &a[k].zarobki) == 4) 
            {
                norm(a[k].imie, a[k].nazwisko);
                bez(a[k].imie);
                bez(a[k].nazwisko);
                k++;
            }

            fclose(fin);
            int l;
            for(l=0; l<k; l++)
            {
                a[l].lp = l+1;
            }
            printf("Wczytano %d rekordow\n", k);
            break;

        case 2:

            printf("\n\t+------+----------------+--------------------+--------+-------------+\n");
            printf("\t|  Lp  |      Imie      |      Nazwisko      |  Wiek  |   Zarobki   |\n");
            printf("\t+------+----------------+--------------------+--------+-------------+\n");
            int t;
            for(t=0; t<k; t++)
            {
                printf("\t|%5d | %-15s| %-19s|%7d |%12lg |\n", a[t].lp, a[t].imie, a[t].nazwisko, a[t].wiek, a[t].zarobki);
            }
            printf("\t+------+----------------+--------------------+--------+-------------+\n");
            break;

        case 3:
            
            while(er!=2)
            switch(menu2())
            {
                case 1:

                    qsort((void *)a, k, sizeof(struct dane), comp1);
                    for(l=0; l<k; l++)
                    {
                        a[l].lp = l+1;
                    }
                    er = 2;
                    break;

                case 2:

                    qsort((void *)a, k, sizeof(struct dane), comp2);
                    for(l=0; l<k; l++)
                    {
                        a[l].lp = l+1;
                    }
                    er = 2;
                    break;

                case 3:

                    qsort((void *)a, k, sizeof(struct dane), comp3);
                    for(l=0; l<k; l++)
                    {
                        a[l].lp = l+1;
                    }
                    er = 2;
                    break;

                case 4:

                    qsort((void *)a, k, sizeof(struct dane), comp4);
                    for(l=0; l<k; l++)
                    {
                        a[l].lp = l+1;
                    }
                    er = 2;
                    break;

                case 5:
                
                    er = 2;
            
                default:
                    break;
            }
            er = 0;
            break;

        case 4:

            k++;
            printf("\n\nPodaj imie:\n");
            int x1 = scanf("%s", a[k-1].imie);
            printf("\n\nPodaj nazwisko:\n");
            int x2 = scanf("%s", a[k-1].nazwisko);
            printf("\n\nPodaj wiek:\n");
            int x3 = scanf("%d", &a[k-1].wiek);
            printf("\n\nPodaj zarobki:\n");
            int x4 = scanf("%lg", &a[k-1].zarobki);
            if(!x1 || !x2 || !x3 || !x4)
            {    
                printf("Nieprawidlowe dane\n");
                break;
            }  

            norm(a[k-1].imie, a[k-1].nazwisko);
            bez(a[k-1].imie);
            bez(a[k-1].nazwisko);

            printf("\n\nRekord zostal dodany. Aktualna liczba rekordow: %d\n", k);
            
            for(l=0; l<k; l++)
                {
                    a[l].lp = l+1;
                    
                }
            
            break;

        case 5:
            
            printf("\nKtory rekord chcesz usunac? Podaj jego Lp.\n");
            int x5 = scanf("%d", &wlp);
            if(!x5)
            {    
                printf("Nieprawidlowe dane\n");
                break;
            }  

            if ((wlp>k) || (wlp<=0))
            {
                printf("\n\nNie ma takiego rekordu.\n");
            }
            else
            {
                int i;
                for(i=0; i<k-1; i++)
                {
                    if (a[i].lp >= wlp)
                    {
                        a[i] = a[i+1];
                    }
                }
               
                k = k-1;
                printf("\n\nRekord zostal usuniety. Aktualna liczba rekordow: %d\n", k);
            }           
            for(l=0; l<k; l++)
            {
                a[l].lp = l+1;
                
            }
            break;

        case 6:

            printf("\nJak chcesz nazwac plik?\n");
            char splik[20] = "";
            int x6 = scanf("%s", splik);            
            fp = fopen(splik,"w");
        
            if(!fp)
            {
                printf("Blad otwarcia pliku do pisania!\n");
                exit(-1);
            }
            int i;
            int lp = 0;
            for(i=0; i<k; i++)
                {
                    lp++;
                    fprintf(fp,"%s %s %d %lg\n", a[i].imie, a[i].nazwisko, a[i].wiek, a[i].zarobki);
                } 
                fclose(fp);
            printf("\n\nZapisano %d rekordow.\n", k);
            break;

        case 7:

            printf("Wywołaj program z opcja \"-h\" lub \"--help\" aby zobaczyc pomoc.\n");                    
            break;

        case 8:
            exit(0);
        default:
            printf("\nNie ma takiej opcji! \n");
    }
    
}

