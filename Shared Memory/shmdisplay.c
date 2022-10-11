#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<unistd.h>

typedef struct StudentDetails
{
    char name[10];
    int rank;
    int count;
} Student;

void swap(Student *std1, Student *std2)
{
    Student temp;
    strcpy(temp.name, std1->name);
    temp.rank = std1->rank;

    strcpy(std1->name, std2->name);
    std1->rank = std2->rank;

    strcpy(std2->name, temp.name);
    std2->rank = temp.rank;
}

void bubbleSort(Student *s_details, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (s_details[j].rank < s_details[j + 1].rank)
            {
                swap(&s_details[j], &s_details[j + 1]);
            }
        }
    }
}

void main()
{
    Student st[10];
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 );
    Student *data = (Student *)shmat(shmid, NULL, 0);

    memcpy(st, data, 10 * sizeof(Student));

    printf("The ranklist is:\n");
    bubbleSort(st, st[0].count);
    for (int i = 0; i < st[0].count; i++)
    {
        printf("\nRank: %d\n", i + 1);
        printf("Name: %s\n", st[i].name);
        printf("Mark: %d\n", st[i].rank);
    }

    shmdt(data); 

    shmctl(shmid, IPC_RMID, NULL); 
}