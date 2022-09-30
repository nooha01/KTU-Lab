#include <stdio.h>
int main() 
{
      int arr[10], burst[10], temp[10],i, smallest, count = 0, n,flag=0,x;
      float avgwt, avgtt,wt = 0, tt = 0,time, end;
      printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &n); 
      printf("\nEnter Details of %d Processes", n);
      for(i = 0; i < n; i++)
      {
      
            printf("\nEnter Arrival Time:\t");
            scanf("%d", &arr[i]);
            printf("Enter Burst Time:\t");
            scanf("%d", &burst[i]); 
            temp[i] = burst[i];
      }
      burst[9] = 9999;  
      printf("\nGantt chart:\n");
      for(time = 0; count != n; time++)
      {
            smallest = 9;
            for(i = 0; i < n; i++)
            {
                  if(arr[i] <= time && burst[i] < burst[smallest] && burst[i] > 0)
                  {
                        smallest = i;
                        if(flag==0){
						
                        	printf("%d ",arr[smallest]);
                        	printf(" p%d ",smallest+1);
                        	x=smallest;}
                        flag=1;
                  }
            }
            
            burst[smallest]--;
            
            if(burst[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  wt = wt + end - arr[smallest] - temp[smallest];
                  tt = tt + end - arr[smallest];
            }
            if(smallest!=x)
            {
            	printf(" %d ",(int)time);
            	printf(" p%d ",smallest+1);
            	x=smallest;
			}
      }
      printf(" %d ",(int)end);
      avgwt = wt / n; 
      avgtt = tt / n;
      printf("\n\nAverage Waiting Time:%f\n", avgwt);
      printf("Average Turnaround Time:%f\n", avgtt);
      printf("Throughput:%f\n",n/end);
      return 0;
}