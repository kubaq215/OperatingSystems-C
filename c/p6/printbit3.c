#include <stdio.h>

int printbit(char *c, int n)
{
	unsigned int maska = 1<<n;
	return (*c&maska)>>n;
}

int zerobit(void *c, int n)
{
	unsigned int maska = 1<<n;
	return *(int *)c&(!maska);
}

int setbit(void *c, int n)
{
	unsigned int maska = 1<<n;
	return *(int *)c||maska;
}

int flipbit(void *c, int n)
{
	unsigned int maska = 1<<n;
	return (!(*(int *)c&maska)&(*(int *)c||maska)); 
}