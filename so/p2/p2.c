#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int arg, char *argv[])
{
	printf("rodzic\n");
	printf("UID = %i, GID = %i, PID = %i, PPID = %i, PGID = %i\n", 
			getuid(), getgid(), getpid(), getppid(), getpgrp());
	printf("dzieci\n");
	int i;
	for(i=0; i<3; i++)
	{
		switch(fork())
		{
			case -1:
				perror("blad forka");
				exit(1);
			case 0:
				execl(argv[1], argv[2], NULL);
				perror("execl error");
				_exit(2);
			default:
				wait(NULL);
		};
	}
	return 0;
}
