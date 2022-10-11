#include<stdio.h>
#include <stdlib.h>

int FORWARD=1, BACK=-1, disk_size=200;

int dist(int a, int b)
{
    return abs(a-b);
}

int direction(int head, int prev)
{
    if(head>=prev)
        return 1;
    else
        return -1;
}

void bubblesort(int arr[],int size){
	int temp;
	int flag=0;
	for(int i=0;i<size;i++){
		flag=0;
		for(int j=0;j<size-i-1;j++){
			if(arr[j]>arr[j+1]){
				flag=1;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
		if(flag==0)
			break;
	}
}

int FCFS()
{
    int n, head,i,seek=0;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int request[n];
    printf("Enter the current head position: ");
    scanf("%d", &head);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the request %d: ",i);
        scanf("%d",&request[i]);
    }
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            seek+=abs(head-request[i]);
        }
        seek+=abs(request[i+1]-request[i]);
    }
    printf("\ntotal seek time in fcfs:%d",seek);
}

int SCAN()
{
    int n, head,prev,i,seek=0,dir;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int request[n];
    printf("Enter the current head position: ");
    scanf("%d", &head);
    printf("Enter the previous head position: ");
    scanf("%d", &prev);
    int index_min=-1, index_max=-1;
    dir=direction(head,prev);
    
    for(i=0;i<n;i++)
    {
        printf("\nEnter the request %d: ",i);
        scanf("%d",&request[i]);
    }
    bubblesort(request,n);
    for(int i=0;i<n;i++){
		printf("%d\t",request[i]);
	}
    for(i=0;i<n;i++)
    {
        if(dir==FORWARD)
        {
            if(head<request[i])
            {
                index_min=i;
                break;
            }
        }
        else
        {
            if(head>request[i])
            {
                index_max=i;
            }
        }
    }
    if(dir==FORWARD)
    {
        for(i=index_min;i<n;i++)
        {
            if(i==n-1)
            {
                seek+=dist(request[i], head);
                head=disk_size-1;
                seek+=dist(request[i], head);
            }
            else
            {
                seek+=dist(request[i], head);
                head=request[i];
            }
        }
        head=disk_size-1;
        for(i=index_min-1;i>=0;i--)
        {
            if(i==0)
            {
                seek+=dist(head,request[i]);
            }
            else
            {
                seek+=dist(head,request[i]);
                head=request[i];
            }
        }
    }
  printf("\ntotal seek time in scan:%d",seek);
    
}

int CSCAN()
{
    int n, head,prev,i,seek=0,dir;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int request[n];
    printf("Enter the current head position: ");
    scanf("%d", &head);
    printf("Enter the previous head position: ");
    scanf("%d", &prev);
    int index_min=-1, index_max=-1;
    dir=direction(head,prev);
    
    for(i=0;i<n;i++)
    {
        printf("\nEnter the request %d: ",i);
        scanf("%d",&request[i]);
    }
    bubblesort(request,n);
    for(int i=0;i<n;i++){
		printf("%d\t",request[i]);
	}
    for(i=0;i<n;i++)
    {
        if(dir==FORWARD)
        {
            if(head<request[i])
            {
                index_min=i;
                break;
            }
        }
        else
        {
            if(head>request[i])
            {
                index_max=i;
            }
        }
    }
    for(i=index_min;i<n;i++)
    {
        if(i==n-1)
            {
                seek+=dist(request[i], head);
                head=disk_size-1;
                seek+=dist(request[i], head);
                head=0;
                seek+=dist(request[i], head);
            }
            else
            {
                seek+=dist(request[i], head);
                head=request[i];
            }
    }
    for(int i=0;i<index_min;i++){
				seek+=dist(request[i],head);
				head=request[i];
		}
        printf("\ntotal seek time in cscan:%d",seek);
}

int main()
{
    while(1)
    {
        int choice;
        printf("\nChoose a Disk scheduling algorithm:\n");
        printf("1.FCFS\n2.SCAN\n3.C-SCAN\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            	FCFS();
            break;
            case 2:
            	SCAN();
            break;
            case 3:
            	CSCAN();
            case 4: 
				exit(0);
            break;
        }
    }
}