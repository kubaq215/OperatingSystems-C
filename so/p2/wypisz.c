#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("UID = %i, GID = %i, PID = %i, PPID = %i, PGID = %i\n", 
			getuid(), getgid(), getpid(), getppid(), getpgrp());
}



