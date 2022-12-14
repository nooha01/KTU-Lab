#include<stdio.h>
#include<stdlib.h>

int mem,pr;

int FF(int m[], int p[])
{
    for(int i=0;i<pr;i++)
    {
        int flag=0;
        for(int j=0;j<mem;j++)
        {
            if(p[i]<=m[j])
            {
                printf("\nProcess %d (%d kb) is allocated to block %d (%d kb)", i + 1, p[i], j+1, m[j]);
                m[j]-=p[i];
                printf("with Internal Fragmentation - %d\n",m[j]);
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("\nprocess%d is waiting to be allocated!", i+1);
        }   
    }
}

int BF(int m[], int p[])
{
    for(int i=0;i<pr;i++)    
    {
        int best=-1,flag=0;
        for(int j=0;j<mem;j++)
        {
            if(p[i]<=m[j])
            {
                if(best==-1)
                {
                    best=j;
                    flag=1;
                }  
                else if(m[best]>m[j])
                {
                    best=j;
                    flag=1;
                } 
            }
        }
        if(flag==1)
        {
            printf("\nProcess %d (%d kb) is allocated to block %d (%d kb)", i + 1, p[i], best+1, m[best]);
            m[best]-=p[i];
            printf("internal Fragmentation is %d", m[best]);
        }
        else
            printf("\nprocess%d is waiting to be allocated!", i+1);
    }
}

int WF(int m[], int p[])
{
    for(int i=0;i<pr;i++)
    {
        int worst=-1,flag=0;
        for (int j=0; j<mem; j++)
        {
            if (m[j] >= p[i])
            {
                if (worst == -1)
                {
                    worst = j;
                    flag=1;
                }  
                else if (m[worst] < m[j])
                {
                    worst = j;
                    flag=1;
                }     
            }
        }
        if(flag==1)
        {
            printf("\nProcess %d (%d kb) is allocated to block %d (%d kb)", i + 1, p[i], worst+1, m[worst]);
            m[worst]-=p[i];
            printf("internal Fragmentation is %d", m[worst]);
            flag=1;
        }
        else
            printf("\nprocess%d is waiting to be allocated!", i+1);
    }
}

int main()
{
    int m[10], m2[10],m3[10],p[10], ch;
    printf("\nEnter the number of memory blocks available: ");
    scanf("%d", &mem);
    printf("Enter the number of processes: ");
    scanf("%d", &pr);
    for(int i=0;i<mem;i++)
    {
        printf("Enter the size of %d memory block: ",i+1);
        scanf("%d", &m[i]);
        m2[i]=m3[i]=m[i];

    }
    for(int i=0;i<pr;i++)
    {
        printf("Enter size required for process%d: ", i+1);
        scanf("%d", &p[i]);   
    }
    while(1)
    {
        printf("\n\nChoose a Memory management algorithm:\n");
        printf("1.First Fit\n2.Best Fit\n3.Worst Fit\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: FF(m,p);
                break;
            case 2: BF(m2,p);
                break;
            case 3: WF(m3,p);
                break;
            case 4: exit(0);
            default: printf("Enter a valid choice!");
        }
    }
}