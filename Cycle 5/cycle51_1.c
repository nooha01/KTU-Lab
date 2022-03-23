#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* link;
};
struct node* head=NULL;

void display()
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}

void insert_end(int data)
{
	struct node* temp=head;
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	
	newnode->data=data;
	
	newnode->link=NULL;
	
	if(temp!=NULL)
	{
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=newnode;

	}else
	{	
		head=newnode;
	}
}

void insert_beg(int data)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->link=head;
	head=newnode;
}

void insert_pos(int data,int pos)
{
	struct node* temp=head;
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;

	if(pos>1)
	{
		while(--pos>1 && temp!=NULL)
		{
			temp=temp->link;
		}

		newnode->link=temp->link;
		temp->link=newnode;
	}else
	{
		insert_beg(data);	
	}
}

void delete_beg()
{
	if(head!=NULL)
	{
		head=head->link;
		
	}else
	{
		printf("Linkd List is empty\n");
	}
}

void delete_end()
{
	struct node* temp=head;
	if(temp==NULL)
	{
		printf("The Linked List is empty\n");
	}else
	{
		if(head->link!=NULL)
		{
			while(temp->link->link!=NULL)
			{
				temp=temp->link;
			}
			temp->link=NULL;
		}else
		{
			head=NULL;
		}
	}
}

void delete_pos(int pos)
{
	struct node* temp=head;

	if(pos>1)
	{	
		
		while(--pos>1 && temp!=NULL)
		{
			temp=temp->link;
		}
		
		temp->link=temp->link->link;

		
	}else
	{
		delete_beg();
	}
}

int main()
{
	while(1)
	{				
		int choice;
		printf("1.Display\n2.Insert at End\n3.Insert at Beginning\n4.Delete from beginning\n5.Delete from end\n6.Insert into position\n7.Delete from position\n8.Exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				display();
				break;
			}
			case 2:
			{
				int temp;
				printf("Enter the data");
				scanf("%d",&temp);
				insert_end(temp);
				
				display();

				break;
			}
			case 3:
			{
				int temp;
				printf("Enter the data");
				scanf("%d",&temp);
				insert_beg(temp);
				display();
				break;
			}
			case 6:
			{
				int temp,pos;
				printf("Enter the data and position");
				scanf("%d %d",&temp,&pos);
				insert_pos(temp,pos);
				display();
				break;
			}
			case 4:
			{
				delete_beg();
				display();
				break;
			}
			case 5:
			{
				delete_end();
				display();
				break;
			}
			case 7:
			{
				int pos;
				printf("Enter the position");
				scanf("%d",&pos);
				delete_pos(pos);
				display();
				break;
			}

			case 8:
			{
				return 0;
			}
		}	
	}
	return 0;
}
