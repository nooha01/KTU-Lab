#include<stdio.h>
int main()
{
         int n, bt[10], wt[10], tat[10],i,p[10],j,at[10],pos,temp;
         float awt=0,att=0,tp=0;
         printf("ENter the no of processes: ");
         scanf("%d", &n);
         printf("Enter the burst time of each process: ");
         for(i=0;i<n;i++)
         {
                  printf("Enter the burst time and arrival time of process %d ",i);
                  p[i]=i+1;
                  scanf("%d%d",&bt[i],&at[i]);
         }
         for(i=0;i<n;i++)
         {
                  pos=i;
                  for(j=0;j<n;j++)
                  {
                           if(bt[j]<bt[pos])
                           if(at[j]<at[pos])
                                    pos=j;
                  }
                  temp=bt[i];
                  bt[i]=bt[pos];
                  bt[pos]=temp;
                  
                  temp=p[i];
                  p[i]=p[pos];
                  p[pos]=temp;
              
         }
         wt[0]=0+at[i];
         for(i=1;i<n;i++)
         {
                  wt[i]=wt[i-1]+bt[i-1]+at[i-1]-at[i];
                  tat[i]=wt[i]+bt[i];
                  tp=tp+bt[i];
                  awt = awt + wt[i];
                  att = att + tat[i];
         }
         tp=n/tp;
         awt=awt/n;
         att=att/n;
         printf("%f\n",awt);
          printf("%f\n",att);
           printf("%f\n",tp);
}
