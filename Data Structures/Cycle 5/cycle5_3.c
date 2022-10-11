#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct queue
{
    struct node* front;
    struct node* rear;
};

void display(struct node* newnode)
{
    printf("Queue:\n");
    while(newnode != NULL)
    {
    printf("%d\t", newnode->data);  
    newnode = newnode->next;
    }
}

void enqueue(struct queue *q, struct node* head)
{
    int X;
    printf("Enter element\n");
    scanf("%d", &X);
    if(q->rear == NULL)
    {
        q->front = (struct node*) malloc(1*sizeof(struct node));
        head->next = q->front;
        q->rear = q->front;
        q->rear->data = X;
        q->rear->next = NULL;
    }
    else
    {
        q->rear->next = (struct node*) malloc(1*sizeof(struct node));
        q->rear->next->data = X;
        q->rear->next->next = NULL;
        q->rear = q->rear->next;
    }
}

int dequeue(struct queue *q, struct node* head)
{
    if(q->front == NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        int X = q->front->data;
        head->next = q->front->next;
        free(q->front);
        q->front = head->next;
        printf("Element deleted\n");
        if(q->front == NULL)
        q->rear = NULL;
        return X;
    }
}

void main()
{
    struct node* qhead = (struct node*) malloc(1*sizeof(struct node));
    struct queue q;
    q.front = NULL;
    q.rear = NULL;
    qhead->next = q.front;
    int flag;
    do
    {
        printf("\nChoose an operation to perform:\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n\n");
        scanf("%d", &flag);
        switch(flag)
        {
            case 1:
                enqueue(&q, qhead);
               break;
            case 2:
                dequeue(&q, qhead);
               break;
            case 3:
                display(q.front);
               break;
            case 4:
                exit(0);
            default:
                printf("Invalid input!\n");
               break;
        }
    } while (1);
}
