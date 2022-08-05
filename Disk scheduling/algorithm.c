#include<stdio.h>
#include<stdlib.h>
int f,p,str[30];
int fr[4], count=0;

static int disk_size=200;
const int FORWARD = 1;
const int BACKWARD = -1;

int dist(int a,int b){
	return abs(a-b);
}

int is_completed(int arr[],int n){
	for(int i=0;i<n;i++){
		if(arr[i]!=1)
			return 0;
	}
	return 1;
}

int direction(int head,int prev){
	if(prev<=head){
		return 1;		
	}
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

void FCFS()
{
    int seek=0,head=0,arr[10];		
	int n;
	printf("enter no of request:");
	scanf("%d",&n);
	int request[n];
	printf("current head position is at:");
	scanf("%d",&head);
	for(int i=0;i<n;i++){
		printf("enter the request %d:",i+1);
		scanf("%d",&request[i]);
	}
	for(int i=0;i<n-1;i++){
		if(i==0){
			seek+=request[i]-head;
		}
		seek+=abs(request[i+1]-request[i]);
	}
	printf("\ntotal seek time in fcfs:%d",seek);
}

void SCAN()
{
    int seek=0,prev=0,head=0,min=99999;		
	int n,dir;
	printf("enter no of request:");
	scanf("%d",&n);
	int request[n];
	int flag[n];
	int index_min=-1;
	int index_max=-1;
	printf("current head position is at:");
	scanf("%d",&head);
	printf("previous head position is at:");
	scanf("%d",&prev);
	for(int i=0;i<n;i++){
		printf("enter the request %d:",i+1);
		scanf("%d",&request[i]);
		flag[i]=0; 				
	}
	dir = direction(head,prev);
	bubblesort(request,n);		
	for(int i=0;i<n;i++){
		printf("%d\t",request[i]);
	}
	printf("\n");
	for(int i=0;i<n;i++){
		if(dir==FORWARD){
			if(request[i]>head){
				index_min=i;
				break;
			}
		}
		else{
			if(request[i]<head){
				index_max=i;
			}
		}
	}
	if(dir==FORWARD){
		for(int i=index_min;i<n;i++){
			if(i==n-1){
				seek+=dist(request[i],head);
				head=disk_size-1;
				printf("%d\t",seek);
				seek+=dist(request[i],head);
				printf("%d\t",seek);
			}
			else{
				seek+=dist(request[i],head);
				head=request[i];
				printf("%d\t",seek);
			}
		}
		head=disk_size-1;
		for(int i=index_min-1;i>=0;i--){
			if(i==0){
				seek+=dist(request[i],head);
				printf("%d\t",seek);			
			}
			else{
				seek+=dist(request[i],head);
				printf("%d\t",seek);
				head=request[i];
			}
		}
	}
	if(dir==BACKWARD){
		for(int i=index_max;i>=0;i--){
			if(i==0){
				seek+=dist(request[i],head);
				seek+=request[i];
				printf("%d\t",seek);
				head=0;
			}
			else{
				seek+=dist(request[i],head);
				head=request[i];
				printf("%d\t",seek);
			}
		}
		head=0;
		for(int i=index_max+1;i<n;i++){
			if(i==0){
				seek+=dist(request[i],head);
				printf("%d\t",seek);
				head=request[i];
			}
			else{
				seek+=dist(request[i],head);
				head=request[i];
				printf("%d\t",seek);
			}
		}

	}
	printf("\ntotal seek time in scan:%d",seek);
}

void CSCAN()
{
    int seek=0,prev=0,head=0,min=99999;		
	int n,dir;
	printf("enter no of request:");
	scanf("%d",&n);
	int request[n];
	int flag[n];
	int index_min=-1;
	int index_max=-1;
	printf("current head position is at:");
	scanf("%d",&head);
	printf("previous head position is at:");
	scanf("%d",&prev);
	for(int i=0;i<n;i++){
		printf("enter the request %d:",i+1);
		scanf("%d",&request[i]);
		flag[i]=0; 				
	}
	dir = direction(head,prev);
	bubblesort(request,n);	
	for(int i=0;i<n;i++){
		printf("%d\t",request[i]);
	}
	printf("\n");
	for(int i=0;i<n;i++){
		if(dir==FORWARD){
			if(request[i]>head){
				index_min=i;
				break;
			}
		}
		else{
			if(request[i]<head){
				index_max=i;
			}
		}
	}
	if(dir==FORWARD){
		for(int i=index_min;i<n;i++){
				seek+=dist(request[i],head);
				head=request[i];
				printf("%d\t",request[i]);
				printf("\nseek:%d\t",seek);
		}
		seek+=dist(head,disk_size-1);
		head=0;
		seek+=dist(head,disk_size-1);
		for(int i=0;i<index_min;i++){
				seek+=dist(request[i],head);
				head=request[i];
		}
	}
	if(dir==BACKWARD){
		for(int i=index_max;i>=0;i--){
				seek+=dist(request[i],head);
				head=request[i];
		}
		seek+=dist(head,0);
		//printf("xxxx%d\t",seek);
		head=0;
		seek+=dist(head,disk_size-1);
		//printf("%d\t",seek);
		head=disk_size-1;
		for(int i=n-1;i>index_max;i--){
				seek+=dist(request[i],head);
				head=request[i];
		}
	}
	printf("\ntotal seek time in scan:%d",seek);
}

int main()
{
    while(1)
    {
        int choice;
        count=0;
        printf("\nChoose a Page Replacement algorithm:\n");
        printf("1.FCFS\n2.SCAN\n3.C-SCAN\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        for(int i=0;i<f;i++)
        {
            fr[i]=-1;
        }
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