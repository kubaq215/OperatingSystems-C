#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "biblioteka.h"
#include "biblioteka2.h"

int main(int arg, char *argv[])
{
	char bufo[BUFS];

	int input = open(argv[1], O_RDONLY, 0);
	if(input == -1)
	{
		perror("blad funkcji open");
		exit(1);
	}

	Shmem *map;
	int des = openSHM("/shm");
	map = mapSHM(des, sizeof(Shmem));
	map->wstaw = 0;

	sem_t *prodes = openSMF("/prod", LEL);
	sem_t *kondes = openSMF("/kons", 0);

	printf("-------PRODUCENT-------\n*Sekcja prywatna*  ID procesu: %i  "
		   "Wartosc semafora: %i\n\n", getpid(), valueSMF(prodes));

	while(1)
	{
		waitSMF(prodes);
		int des1 = read(input, bufo, sizeof(bufo));
		if(des1 == -1)
		{
			perror("blad funkcji read");
			exit(1);
		}
		if(des1 == 0)
		{
			map->buf[map->wstaw][0] = '\0';
			break;
		}

		printf("------------------PRODUCENT------------------\n*Sekcja krytyczna*  ID procesu: %i  "
			   "Wartosc semafora: %i\n\n", getpid(), valueSMF(prodes));		

		printf("Tekst przenoszony: \n");

		write(STDOUT_FILENO, bufo, sizeof(bufo));
        printf("\n\n");

		memcpy(map->buf[map->wstaw], bufo, sizeof(bufo));
		map->wstaw = (map->wstaw + 1) % BUFS;

		postSMF(kondes);

		printf("*Sekcja prywatna*  ID procesu: %i  "
			   "Wartosc semafora: %i\n\n", getpid(), valueSMF(prodes));
		sleep(1);
	}

	sleep(3);
	close(input);
	unmapSMH(map);
	close(des);
	closeSMF(prodes);

	return 0;
}