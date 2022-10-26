#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "biblioteka.h"
#include "biblioteka2.h"

void handler(int signo)
{
	unlinkSMF("/kons");
	unlinkSMF("/prod");
	unlinkSHM();
	exit(1);
}

void end()
{
	unlinkSMF("/kons");
	unlinkSMF("/prod");
	unlinkSHM();
}

int main(int arg, char *argv[])
{
	if(arg!=4)
	{
		printf("Nieprawidlowe wywolanie programu\n");
		exit(1);
	}

	createSMF("/prod", LEL);
	sem_t *prodes = openSMF("/prod", LEL);
	printf("Adres semafora producenta: %p\n", (void *)prodes);
    printf("Wartosc semafora: %d\n\n", valueSMF(prodes));

    createSMF("/kons", 0);
	sem_t *kondes = openSMF("/kons", 0);
	printf("Adres semafora konsumenta: %p\n", (void *)kondes);
    printf("Wartosc semafora: %d\n\n", valueSMF(kondes));

    createSHM("/shm", sizeof(Shmem));
    printf("**Utworzono pamiec dzielona**\n\n");

	

	if(signal(SIGINT, handler) == SIG_ERR)
    {
        perror("blad funkcji signal");
        exit(1);
    }



    pid_t f1 = fork();

    if(f1<0)
    {
    	printf("blad forka");
    	exit(1);
    }
    else
    if(f1==0)
    {
    	execl(argv[1], argv[1], argv[3], NULL);
    	perror("blad funkcji execl");
    	exit(1);
    }

    int output = open("out.txt", O_RDWR | O_CREAT | O_APPEND | O_TRUNC, 0666);

    if(output == -1)
    {
        perror("blad funkcji open");
        exit(1);
    }

    pid_t f2 = fork();

    if(f2<0)
    {
    	printf("blad forka");
    	exit(1);
    }
    else
    if(f2==0)
    {
    	execl(argv[2], argv[2], "out.txt", NULL);
    	perror("blad funkcji execl");
    	exit(1);
    }

    wait(NULL);
    wait(NULL);

    if(atexit(end) != 0)
    {
    	perror("blad atexit");
    	exit(1);
    }
    closeSMF(prodes);
	closeSMF(kondes);

    return 0;
}