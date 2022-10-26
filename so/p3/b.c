#define _POSIX_C_SOURCE 200112L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main(int arg, char *argv[])
{
	int f = fork();

	if(f<0)
	{
		perror("blad forka");
		exit(1);
	}
	else if(f==0)	
	{
		if(execl("./a.x", "a.x", argv[1], argv[2], NULL) == -1);
    	{
    		perror("blad funkcji execl");
    		_exit(2);
    	}
	}
	else
	{
		sleep(1);
    	if(kill(f, 0) == 0)
    	{
        	kill(f, atoi(argv[1]));
        		printf("Sygnal wyslany\n");
    	}
    	else 
    		printf("Nie istnieje proces potomny\n");
	}
	
	return 0;
}