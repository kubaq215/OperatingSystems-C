#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>


typedef void (*sighandler_t)(int);
sighandler_t signal(int sig, sighandler_t signal);

extern const char * const sys_siglist[];

void handler(int signo)
{
	printf("*Przechwycono sygnal*\n");
	printf("nazwa = %s, numer = %i\n",sys_siglist[signo], signo);
}


int main(int arg, char *argv[])
{
	printf("PID = %i\n", getpid());

	if(arg!=3)
	{
		printf("Nieprawidlowe wywolanie programu.\n");
		exit(EXIT_FAILURE);
	}
	
	int sg = atoi(argv[1]);
	int nr = atoi(argv[2]);

	if(nr != 1 && nr != 2 && nr != 3)
		printf("Nieprawidlowe wywolanie programu.\n");

 	if(nr == 1)
 	{
 		if(signal(sg, SIG_DFL) == SIG_ERR)
 		{
        	perror("Blad funkcji signal.");
        	exit(EXIT_FAILURE);
        }
        else 
        	printf("*Operacja domyslna wykonana*\n");
 	}
 	if(nr == 2)
 	{
 		if(signal(sg, SIG_IGN) == SIG_ERR)
 		{
        	perror("Blad funkcji signal.");
        	exit(EXIT_FAILURE);
        }
        else 
        	printf("*Sygnal zostal zignorowany*\n");
 	}
 	if(nr == 3)
 	{
 		if(signal(sg, handler) == SIG_ERR)
 		{
        	perror("Blad funkcji signal.");
        	exit(EXIT_FAILURE);
        }  
        handler(sg);
 	}

 	printf("Oczekiwanie\n\n");

	pause();
}



