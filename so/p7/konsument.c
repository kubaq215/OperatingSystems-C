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

	int output = open(argv[1], O_WRONLY, 0);
	if(output == -1)
	{
		perror("blad funkcji open");
		exit(1);
	}

	Shmem *map;
	int des = openSHM("/shm");
	map = mapSHM(des, sizeof(Shmem));
	map->wyjmij = 0;

	sem_t *prodes = openSMF("/prod", LEL);
	sem_t *kondes = openSMF("/kons", 0);

	printf("-------KONSUMENT-------\n*Sekcja prywatna*  ID procesu: %i  "
		   "Wartosc semafora: %i\n\n", getpid(), valueSMF(kondes));
	sleep(4);

	while(1)
	{
		waitSMF(kondes);
		printf("------------------KONSUMENT------------------\n*Sekcja krytyczna*  ID procesu: %i  "
			   "Wartosc semafora: %i\n\n", getpid(), valueSMF(kondes));

        memcpy(bufo, map->buf[map->wyjmij], sizeof(bufo));
        map->wyjmij = (map->wyjmij + 1) % BUFS;

        if(write(output, bufo, sizeof(bufo)) == -1)
        {
            perror("blad funkcji write");
            exit(3);
        }
        
		printf("Tekst odebrany: \n");

		write(STDOUT_FILENO, bufo, sizeof(bufo));
        printf("\n\n");

		postSMF(prodes);
		printf("*Sekcja prywatna*  ID procesu: %i  "
			   "Wartosc semafora: %i\n\n", getpid(), valueSMF(kondes));

		sleep(1);
		
		if(map->buf[map->wyjmij][0] == '\0')
		{
            break;
        }
	}

	close(output);
	unmapSMH(map);
	close(des);
	closeSMF(kondes);

	return 0;
}