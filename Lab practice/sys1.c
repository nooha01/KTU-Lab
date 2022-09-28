#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

void Fibonacci(int n)
{
         int first=0,second=1,sum=0;
         for(int i=0;i<n;i++)
         {
                  printf("%d\t",sum);
                  first=second;
                  second=sum;
                  sum=first+second;
         }
}

void prime(int n)
{
      
}

int main()
{
         int n;
         printf("Enter the limiting value: ");
         scanf("%d",&n);
         pid_t pid;
         pid=fork();
         if(pid==0)
         {
                  wait(NULL);
                  printf("\nParent!\n");
                  prime(n);
         }
         else if(pid>0)
         {
                  printf("\nChild!\n");
                  Fibonacci(n);
         }
         else
         {
                  printf("Error in child creation!!");
         }
         
}
