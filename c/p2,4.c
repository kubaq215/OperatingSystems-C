#include <math.h>
#include <stdio.h>

int main ()
{
    int spr;
    double a, b, c, x1, x2, d, k;
    
    printf("Podaj wspolczymnik a: ");
    spr = scanf("%lf",&a);
    if(spr == 0) { printf("nieprawidlowa wartosc argumentu a"); return 1; }
    
    printf("Podaj wspolczymnik b: ");
    spr = scanf("%lf",&b);
    if(spr == 0) { printf("nieprawidlowa wartosc argumentu b"); return 2; }
    
    printf("Podaj wspolczymnik c: ");
    spr = scanf("%lf",&c);
    if(spr == 0) { printf("nieprawidlowa wartosc argumentu c"); return 3; }

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
}
