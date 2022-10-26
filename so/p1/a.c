#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void wypisz()
{
	printf("rodzic   - UID = %i, GID = %i, PID = %i, PPID = %i, PGID = %i\n", 
			getuid(), getgid(), getpid(), getppid(), getpgrp());
}

void wypisz1()
{
	printf("dziecko  - UID = %i, GID = %i, PID = %i, PPID = %i, PGID = %i\n", 
			getuid(), getgid(), getpid(), getppid(), getpgrp());
}

