#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<unistd.h>
#include <string.h>

typedef struct studentd
{
    char name[10];
    int mark;
    int count;
}student;

int main()
{

    key_t key=ftok("shmfile", 65);
    int shmid=shmget(key,1024,0666 | IPC_CREAT);
    student st[10];
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        printf("Enter details of students 1:(name, mark) ");
        scanf("%s%d", st[i].name, &st[i].mark);
        st[i].count=n;
    }
    student *data  = (student *)shmat(shmid, NULL, 0);
    memcpy(data, st, 10*sizeof(student));
     shmdt(data);
    printf("\nSuccessfully copied to the memory.\n");
}