#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "a.h"

int main()
{
	wypisz();
	int i;
	for(i=0; i<3; i++)
	{
		switch(fork())
		{
			case -1:
				perror("blad forka");
				exit(-1);
			case 0:
				wypisz1();
			default:
				wait(NULL);
		};
	}
	return 0;
}
