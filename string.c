
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(char argc[], char *argsv[])
{
        int fd[2];
        char val[30]="";
        pipe(fd);
        if(fork() != 0)
        {
                close(fd[0]);
                printf("Enter the string to pass:");
                scanf("%s",val);
                write(fd[1], &val, sizeof(val));
                close(fd[1]);
        }
        else
        {
                sleep(2);
                int alphabets=0, digits=0;
                close(fd[1]);
                read(fd[0], &val, sizeof(val));
                printf("Child(%d) received value : %s \n", getpid(),val);
                for(int i=0;val[i];i++)
                {
                     if((val[i]>=65 && val[i]<=90)|| (val[i]>=97 && val[i]<=122) )
                               alphabets++;
                     else if(val[i]>=48 && val[i]<=57)
                              digits++;
                }
                sleep(2);
                printf("\nNo of charecter is : %d",alphabets);
                printf("\nNo of digits is : %d",digits);
                close(fd[0]);
        }
        return 0;
}
