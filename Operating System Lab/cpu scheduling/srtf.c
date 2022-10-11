#include<stdio.h>

struct process
{
    int WT,AT,BT,TAT;
};

struct process a[10];
int main()
{
    int n,temp[10],i,j;
    int count=0,t=0,small;
    float total_WT=0, total_TAT=0,Avg_WT,Avg_TAT;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the arrival time and burst time of the process %d: ", i+1);
        scanf("%d%d",&a[i].AT,&a[i].BT);
        temp[i]=a[i].BT;
    }
    a[9].BT=10000;
    for(t=0;count!=n;t++)
    {
        small=9;
        for(int i=0;i<n;i++)
        {
            if(a[i].BT<a[small].BT && (a[i].AT<=t && a[i].BT>0))
            {
                small=i;
            }
            
        }     
        a[small].BT=a[small].BT-1;
        if(a[small].BT==0)
        {
            count++;
            a[small].WT=t+1-a[small].AT-temp[small];
            a[small].TAT=t+1-a[small].AT;
            
            // total calculation
            total_WT=total_WT+a[small].WT;
            total_TAT=total_TAT+a[small].TAT;
        }      
    }
    Avg_WT=total_WT/n;
    Avg_TAT=total_TAT/n;

    printf("\n+-----+--------------+-----------------+\n");
	printf("| PID | Waiting Time | Turnaround Time |\n");
	printf("+-----+--------------+-----------------+\n");
	for(i=0; i<n; i++) 
	{
		printf("\n| p%d |      %2d     |        %2d         |\n",i+1, a[i].WT, a[i].TAT );
		printf("\n+-----+--------------+-----------------+");
	}
	printf(" ");
    
    printf("\nAvg waiting time of the process is %f\n",Avg_WT);
    printf("Avg turn around time of the process %f\n",Avg_TAT);   
}
