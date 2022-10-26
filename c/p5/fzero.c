#include <stdio.h>
#include <math.h>
#include "funkcja.h"

 int fzero(double a, double b, int metoda, double eps, double *x0)
 {
 	double fa, fb, fx;
 	int licznik = 2;

 	fa = f(a); if(fa == 0) { *x0 = a; return 1; } 
 	fb = f(b); if(fb == 0) { *x0 = b; return 2; } 
	if(fa*fb > 0) 
 			return 0;
 	
 	do
 	{	
 		if(metoda == 1) 
 			*x0 = (a + b) / 2;
 		else 
 			*x0 = (fa * b - fb * a) / (fa - fb);

 		licznik++;	
 			
 		fx = f(*x0);		
 		if(fx == 0) 
 			return licznik;

 		if(metoda == 1)
 		{	
 			if(fa * fx < 0)
 			{	
 				b = *x0;
 				fb = fx;
 			}
 			else
 			{
 				a = *x0;
 				fa = fx;
 			}
 		}
 		else
 		{
 			a = b;
 			fa = fb;
 			b = *x0;
 			fb = fx;
 		}	

 	}
 	while ((fabs(fx) > eps) && (fabs((b - a) / a) > eps));

 	return licznik;
}