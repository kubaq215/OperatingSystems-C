#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <semaphore.h>
#include <sys/stat.h>

#include "biblioteka.h"

void handler(int signo)
{
	unlinkSMF();
	exit(1);
}

int main(int arg, char *argv[])
{
	createSMF("/semafor1", 1);
	sem_t *smf = openSMF("/semafor1");
	printf("Adres semafora: %p\n", (void *)smf);
    printf("Wartosc semafora: %d\n\n", valueSMF(smf));
    closeSMF(smf);

    int a = open("numer.txt", O_RDWR | O_CREAT | O_APPEND | O_TRUNC, 0666);
    if(a == -1)
    {
        perror("blad funkcji open");
        exit(1);
    }

    int test = 0;
    if(write(a, &test, sizeof(int)) == -1)
    {
        perror("blad funkcji write");
        exit(1);
    }
    close(a);

    if(signal(SIGINT, handler) == SIG_ERR)
    {
        perror("blad funkcji signal");
        exit(1);
    }

    int i;
    for(i=0; i<4; i++)
    {
    	pid_t f = fork();

    	if(f<0)
    	{
    		perror("blad forka");
    		exit(1);
    	}
    	else
    	if(f==0)
    	{
    		sleep(1+(2*i));
    		execl("procesy.x", "./procesy.x", NULL);
            perror("blad funkcji execl");
            exit(1);
    	}
    }
    wait(NULL);
    wait(NULL);
    wait(NULL);
    wait(NULL);

    int b = open("numer.txt", O_RDONLY, 0666);
    if(b == -1)
    {
        perror("blad funkcji open");
        exit(1);
    }
    
    if(read(b, &test, sizeof(int)) == -1)
    {
        perror("blad funkcji read");
        exit(1);
    }

    printf("Numer testowy: %i\n", test);

    if(test == i)
    	printf("Wszystko ok\n");
    else
    	printf("Cos nie tak\n");

    close(b);

    if(atexit(unlinkSMF) != 0)
    {
    	perror("blad atexit");
        exit(1);
    }

    return 0;
}