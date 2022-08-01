#include<stdio.h>
#include<stdlib.h>
int f,p,str[30];
int fr[4], count=0;

void prarr(char ch)
{
    for(int i=0;i<f;i++)
    {
        printf("%d\t",fr[i]);
    }
    printf("%c\n", ch);
    if(ch=='M')
        count++;
}

void fifo()
{
    int i,j;
    int ptr=0;
    for(i=0;i<p;i++)
    {
        int flag=0;
        int item=str[i];
        for(j=0;j<f;j++)
        {
            if(fr[j]==item)
            {
                prarr('H');
                flag = 1;
            }
        }
        if(flag==0)
        {
                fr[ptr]=item;
                ptr=(ptr+1)%f;
                prarr('M');
        }
    }
    printf("Number of page faults is %d", count);
    
}

void opt()
{
    int i,j,farthest,l,k;
    int ptr=-1;
    for(i=0;i<p;i++)
    {
        int flag=0;
        int item=str[i];
        for(j=0;j<f;j++)
        {
            if(fr[j]==item)
            {
                prarr('H');
                flag = 1;
            }
        }
        if(flag==0)
        {
            farthest=i+1;
            for(k=0;k<f;k++)
            {
                for(l=i+1;l<p;l++)
                {
                    if(fr[k]==str[l])
                    {
                        if(farthest<l)
                        {
                            farthest=l;
                            ptr=k;
                        }
                        break;
                    }
                }
                if(l==p)
                {
                    ptr=k;
                    break;
                }
            }  
            if(ptr==-1)
                ptr=0;
            fr[ptr]=str[i];
            prarr('M');
        }
    }
    printf("Number of page faults is %d", count);
}

void lru()
{
    int i,j,recent,l,k;
    int ptr=-1;
    for(i=0;i<p;i++)
    {
        int flag=0;
        int item=str[i];
        for(j=0;j<f;j++)
        {
            if(fr[j]==item)
            {0
                prarr('H');
                flag = 1;
            }
        }
        if(flag==0)
        {
            recent=i-1;
            for(k=0;k<f;k++)
            {
                for(l=i-1;l>=0;l--)
                {
                    if(fr[k]==str[l])
                    {
                        if(recent>l)
                        {
                            recent=l;
                            ptr=k;
                        }
                        break;
                    }
                }
                if(l==-1)
                {
                    ptr=k;
                    break;
                }
            }  
            if(ptr==-1)
                ptr=0;
            fr[ptr]=str[i];
            prarr('M');
        }
    }
    printf("Number of page faults is %d", count);
}

int main()
{
    int i;
    printf("Enter number of frames\n");
    scanf("%d",&f);
    printf("Enter number of pages\n");
    scanf("%d",&p);
    printf("Enter page reference string\n");
    for(i=0;i<p;i++)
    {
        scanf("%d",&str[i]);
    }
    
    while(1)
    {
        int choice;
        count=0;
        printf("\nEnter\n1.FIFO \n2.Optimal\n3.LRU\n");
        scanf("%d",&choice);
        for(int i=0;i<f;i++)
        {
            fr[i]=-1;
        }
        switch(choice)
        {
            case 1:
            fifo();
            break;
            case 2:
            opt();
            break;
            case 3:
            lru();
            break;
        }
    }
}

