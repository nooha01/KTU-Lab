#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    printf("\nA: %d", getpid());
    if(fork()==0)
    {
        printf("\nB: %d forked by %d", getpid(), getppid());
        if(fork()==0)
        {
            printf("\nD: %d forked by %d", getpid(), getppid());
            if(fork()==0)
            {
                printf("\nH: %d forked by %d", getpid(), getppid());
                if(fork()==0)
                {
                    printf("\nI: %d forked by %d", getpid(), getppid());
                }
                else   
                    wait(NULL);
            }
            else
                wait(NULL);
        }
        else if(fork()==0)
        {
            printf("\nE: %d forked by %d", getpid(), getppid());
        }  
        else if(fork()==0)
        {
            printf("\nF: %d forked by %d", getpid(), getppid());
        }
        else 
            wait(NULL);
    }
    else if(fork()==0)
    {
        printf("\nC: %d forked by %d", getpid(), getppid());
        if(fork()==0)
        {
            printf("\nG: %d forked by %d", getpid(), getppid());
        }
        else
        {
            wait(NULL);
        }
    }
    
    else
        wait(NULL);
}