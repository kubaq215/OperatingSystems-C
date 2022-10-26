#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include<string.h>


void end()
{
	unlink("fifo");
}

int main(int arg, char *argv[])
{
	if(arg!=2)
    {
        printf("Nieprawidlowe wywolanie programu.\n");
        exit(1);
    }

    if(mkfifo("fifo", 0777) == -1)
    {
        perror("blad mkfifo");
        exit(1);
    }

    int f1 = fork();

    if(f1==0)
    {
        if(execl("./producent.x","producent.x", argv[1], "fifo", NULL) == -1)
        {
        	perror("blad execl");
        	_exit(1);
        }	
    }
    
    if(f1<0)
    {
        perror("blad forka");
        exit(1);
    }

    int f2 = fork();

    if(f2==0)
    {
        if(execl("./konsument.x","konsument.x", argv[2], "fifo", NULL) == -1)
        {
        	perror("blad execl");
        	_exit(1);
        }	
    }
    
    if(f2<0)
    {
        perror("blad forka");
        exit(1);
    }
    
    wait(NULL);
   	
    if(atexit(end) != 0)
    {
        perror("blad atexit");
        exit(1);
    }
    return 0;

}