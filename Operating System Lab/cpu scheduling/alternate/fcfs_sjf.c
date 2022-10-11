#include<stdio.h>
#include<stdlib.h>

void gc_fcfs(int n,int pro[10],int bu[10]);
void gc_sjf(int n,int pro[10],int bu[10]);
float avg_wt(int n,int bu[10]);
float avg_tt(int n,int bu[10]);
float thru_put(int n,int bu[10]);

int main()
{
    int n,i,bu[10],pro[10],m,k;
    float wt,tt,tp;
    printf("enter the no of process:");
    scanf("%d",&n);
    printf("enter the processes:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pro[i]);
    }
    printf("enter the burst time:");
    for(i=0;i<n;i++)
    {
        scanf("%d", &bu[i]);
    }
    do
    {
       printf("1:fcfs\n2:sjf\n3:exit");
       scanf("%d",&m);

       switch(m)
       {
        case 1:gc_fcfs(n,pro,bu);
               wt=avg_wt(n,bu);
               printf("\naverage waiting time:%f",wt);
               tt=avg_tt(n,bu);
               printf("\naverage turnaround time:%f",tt);
               tp=thru_put(n,bu);
               printf("\nthroughput:%f",tp);
               break;
        case 2:gc_sjf(n,pro,bu);
               wt=avg_wt(n,bu);
               printf("\naverage waiting time:%f",wt);
               tt=avg_tt(n,bu);
               printf("\naverage turnaround time:%f",tt);
               tp=thru_put(n,bu);
               printf("\nthroughput:%f",tp);
               break;
        default:
               exit(0);
       }
       printf("\nenter 5 to continue:");
       scanf("%d",&k);
    }while(k==5);
    
}

void gc_fcfs(int n,int pro[10],int bu[10])
{
    int burst=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            printf("0 ");
        }
        printf(" p%d ",pro[i] );
        burst=burst+bu[i];
        printf("%d", burst);
    }
}

void gc_sjf(int n,int pro[10],int bu[10])
{
    int burst=0,temp,pt;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(bu[j]>bu[j+1])
            {
                temp=bu[j];
                bu[j]=bu[j+1];
                bu[j+1]=temp;

                pt=pro[j];
                pro[j]=pro[j+1];
                pro[j+1]=pt;
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            printf("0 ");
        }
        printf(" p%d ",pro[i] );
        burst=burst+bu[i];
        printf("%d", burst);
    }

}

float avg_wt(int n,int bu[10])
{
     int wt=0,w=0;
     for(int i=0;i<n-1;i++)
     {
        w=w+bu[i];
        wt=wt+w;     
     }
     float avg=(float)wt/n;
     return avg;
}

float avg_tt(int n,int bu[10])
{
    int wt=0,w=0,tt=0;
    for(int i=0;i<n-1;i++)
     {
        w=w+bu[i];
        wt=wt+w;     
     }
     for(int i=0;i<n;i++)
     {
        tt=tt+bu[i];
     }
     float avg=(float)(wt+tt)/n;
     return avg;
}

float thru_put(int n,int bu[10])
{
    int tp=0;
    for(int i=0;i<n;i++)
     {
        tp=tp+bu[i];
     }
     float t=(float)n/tp;
     return t;
}