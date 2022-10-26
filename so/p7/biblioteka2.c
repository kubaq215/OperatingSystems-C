#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include "biblioteka2.h"

int openSHM(const char *nazwa)
{
	int des = shm_open(nazwa, O_RDWR, 000);
    if(des == -1)
    {
        perror("blad shm_open");
        exit(1);
    }
    return des;
}

void createSHM(const char *nazwa, int size)
{
    int des = shm_open(nazwa, O_RDWR | O_CREAT | O_EXCL, 0644);
    if(des == -1)
    {
        perror("blad shm_open");
        exit(1);
    }

    if(ftruncate(des, size) == -1)
    { 
        perror("blad ftruncate");
        exit(1);
    }
    
    closeSHM(des);
}

void *mapSHM(int des, int size)
{
    Shmem *adres = (Shmem *) mmap(NULL, size, 
    					PROT_EXEC | PROT_READ | PROT_WRITE, MAP_SHARED, des, 0);
    if(adres == MAP_FAILED)
    {
        perror("blad mmap");
        exit(1);
    }
    printf("**Odwzorowano pamiec dzielona**\n");
    return adres;
}

void unmapSMH(void *adres)
{
    if(munmap(adres, sizeof(Shmem)) == -1)
    {
        perror("blad munmap");
        exit(1);
    }
    printf("**Usunieto odwzorowanie**\n");
}

void sizeSHM(int des)
{
    if(ftruncate(des, sizeof(Shmem)) == -1)
    { 
        perror("blad ftruncate");
        exit(1);
    }
    printf("Rozmiar pamieci dzielonej: %ld\n", sizeof(Shmem));
}

void closeSHM(int des)
{
	if(close(des) == -1)
	{
		perror("blad close");
		exit(1);
	}
}

void unlinkSHM(void)
{
    if(shm_unlink("/shm") == -1)
    {
        perror("blad shm_unlink");
        exit(1);
    }
    printf("**Usunieto pamiec dzielona**\n");
}