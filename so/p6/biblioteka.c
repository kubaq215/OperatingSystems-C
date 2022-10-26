#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <semaphore.h>
#include <sys/stat.h>

#include "biblioteka.h"

sem_t *openSMF(const char *nazwa)
{
	sem_t *s = sem_open(nazwa, 1);
    if(s == SEM_FAILED)
    {
        perror("blad sem_open");
        exit(1);
    }
    return s;
}

void createSMF(const char *nazwa, unsigned int war)
{
    sem_t *smf = sem_open(nazwa, O_CREAT | O_EXCL, 0777, war);
    if(smf == SEM_FAILED)
    {
        perror("blad sem_open");
        exit(1);
    }
    printf("**Semafor utworzony**\n");
    printf("Nazwa semafora: %s\n", nazwa);
}

void postSMF(sem_t *smf)
{
	if(sem_post(smf) == -1)
    {
        perror("blad sem_post");
        exit(1);
    } 
    else
    	printf("**Semafor podniesiony**\n");
}

void waitSMF(sem_t *smf)
{
    if(sem_wait(smf) == -1)
    {
        perror("blad sem_wait");
        exit(1);
    } 
    else
    	printf("**Semafor opuszczony**\n");
}

int valueSMF(sem_t *smf)
{
    int war;
    if(sem_getvalue(smf, &war) == -1)
    {
        perror("blad sem_getvalue");
        exit(1);
    }
    return war;
}

void closeSMF(sem_t *smf)
{
	if(sem_close(smf) == -1)
    {
        perror("blad sem_close");
        exit(1);
    }
    else
    	printf("**Semafor zamkniety**\n");
}

void unlinkSMF(void)
{
	if(sem_unlink("/semafor1") == -1)
    {
        perror("blad sem_unlink");
        exit(1);
    }
    else
    	printf("**Semafor usuniety**\n");
}