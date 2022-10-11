#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t b,c,d;
    b=fork();
    if(b==0)
    {
        sleep(3);
        printf("child 1-->PID:%d\n",getpid());
        printf("child 1-->PPID:%d\n",getppid());    
    }
    else
    {
        c=fork();
        if(c==0)
        {
            sleep(2);
            printf("child 2-->PID:%d\n",getpid());
            printf("child 2-->PPID:%d\n",getppid());    
        }
        else
        {
            d=fork();
            if(d==0)
            {
                printf("child 3-->PID:%d\n",getpid());
                printf("child 3-->PPID:%d\n",getppid());   
            }
            else
            {
                sleep(5);
                printf("parent-->PID:%d\n",getpid());
                printf("parent-->PPID:%d\n",getppid());
            }
        }
    }
    return 0;
    
}
