#include <stdio.h>
int main()
{
      int AT[10], BT[10], temp[10],w[10],t[10],i, small, count = 0, n,flag=0,x;
      float avgwt, avgtt,wt = 0, tt = 0,time, end;
      printf("Enter the number of processes\n");
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
            printf("Enter the arrival time and burst time of the process %d: ", i+1);
            scanf("%d%d",&AT[i],&BT[i]);
            temp[i] = BT[i];
      }
      for(i=0;i<n;i++)
      {
      	w[i]=0;
            t[i]=0;
      }
      BT[9] = 9999;
      printf("\nGantt chart:\n");
      for(time=0;count!=n;time++)
      {
            small = 9;
            for(i=0;i<n;i++)
            {
                   
                  if(AT[i]<=time && BT[i]<BT[small] && BT[i]>0)
                  {
                        small=i;
                        if(flag==0)
                        {
                        	printf("%d ",AT[small]);
                        	printf(" p%d ",small+1);
                        	x=small;
                        }
                        flag=1;
                  }
            }
            BT[small]--;
            if(BT[small] == 0)
            {
                  count++;
                  end = time + 1;
                  wt=wt+end-AT[small]-temp[small];
                  w[small]+=end - AT[small] - temp[small];
                  tt = tt+end-AT[small];
                  t[small]+= end - AT[small];
            }
            if(small!=x)
            {
                  
                  printf(" %d ",(int)time);
                  printf(" p%d ",small+1);
                 
                  x=small;
            }
      }
      printf(" %d ",(int)end);
      printf("\n\n+-----+--------------+-----------------+\n");
	printf("| PID | Waiting Time | Turnaround Time |\n");
	printf("+-----+--------------+-----------------+\n");
      for(i=0; i<n; i++) 
	{
		printf("\n| p%d |      %2d     |        %2d         |\n",i+1,w[i],t[i] );
		printf("\n+-----+--------------+-----------------+");
	}
	printf(" ");
      avgwt = wt/n;
      avgtt = tt/n;
      printf("\n\nAvg waiting time of the process is %f\n",avgwt);
      printf("Avg turn around time of the process %f\n",avgtt);
      printf("Throughput:%f\n",n/end);
      return 0;
}