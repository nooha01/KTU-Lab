#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int exp;
    struct node *link;
}*head1,*temp1,*new1,*head2,*temp2,*new2;
void create1()
{
	printf("First polynomial: ");
	char c;
    do
    {
    	new1=(struct node*)malloc(sizeof(struct node));
    	printf("\nEnter the coefficient and exponent(descending order):\n");
    	scanf("%d%d",&new1->coeff,&new1->exp);
   	 	new1->link=NULL;
    	if(head1==NULL)
    	{
        	head1=new1;
        	temp1=new1;

    	}
    	else
    	{
        	temp1->link=new1;
        	temp1=new1;
    	}
    	printf("Add more terms?(Y/N)");
    	scanf("  %c",&c);
	}while(c=='Y'||c=='y');

}
void create2()
{
	printf("\nSecond polynomial");
	char c;
    do
    {
    	new2=(struct node*)malloc(sizeof(struct node));
    	printf("\nEnter the coefficient and exponent(descending order):\n");
    	scanf("%d%d",&new2->coeff,&new2->exp);
   	 	new2->link=NULL;
    	if(head2==NULL)
    	{
        	head2=new2;
        	temp2=new2;

    	}
    	else
    	{
        	temp2->link=new2;
        	temp2=new2;
    	}
    	printf("Add more terms?(Y/N)");
    	scanf(" %c",&c);
	}while(c=='Y'||c=='y');

}

void display1()
{
    
    temp1=head1;
    printf("First polynomial is ");
    while(temp1!=NULL)
    {
        printf("%d(x^%d)",temp1->coeff,temp1->exp);
        temp1=temp1->link;
        if(temp1!=NULL)
        	printf("+");
    }
}

void display2()
{
    temp2=head2;
    printf("\nSecond polynomial is ");
    while(temp2!=NULL)
    {
        printf("%d(x^%d)",temp2->coeff,temp2->exp);
        temp2=temp2->link;
        if(temp2!=NULL)
        	printf("+");
    }
}

void sum()
{
	printf("\nSum of polynomials:\n");
	temp1=head1;
	temp2=head2;
	while(temp1!=NULL&&temp2!=NULL)
	{
		if(temp1->exp==temp2->exp)
		{
			printf("%d(x^%d)",temp1->coeff+temp2->coeff,temp1->exp);
			temp1=temp1->link;
			temp2=temp2->link;
		}
		else if(temp1->exp>temp2->exp)
		{
			printf("%d(x^%d)",temp1->coeff,temp1->exp);
			temp1=temp1->link;
		}
		else 
		{
			printf("%d(x^%d)",temp2->coeff,temp2->exp);
			temp2=temp2->link;
		}
		if(temp1!=NULL||temp2!=NULL)
			printf("+");
	}
	while(temp1!=NULL)
	{
		printf("%d(x^%d)",temp1->coeff,temp1->exp);
		temp1=temp1->link;
		if(temp1!=NULL)
			printf("+");
	}
	while(temp2!=NULL)
	{
		printf("%d(x^%d)",temp2->coeff,temp2->exp);
		temp2=temp2->link;
		if(temp2!=NULL)
			printf("+");
	}
}


int main()
{
    create1();
    create2();
    display1();
    display2();
    sum();   
}
