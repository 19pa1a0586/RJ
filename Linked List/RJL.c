#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
}*first;

void Create()
{
	int n;
	struct Node *temp, *last;
	first = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter the size of the list : ");
	scanf("%d",&n);
	
	if(n > 0)
	{
		printf("Enter the Node 1 : ");
		scanf("%d",&first->data);
		first->prev = NULL;
		first->next = NULL;
		last = first;
	
		for(int i = 1; i < n; i++)
		{
			temp = (struct Node *)malloc(sizeof(struct Node));
			printf("Enter the Node %d : ",i+1);
			scanf("%d",&temp->data);
			temp->next = last->next;
			temp->prev = last;
			last->next = temp;
			last = temp;		
		}	
	}
	else
	{
		first = NULL;
		printf("Pls enter valid number starts from 1\n");
	}
}

void Display()
{
	struct Node *p;
	p = first;
	if(p == NULL)
	{
		printf("Empty list\n");
	}
	else
	{
		printf("Elements are : ");
		while(p != NULL)
		{
			printf("%d ",p->data);
			p = p->next;
		}
		printf("\n");
	}
}

int Count()
{
	int count = 0;
	struct Node *p;
	p = first;
	while(p)
	{
		count++;
		p = p->next;
	}
	if(count > 0)
	{
		return count;		
	}
	else
	{
		return -1;
	}
}

void InsertBig()
{
	struct Node *p;
	p = (struct Node *)malloc(sizeof(struct Node));
	if(p == NULL)
	{
		printf("Over Flow");
	}
	else
	{
		printf("Enter the element you want to Insert at beginning : ");
		scanf("%d",&p->data);
		if(first == NULL)
		{
			p->prev = NULL;
			p->next = NULL;
			first = p;
		}
		else
		{
			p->prev = NULL;
		        p->next = first;
		        first->prev = p;
		        first = p;
		}
	}
}

int main()
{
	Create();
	Display();
	printf("Length of the list is : %d\n",Count());
	InsertBig();
	Display();
	printf("Length of the list after Insertion is : %d\n",Count());
	return 0;
}
