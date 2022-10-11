#include<stdio.h>
#define N 5
int dq[N];
int front=-1;
int rear=-1;
void enqueuer();
void dequeuer();
void enqueuef();
void dequeuef();
void display();

void main()
{
  	int n,m;
  	do
  	{	
    		printf("\nChoose an operation\nEnter 1 for enqueue at front\nEnter 2 for dequeue at front\nEnter 3 for enqueue at rear\nEnter 4 for dequeue at rear\nEnter 5 for display\n");
    		scanf("%d",&n);
    		switch(n)
    		{
      			case 1: 
                                    enqueuef();
		   	   	break;
	  		case 2:
               			dequeuef();
		   	   	break;
	  		case 3:
	           		enqueuer();
			   	break;
	  		case 4:
	           		dequeuer();
			   	break;
      			case 5:
               			display();	
			   	break;
    		}
    		printf("Enter 1 for more operations: ");
    		scanf("%d",&m);
  	}while(m==1);
}

void enqueuef()
{
   	int item;
   	printf("Enter the element to be inserted: ");
   	scanf("%d",&item);
   	if((front==0&&rear==N-1)||(front==rear+1))
   	{
    	 	printf("Overflow\n");
   	}
   	else if(front==-1&&rear==-1)
   	{
      		front=rear=0;
	  	dq[front]=item;
   	}
   	else if(front==0)
   	{
   	 	 front=N-1;
	  	dq[front]=item;
   	}
   	else
   	{
      	front--;
	dq[front]=item;
   	}
}

void enqueuer()
{
   	int item;
   	printf("Enter the element to be inserted: ");
   	scanf("%d",&item);
   	if((front==0&&rear==N-1)||(rear==front-1))
   	{
   	   	printf("overflow\n");
   	}
   	else if(front==-1&&rear==-1)
   	{ 
	  	front=rear=0;
	  	dq[rear]=item;
   	}
   	else if(rear==N-1)
   	{
	 	rear=0;
     		dq[rear]=item;	 
   	}
   	else
   	{
   	  	rear++;
	 	dq[rear]=item;
   	}
}

void dequeuef()
{
   	if(front==-1&&rear==-1)
   	{
      		printf("Underflow\n");
   	}
   	else if(front==rear)
   	{ 
      		printf("Deleted element is %d\n",dq[front]);
	  	front=rear=-1;
   	}
   	else if(front==N-1)
   	{
		 printf("Deleted element is %d\n",dq[front]);
		 front=(front+1)%N; 
   	}
   	else
   	{
   	   	printf("Deleted element is %d\n",dq[front]);
	  	front++;
   	}
}

void dequeuer()
{
   	if(front==-1&&rear==-1)
   	{
   		   printf("Underflow\n");
   	}
   	else if(front==rear)
   	{ 
   		   printf("Deleted element is %d\n",dq[rear]);
		  front=rear=-1;
   	}
   	else if(rear==0)
   	{
		 printf("Deleted element is %d\n",dq[rear]);
		 rear=N-1; 
   	}
   	else
   	{
   		   printf("Deleted element is %d\n",dq[rear]);
        		   rear--;
   	}
}

void display()
{
  	int i;
  	if(front==-1&&rear==-1)
  	{
  	   	printf("Q is empty\n");
  	}
  	else
  	{
  		  i=front;
		  while(i!=rear)
    		{
      			 printf("%d\n",dq[i]);
			   i=(i+1)%N;
	}
	 printf("%d",dq[rear]);
	 printf("\n");
  }
}
