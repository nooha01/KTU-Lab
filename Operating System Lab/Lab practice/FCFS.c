#include<stdio.h>

int main()
{
         int n, wt[10],tat[10],bt[10],w[10],i;
         float awt=0,att=0,tp=0;
         printf("Enter the number of processes: ");
         scanf("%d", &n);
         printf("Enter the burst time of each process:\n");
         for(i=0;i<n;i++)
         {
                  printf("Enter the burst time of process %d ",i);
                  scanf("%d",&bt[i]);
         }
         wt[0]=w[0]=0;
         for(i=0;i<n;i++)
         {
                  wt[i+1]=wt[i]+bt[i];
                  tp=tp+bt[i];
                 
         }
         for(i=0;i<n;i++)
         {
                w[i]=wt[i];
                tat[i]=bt[i]+wt[i];
                awt=awt+w[i];
                att=att+tat[i];
                
         }
         tp=n/tp;
         awt=awt/n;
         att=att/n;
         printf("%f\n",awt);
          printf("%f\n",att);
           printf("%f\n",tp);
         
          
          
}
