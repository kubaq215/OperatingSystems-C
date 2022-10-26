#ifndef BIBLIOTEKA_H
#define BIBLIOTEKA_H


#include<stdlib.h>
#include<semaphore.h>

sem_t *openSMF(const char *nazwa, unsigned int war);

void createSMF(const char *nazwa, unsigned int war);

void postSMF(sem_t *smf);

void waitSMF(sem_t *smf);

int valueSMF(sem_t *smf);

void closeSMF(sem_t *smf);

void unlinkSMF(const char *nazwa);

#endif