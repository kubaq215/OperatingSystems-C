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


int main(int arg, char *argv[])
{
	sem_t *smf = openSMF("/semafor1");

    printf("- - - - - - - - - - - - - - - - - - - -");
	printf("\nProces potomny: %i. Wartosc semafora: %i\n", getpid(), valueSMF(smf));
    waitSMF(smf);
    printf("                                   Sekcja krytyczna procesu: %i.\nWartosc semafora: %i\n\n", getpid(), valueSMF(smf));

    int a = open("numer.txt", O_RDONLY, 0666);
    if(a == -1)
    {
        perror("blad funkcji open");
        exit(1);
    }

    int test;
    if(read(a, &test, sizeof(int)) == -1)
    {
        perror("blad funkcji read");
        exit(1);
    }
    printf("Wartosc odczytana z pliku: %i\n\n", test);
    test++;
    close(a);   
    sleep(1);

    int b = open("numer.txt", O_WRONLY, 0666);
    if(b == -1)
    {
        perror("blad funkcji open");
        exit(1);
    }
    
    if(write(b, &test, sizeof(int)) == -1)
    {
        perror("blad funkcji write");
        exit(1);
    }
    close(b);
    postSMF(smf);
    printf("Sekcja prywatna procesu: %i.\nWartosc semafora: %i\n", getpid(), valueSMF(smf));
    printf("- - - - - - - - - - - - - - - - - - - -\n");

    return 0;
}