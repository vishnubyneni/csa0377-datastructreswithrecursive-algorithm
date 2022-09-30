#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node*next;
}
*head=NULL,*p,*t,*newnode;
void create()
{
	int x,n,i;
	printf("enter the n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the value");
		scanf("%d",&x);
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=x;
		newnode->next=NULL;
		if (head==NULL)
		{
			head=newnode;
			p=newnode;
		}
		else
		{
			for(p=head;p->next!=NULL;p=p->next);
			p->next=newnode;
			p=newnode;
		}
	}
}
void insert_at_begin()
{
	int x;
	
		printf("enter the value");
		scanf("%d",&x);
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=x;
		newnode->next=NULL;
		p=head;
		head=newnode;
		newnode->next=p;
		p=newnode;
}
void insert_at_end()
{
	int x;
	
		printf("enter the value");
		scanf("%d",&x);
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=x;
		newnode->next=NULL;
		for(p=head;p->next!=NULL;p=p->next);
		p->next=newnode;
		p=newnode;
}
void insert_at_anyposition()
{
	int x,i,pos;
	
		printf("enter the value and pos");
		scanf("%d%d",&x,&pos);
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=x;
		newnode->next=NULL;
		for(p=head,i=1;i<pos;p=p->next,i++)
		t=p;
		t->next=newnode;
		newnode->next=p;
		p=newnode;
		
}
void delete_at_begin()
{
	int x;
	p=head;
	head=p->next;
	x=p->data;
	free(p);
	p=head;
	printf("the deleted element is %d",x);
}
void delete_at_end()
{
	int x;
	for(p=head;p->next!=NULL;p=p->next)
	t=p;
	t->next=NULL;
	x=p->data;
	free(p);
	printf("the deleted element is %d",x);
}
void delete_at_anyposition()
{
	int x,pos,i;
	printf("enter the n");
	scanf("%d",&pos);
	for(i=1,p=head;i<pos;i++,p=p->next)
	t=p;
	t->next=p->next;
	x=p->data;
	free(p);
	printf("the deleted element is %d",x);
	
}

void display()
{
	if (head==NULL)
	printf("empty");
	else
	for(p=head;p!=NULL;p=p->next)
	printf("%d->",p->data);
}
int main()
{
	int choice;
	do
	{
		printf("\nMain menu \n");
		printf("\n1.create\n2.display\n3.insert_at_begin\n4.insert_at_end\n5.insert_at_anyposition\n6.delete_at_begin\n7.delete_at_end\n8.delete_at_anyposition\n9.exit\n");
		printf("enter your choice");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				insert_at_begin();
				break;
			case 4:
				insert_at_end();
				break;
			case 5:
				insert_at_anyposition();
				break;
			case 6:
				delete_at_begin();
				break;
			case 7:
				delete_at_end();
				break;
			case 8:
				delete_at_anyposition();
				break;
			case 9:
				exit(0);

			default:
				printf("enter numbers from 1 to 9");
		}
	}while(choice>0 && choice<=9);
	return 0;		
}

