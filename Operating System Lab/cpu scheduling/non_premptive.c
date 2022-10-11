#include<stdio.h>
#include<stdlib.h>

void fcfs()
{
    int n,bt[10],t[10],w[10],wt[10],i,j;
	float att=0,awt=0, tp=0;
	printf("\nEnter the number of process: ");
	scanf("%d",&n);
   	printf("\nEnter Burst Time:\n");
	for(i=0;i<n;i++)
	{
		printf("p%d:",i+1);
		scanf("%d",&bt[i]);
	}
	wt[0]=0;
	for(i=0;i<n;i++)
	{
		wt[i+1]=wt[i]+bt[i];
		tp = tp + bt[i];
	}
	for(i=0;i<n;i++)
        {
		w[i]=wt[i];
		t[i]=wt[i+1];
		awt=awt+w[i];
		att=att+t[i];
        }
        tp=(n/tp);
	awt =awt/n;
	att=att/n;
	printf("\n+-----+------------+--------------+-----------------+\n");
	printf("| PID | Burst Time | Waiting Time | Turnaround Time   |\n");
	printf("+-----+------------+--------------+-----------------+\n");
	for(i=0; i<n; i++) 
	{
		printf("\n| p%2d  |     %2d     |      %2d      |        %2d    |\n",i+1,bt[i], w[i], t[i] );
		printf("\n+-----+------------+--------------+-----------------+");
	}
	printf(" ");
	printf("\n\nGantt chart is:\n");
	for(i=0; i<n; i++) 
	{
		for(j=0; j<bt[i]; j++) 
		printf("--");
		printf(" ");
	}
   	printf("\n|");
	for(i=0; i<n; i++) 
	{
		for(j=0; j<bt[i] - 1; j++)
				printf(" ");
		printf("P%d", i+1);
		for(j=0; j<bt[i] - 1; j++)
		printf(" ");
		printf("|");
	}
	printf("\n ");
	for(i=0; i<n; i++) 
	{
		for(j=0; j<bt[i]; j++)
		printf("--");
		printf(" ");
	}
	printf("\n");
	printf("0");
	for(i=0; i<n; i++)
	{
		for(j=0; j<bt[i]; j++)
			printf("  ");
		if(t[i] > 9) printf("\b"); 
		printf("%d", t[i]);
 	}
    printf("\n");
	printf("\n\nAverage waiting time is= %f\n",awt);
	printf("Average turn around time is= %f\n",att);
	printf("Throughput is= %f\n",tp);
}

void sjf()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float awt=0 ,att=0, tp=0;
    printf("Enter number of process: ");
    scanf("%d",&n);
    printf("\nEnter Burst Time: \n");
    for(i=0;i<n;i++)
    {
        printf("p%d: ",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;  
        tp = tp + bt[i];       
    }
  
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
  
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
  
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;            
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
  
        total+=wt[i];
    }
  
    awt=(float)total/n;      
    total=0;
    
    printf("\n+-----+------------+--------------+-----------------+\n");
    printf("| PID | Burst Time | Waiting Time | Turnaround Time |\n");
    printf("+-----+------------+--------------+-----------------+\n");
    for(i=0; i<n; i++) 
    {
    	tat[i]=bt[i]+wt[i];   
        total+=tat[i];
    	printf("\n| p%2d  |     %2d     |      %2d      |        %2d    |\n",p[i],bt[i], wt[i], tat[i] );
    	printf("\n+-----+------------+--------------+-----------------+");
    }
    printf(" ");
    printf("\n\nGantt chart is:\n");
    for(i=0; i<n; i++) 
    {
        for(j=0; j<bt[i]; j++) 
        	printf("--");
        printf(" ");
    }
    printf("\n|");
    for(i=0; i<n; i++) 
    {
        for(j=0; j<bt[i] - 1; j++)
        	printf(" ");
        printf("P%d", p[i]);
        for(j=0; j<bt[i] - 1; j++)
        	printf(" ");
        printf("|");
    }
    printf("\n ");
    for(i=0; i<n; i++) 
    {
        for(j=0; j<bt[i]; j++)
        	printf("--");
        printf(" ");
    }
    printf("\n");
    printf("0");
    for(i=0; i<n; i++)
    {
        for(j=0; j<bt[i]; j++)
        	printf("  ");
        if(tat[i] > 9) printf("\b"); 
        printf("%d", tat[i]);
 
    }
    printf("\n");
 
    tp=(n/tp);
    att=(float)total/n;    
    printf("\n\nAverage waiting time is= %f\n",awt);
    printf("Average turn around time is= %f\n",att);
    printf("Throughput is= %f\n",tp);
}

void main()
{
    int op,ch;
    while(1)
    {
        printf("\nSelect the scheduling algorithm (Non - pre-emptive)");
        printf("\n1.FCFS\n2.SJF\n3.Exit\nEnter your option: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1: fcfs();
                    break;
            case 2: sjf();
                    break;
            case 3: exit(0);
                    break;
            default: printf("\nNot a valid entry!\n");
        }
    }
}
