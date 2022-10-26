#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp(const void *a, const void *b)
{
	const double *x = a;
	const double *y = b;
	if(*x>*y)
		return 1;
	if(*x<*y)
		return -1;
	return 0;
}

void swap(double a[], int i, int j)
{
	double temp;
  	if (i != j) 
  	{
    	temp = a[i];
    	a[i] = a[j];
    	a[j] = temp; 
  	}
}

void bubblesort(double a[], int n)
{
	int i, j;
	for(i=0; i<n-1; i++)
		for(j=0; j<n-i-1; j++)
			if(a[j] > a[j+1])
				swap(a, j, j+1);
}

void quicksort(double a[], int left, int right)
{
	int i, last;

	if(right <= left) return;

	int sr = (right + left)/2;
	swap(a, left, sr);
	last = left;
	for (i=left+1; i<=right; i++)
     	if (a[i] < a[left])
       		swap(a, ++last, i);
	swap(a, left, last);
   	quicksort(a, left, last-1);
   	quicksort(a, last+1, right);

}

int main(int arg, char *argv[])
{
	double N = strtod(argv[1], NULL);
	double *tab, *tab2, *tab3;
	tab = malloc(N * 64);
	tab2 = malloc(N * 64);
	tab3 = malloc(N * 64);
	int i;
	size_t x = time(NULL);
	srand48(x);
	for(i=0; i<N; i++)
	{
		tab[i] = drand48();
		tab2[i] = tab[i];
		tab3[i] = tab[i];
	}

	clock_t start = clock();
	qsort(tab, N, sizeof(double), comp);
	clock_t stop = clock();
	double q = ((double)(stop - start)) / CLOCKS_PER_SEC;
	printf("czas qsorta - %lfs\n", q);

	start = clock();
	quicksort(tab2, 0, N-1);
	stop = clock();
	q = ((double)(stop - start)) / CLOCKS_PER_SEC;
	printf("czas wlasnego qsorta - %lfs\n", q);

	start = clock();
	bubblesort(tab3, N);
	stop = clock();
	q = ((double)(stop - start)) / CLOCKS_PER_SEC;
	printf("czas bubblesorta - %lfs\n", q);

	for(i=0; i<N-1; i++)
	{
		printf("%lf ", tab[i]);
	}
	printf("\n");
	for(i=0; i<N-1; i++)
	{
		printf("%lf ", tab2[i]);
	}
	printf("\n");
	for(i=0; i<N-1; i++)
	{
		printf("%lf ", tab3[i]);
	}
	printf("\n");

	return 0;
}