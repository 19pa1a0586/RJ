#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
}*first; // Here pointer "*first" is the global variable as it can be accessed any where in the program code

void Create()
{
	int n;
	struct Node *temp, *last;
	
	printf("Enter the size of the list : ");
	scanf("%d",&n);
	
	if(n < 1)
	{
		printf("Memory cannot be allocated");
	}
	else
	{
		first = (struct Node *)malloc(sizeof(struct Node));
		printf("Enter the Node 1 : ");
		scanf("%d",&first->data);
		first->next = NULL;
		last = first;
		
		for(int i = 1; i < n; i++)
		{
		    temp = (struct Node *)malloc(sizeof(struct Node));
		    printf("Enter the Node %d : ",i+1);
		    scanf("%d",&temp->data);
		    temp->next = NULL;
		    last->next = temp;
		    last = temp; //last = last->next; ----> This also gives the same output
		}
	}
}

void Display()
{
	struct Node *p;
	p = first;
	if(p == NULL)
	{
		printf("List is empty");
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

void RecursiveDisplay(struct Node *p)
{
	if(p != NULL)
	{
		printf("%d ",p->data);
		RecursiveDisplay(p->next);
	}
}

void ReverseRecursiveDisplay(struct Node *p)
{
	if(p != NULL)
	{
		ReverseRecursiveDisplay(p->next);
		printf("%d ",p->data);
	}
}

int Count()
{
	struct Node *t;
	int count = 0;
	t = first;
	while(t != NULL)
	{
		count++;
		t = t->next;
	}
	return count;
}

int Sum()
{
	struct Node *temp;
	temp = first;
	int sum = 0;
	if(temp == NULL)
	{
		return 0;
	}
	else
	{
		while(temp != NULL)
		{
			sum += temp->data;
			temp = temp->next;
		}
	}
	return sum;
}

int Max()
{
	struct Node *p;
	int max;
	p = first;
	max = first->data;
	while(p)
	{
		if(p->data > max)
		{
			max = p->data;
		}
		p = p->next;
	}
	return max;
}

int Min()
{
	struct Node *p;
	int min;
	p = first;
	min = first->data;
	while(p)
	{
		if(p->data < min)
		{
			min = p->data;
		}
		p = p->next;
	}
	return min;
}

int Search(int ele)
{
	struct Node *p;
	p = first;
	while(p)
	{
		if(p->data == ele)
		{
			return 1;
		}
		p = p->next;
	}
	return 0;
}

struct Node * Search2(int ele)
{
	struct Node *p;
	p = first;
	while(p)
	{
		if(p->data == ele)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

int main()
{	
	Create();
	printf("\n");
	Display();
	printf("\n");
	printf("There are %d data elements in the Linked List",Count());
	printf("\n");
	if(Sum())
	{
		printf("Sum of all the data elements in the List is %d",Sum());
	}
	else
	{
		printf("List is empty Summation is not possible");
	}
	printf("\n");
	RecursiveDisplay(first);
	printf("\n");
	ReverseRecursiveDisplay(first);
	printf("\n");
	printf("Maximum element in the List is %d",Max());
	printf("\n");
	printf("Minimum element in the List is %d",Min());
	printf("\n");
	if(Search(8))
	{
		printf("%d is found in the List",8);
	}
	else
	{
		printf("%d is not found in the List",8);
	}
	printf("\n");
	if(Search2(8))
	{
		printf("%d is found at address %d in the List",8,Search2(8));
	}
	else
	{
		printf("%d is not found in the List",8);
	}
	return 0;
}


