#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};

void display(struct node* stack)
{
    printf("Stack:\n");
    if(stack==NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        while(stack != NULL)
        {
            printf("%d\n", stack->data);
            stack = stack->next;
        }
    }
}

struct node* push(struct node* head)
{
    struct node* stack = (struct node*) malloc(1*sizeof(struct node));
    int X;
    printf("\nEnter element: ");
    scanf("%d", &X);
    stack->data = X;
    stack->next = head->next;
    head->next = stack;
    return stack;
}

int pop(struct node* head)
{
    struct node* stack;
    int data;
    if(head->next == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        stack = head->next;
        data = stack->data;
        head->next = stack->next;
        free(stack);
        printf("%d is popped\n",data);
        return data;
    }
}

void main()
{
    struct node* head = (struct node*) malloc(1*sizeof(struct node));
    struct node* TOP = NULL;
    head->next = TOP;
    int flag;
    do
    {
        printf("\nChoose an operation to perform:\n");
        printf("1.push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &flag);
        switch(flag)
        {
            case 1:
                TOP = push(head);
            break;
            case 2:
                pop(head);
                TOP = head->next;
            break;
            case 3:
                display(TOP);
            break;
            case 4:
                exit(0);
            default:
                printf("Invalid input!\n");
            break;
        }
    } while (1);   
}
