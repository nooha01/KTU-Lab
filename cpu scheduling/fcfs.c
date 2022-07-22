#include<stdio.h>
#include<stdlib.h>

int main()
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
	printf("| PID | Burst Time | Waiting Time | Turnaround Time |\n");
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
    return 0;
}
