#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include<time.h>
#include<string.h>



int main(int arg, char *argv[])
{
	int filedes[2];
    char buf[4];
    srand(time(NULL));
    
    if(arg!=2)
    {
        printf("Nieprawidlowe wywolanie programu.\n");
        exit(1);
    }

    if(pipe(filedes) == -1)
    {
        perror("blad funkcji pipe");
        exit(2);
    }
    
    int des1 = open(argv[1], 0);
    int des2 = open("out.txt", O_RDWR | O_CREAT | O_APPEND | O_TRUNC, 0666);

    if(des1 == -1 || des2 == -1)
    {
        perror("blad funkcji open");
        exit(3);
    }

    int f = fork();

    if(f<0)
	{
		perror("blad forka");
		exit(4);
	}
    else 
	if(f==0)
    {
        close(filedes[1]);
        int k=1;
        while(k)
        {
            int czas = rand() % 3;
            sleep(czas);
        	k = read(filedes[0], buf, sizeof(buf));
            if(k == -1)
            {
                perror("blad\n");
                exit(1);        
            }
            if(k == 0)
              {  break;}
        	printf("Tekst przenoszony: %s\n", buf);
            
        	if(write(des2, buf, k) == -1)
            {
                perror("blad\n");
                exit(1);        
            }

        }
       
        close(filedes[0]);
        close(des2);
    }
    else 
	{
        close(filedes[0]);
        int k=1;
        while(k)
        {
            k = read(des1, buf, sizeof(buf));
            if(k == -1)
            {
                perror("blad");
                exit(1);
            }
            if(k == 0)
                break;
            printf("Przeczytano tekst: %s\n", buf);

            if(write(filedes[1], buf, k) == -1)
            {
                perror("blad funkcji write");
                exit(8);
        	}
    	} 
    	close(filedes[1]);
    	close(des1);
    	wait(NULL);
	}

    return 0;
}