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

void main()
{
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    Student st[10];
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nDetails of Student %d\n", i+1);
        printf("Enter name: ");
        scanf("%s", st[i].name);
        printf("Enter Mark: ");
        scanf("%d", &st[i].rank);
        st[i].count = n;
    }

    Student *data = (Student *)shmat(shmid, NULL, 0);

    memcpy(data, st, 10 * sizeof(Student));

    shmdt(data);
    printf("\nSuccessfully copied to the memory.\n");

}