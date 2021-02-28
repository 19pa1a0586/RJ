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
	return count;
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

void InsertPos(struct Node *p, int ind, int val)
{
	if(ind < 0 || ind > Count())
	{
		printf("Length is out of range; pls enter the positions from 0 to %d.\n",Count());
	}
	else
	{
		struct Node *q;
		q = (struct Node *)malloc(sizeof(struct Node));
		q->data = val;
		if(ind == 0)
		{
			q->prev = NULL;
			q->next = first;
			first->prev = q;
			first = q;
		}
		else
		{
			for(int i = 0; i < ind-1; i++)
			{
				p = p->next;
			}
			q->next = p->next;
		        q->prev = p;
			p->next = q;
		}
	}
}

void InsertEnd()
{
	struct Node *p, *q;
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
			q = first;
			while(q->next != NULL)
			{
				q = q->next;
			}
			p->next = NULL;
			p->prev = q;
			q->next = p;
		}
	}
}

void BigDelete()
{
	struct Node *p;
	p = first;
	if(p == NULL)
	{
		printf("Empty List");
	}
	else
	{
		first = first->next;
		first->prev = NULL;
		free(p);
	}
}

void PosDelete(struct Node *p, int ind) // single pointer uses
{
	if(ind < 1 || ind > Count())
	{
		printf("Length is out of range; pls enter the positions from 1 to %d.\n",Count());
	}
	else
	{
		if(ind == 1)
		{
			first = first->next;
			if(first)
			{
				first->prev = NULL;
			}
			free(p);
		}
		else
		{
			for(int i = 0; i < ind-1; i++)
			{
				p = p->next;
			}
			p->prev->next = p->next;
			if(p->next) // checks if there is another node next to p
			{
				p->next->prev = p->prev;
			}
			free(p);
		}
	}
}

void EndDelete()
{
	struct Node *p, *q;
	p = first;
	if(p == NULL)
	{
		printf("Empty List");
	}
	else
	{
		while(p->next != NULL)
		{
			q = p;
			p = p->next;
		}
		q->next = NULL;
		free(p);
	}
}

int main()
{
	int ind, val, pos;
	Create();
	Display();
	printf("Length of the list is : %d\n",Count());
	InsertBig();
	Display();
	printf("Length of the list after Insertion at beginning is : %d\n",Count());
	InsertEnd();
	Display();
	printf("Length of the list after Insertion at end is : %d\n",Count());
        printf("\nEnter the element you want Insert : ");
	scanf("%d",&val);
	printf("Enter the Position where you want to Insert : "); // It links the newnode to the entered numbers next position. for ex-->> enter 4 then the element(newnode) is inserted at 5 as it links next to 4.
	scanf("%d",&ind);
	InsertPos(first,ind,val);
	Display();
	printf("Length of the list after Insertion is : %d\n",Count());
	BigDelete();
	Display();
	printf("Length of the list after removal of first node is : %d\n",Count());
	EndDelete();
	Display();
	printf("Length of the list after removal of last node is : %d\n",Count());
	printf("Array elements after deleting the element at a position.");
	printf("Enter the Position where you want to remove : "); // It links the newnode to the entered numbers next position. for ex-->> enter 4 then the element(newnode) is inserted at 5 as it links next to 4.
	scanf("%d",&pos);
	PosDelete(first,pos);
	Display(); 
	return 0;
}

//Routput:

//Enter the size of the list : 0
//Pls enter valid number starts from 1
//Empty list
//Length of the list is : 0
//Enter the element you want to Insert at beginning : 4
//Elements are : 4
//Length of the list after Insertion at beginning is : 1
//Enter the element you want to Insert at beginning : 5
//Elements are : 4 5
//Length of the list after Insertion at end is : 2
//
//Enter the element you want Insert : 9
//Enter the Position where you want to Insert : 1
//Elements are : 4 9 5
//Length of the list after Insertion is : 3
//Elements are : 9 5
//Length of the list after removal of first node is : 2
//Elements are : 9
//Length of the list after removal of last node is : 1
//Array elements after deleting the element at a position.Enter the Position where you want to remove : 1
//Empty list
