#include <stdio.h>

int fibo_rek(int n)
{
	if(n < 3) return 1;
	return fibo_rek(n-2)+fibo_rek(n-1);
}

int fibo_it(int n)
{
	if(n < 0) return 1;
	int a=0, b=1, i;
	for(i=1; i<n; i++)
	{	
		b += a;
		a = b-a;
	}
	return b;

}

int main()
{
	int n, spr;
	printf("podaj ktory wyraz ciagu fiboncciego chcesz policzyc - ");
	spr = scanf("%d", &n);
	if(spr < 1) { printf("zla wartosc\n"); return 1; } 
	printf("rekurencyjnie - %d , iteracyjnie - %d\n", fibo_rek(n), fibo_it(n) );
}