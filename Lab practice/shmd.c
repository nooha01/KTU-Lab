#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct studentd
{
    char name[10];
    int mark;
    int count;
}student;

int swap(student *st1, student *st2)
{
    student temp;
    strcpy(temp.name, st1->name);
    temp.mark = st1->mark;
     strcpy(st1->name, st2->name);
    st1->mark = st2->mark;
     strcpy(st2->name,temp.name);
     st2->mark = temp.mark;
   
}

int bubblesort(student *std,int n)
{
    int i,j;
    for( i=0;i<n-1;i++)
    {
        for( j=0;j<n-i-1;j++)
        {
            if(std[j].mark<std[j+1].mark)
            {
                swap(&std[j], &std[j+1]);
            }
        }
    }
}

int main()
{
    key_t key=ftok("shmfile", 65);
    int shmid=shmget(key,1024,0666);
    student st[10];
    student *data  = (student *)shmat(shmid, NULL, 0);
    memcpy(st,data, 10*sizeof(student));
    printf("The ranklist is:\n");
    bubblesort(st,st[0].count);
    for (int i = 0; i < st[0].count; i++)
    {
        printf("\nRank: %d\n", i + 1);
        printf("Name: %s\n", st[i].name);
        printf("Mark: %d\n", st[i].mark);
    }

    shmdt(data); 
       shmctl(shmid, IPC_RMID, NULL); 
}