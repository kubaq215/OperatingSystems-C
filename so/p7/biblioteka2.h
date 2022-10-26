#ifndef BIBLIOTEKA2_H
#define BIBLIOTEKA2_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>

#define LEL 4
#define BUFS 4

typedef struct
{
    char buf[LEL][BUFS];
    int wstaw, wyjmij;
} Shmem;

int openSHM(const char *nazwa);

void createSHM(const char *nazwa, int size);

void *mapSHM(int des, int size);

void unmapSMH(void *adres);

void sizeSHM(int des);

void closeSHM(int des);

void unlinkSHM(void);

#endif