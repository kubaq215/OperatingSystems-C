#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<time.h>
#include<string.h>


int main(int arg, char *argv[])
{
	char buf[4];
	srand(time(NULL));
	int des1 = open(argv[1], 0);
	int des2 = open("fifo", O_RDWR);

	if(des1 == -1 || des2 == -1)
	{
        perror("blad funkcji open");
        exit(1);
    }

    int k=1;
    while(k)
    {
        int czas = rand() % 3;
        sleep(czas);
        
    	k = read(des1, buf, sizeof(buf));
        if(k == -1)
        {
            perror("blad\n");
            exit(1);        
        }
        if(k == 0)
        {  break;}
        
    	if(write(des2, buf, k) == -1)
        {
            perror("blad\n");
            exit(1);        
        }
        printf("Tekst przeczytany: %s\n", buf);
    }
    close(des1);
    return 0;
}