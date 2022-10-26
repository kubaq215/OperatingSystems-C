#define _POSIX_C_SOURCE 200112L
#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include<sys/wait.h>

typedef void (*sighandler_t)(int);
sighandler_t signal(int sig, sighandler_t signal);



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
        setpgid(getpid(), 0);
       
        if(signal(atoi(argv[1]), SIG_IGN) == SIG_ERR)
        {
            perror("Blad funkcji signal.");
            exit(EXIT_FAILURE);
        }
        else 
        	printf("*Sygnal zostal zignorowany*\n");

        int i;
        for(i=0; i<3; i++)
        {
            int g = fork();

            if(g<0)
			{
				perror("blad forka");
				exit(1);
			}
            else if(g==0)
            {
               	if(execl("./a.x", "a.x", argv[1], argv[2], NULL) == -1)
		    	{
		    		perror("blad funkcji execl");
		    		_exit(2);
		    	}
            }
            else
            {
                sleep(1);
            }
        }
        int status;

        wait(&status);
        if(WIFEXITED(status))
        	printf("Status: %d\n", WEXITSTATUS(status));

        wait(&status);
        if(WIFEXITED(status))
        	printf("Status: %d\n", WEXITSTATUS(status));
        
        wait(&status);
        if(WIFEXITED(status))
        	printf("Status: %d\n", WEXITSTATUS(status));
    }
    else
    {
    	sleep(3);

        if(kill(f, 0) == 0)
        {
            kill(-getpgid(f), atoi(argv[1]));
            printf("Sygnal wyslany\n\n");
        }
        else 
        	printf("Nie istnieje proces potomny\n");
    }
	return 0;
}