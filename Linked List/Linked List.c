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
	if(count > 0)
	{
		return count;		
	}
	else
	{
		return -1;
	}
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

void InsertBig()
{
	struct Node *p;
	p = (struct Node *)malloc(sizeof(struct Node));
	if(p == 0)
	{
		printf("Over Flow");
	}
	else
	{
		printf("\nEnter the element you want Insert at beginning: ");
		scanf("%d",&p->data);
		p->next = first;
		first = p;	
	}
}

void InsertPos1()
{
	struct Node *p, *q;
	int n;
	p = (struct Node *)malloc(sizeof(struct Node));
	if(p == 0)
	{
		printf("Over Flow");
	}
	else
	{
		printf("\nEnter the element you want Insert : ");
		scanf("%d",&p->data);
		printf("Enter the Position where you want to Insert : "); // It links the newnode to the entered numbers next position. for ex-->> enter 4 then the element(newnode) is inserted at 5 as it links next to 4.
		scanf("%d",&n);
		if(n==0)
		{
		    p->next = first;
		    first = p;
		}
		else if(n > 0)
		{
			int count = 1;
			q = first;
			for(int i = 0; i < n-1 && q; i++)
			{
				count++;
				q = q->next;
			}
			if(n <= count)
			{
				p->next = q->next;
		    	q->next = p;
			}
			else
			{
				printf("Length is out of range; pls enter the positions from 0 to %d.\n",count-1);
			}	
		}		
	}
}

void InsertPos2(struct Node *p, int ind, int val)
{
	if(ind < 0 || ind > Count())
	{
		printf("Length is out of range; pls enter the positions from 0 to %d.\n",Count());
	}
	else
	{
		struct Node *temp;
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = val;
		if(ind == 0)
		{
			temp->next = first;
			first = temp;
		}
		else
		{
			for(int i = 0; i < ind-1; i++)
			{
				p = p->next;
			}
			temp->next = p->next;
			p->next = temp;
		}
	}
}

void InsertEnd()
{
	struct Node *p, *q;
	p = (struct Node *)malloc(sizeof(struct Node));
	if(p == 0)
	{
		printf("Over Flow");
	}
	else
	{
		printf("\nEnter the element you want Insert at end: ");
		scanf("%d",&p->data);
		p->next = NULL;
		q = first;
		while(q->next !=NULL)
		{
			q = q->next;
		}
		q->next = p;
		q = p;		
	}
}

void BigDelete()
{
	struct Node *p;
	p = first;
	if(p == NULL)
	{
		printf("Under Flow");
	}
	else
	{
		first = first->next;
		p->next = NULL;
		free(p);
	}
}

//void PosDelete1()
//{
//	struct Node *p, *q;
//	int n;
//	p = first;
//	q = first;
//	if(p == NULL)
//	{
//		printf("Under Flow");
//	}
//	else
//	{
//		printf("Enter the Position where you want to delete : ");
//	    scanf("%d",&n);
//	    if(n==0)
//	    {
//	    	first = first->next;
//		    p->next = NULL;
//		    free(p);
//		}
//		else if(n > 0)
//		{
//			int count = 1;
//			for(int i = 0; i < n-1; i++)
//			{
//				count++;
//				q = p;
//				p = p->next;
//			}
//			if(n <= count)
//			{
//				q->next = p->next;
//			    free(p);
//			}
//			else
//			{
//				printf("Length is out of range; pls enter the positions from 0 to %d.\n",count-1);
//			}
//		}
//	}
//}

void EndDelete()
{
	struct Node *p, *q;
	p = first;
	q = first;
	if(p == NULL)
	{
		printf("Under Flow");
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

void PosDelete2(struct Node *p, int ind)
{
	if(ind < 1 || ind > Count())
	{
		printf("Length is out of range; pls enter the positions from 1 to %d.\n",Count());
	}
	else
	{
		struct Node *q;
		q = first;
		if(ind == 1)
		{
			first = first->next;
			free(p);
		}
		else
		{
			for(int i = 0; i < ind-1; i++)
			{
				q = p;
				p = p->next;
			}
			q->next = p->next;
			free(p);
		}
	}
}

int main()
{
	int ind,val,pos;
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
	InsertBig();
	Display();
	InsertEnd();
	Display();
	printf("\nEnter the element you want Insert : ");
	scanf("%d",&val);
	printf("Enter the Position where you want to Insert : "); // It links the newnode to the entered numbers next position. for ex-->> enter 4 then the element(newnode) is inserted at 5 as it links next to 4.
	scanf("%d",&ind);
	InsertPos2(first,ind,val);
	Display();
	printf("Array elements after deleting the first element.");
	BigDelete();
	Display();
	printf("Array elements after deleting the end element.");
	EndDelete();
	Display();
	printf("Array elements after deleting the element at a position.");
	printf("Enter the Position where you want to remove : "); // It links the newnode to the entered numbers next position. for ex-->> enter 4 then the element(newnode) is inserted at 5 as it links next to 4.
	scanf("%d",&pos);
	PosDelete2(first,pos);
	Display(); 
	return 0;
}

//Routput 1 :

//Enter the size of the list : 4
//Enter the Node 1 : 9
//Enter the Node 2 : 2
//Enter the Node 3 : 4
//Enter the Node 4 : 8
//
//Elements are : 9 2 4 8
//
//There are 4 data elements in the Linked List
//Sum of all the data elements in the List is 23
//9 2 4 8
//8 4 2 9
//Maximum element in the List is 9
//Minimum element in the List is 2
//8 is found in the List
//8 is found at address 12807920 in the List
//Enter the element you want Insert at beginning: 5
//Elements are : 5 9 2 4 8
//
//Enter the element you want Insert at end: 8
//Elements are : 5 9 2 4 8 8
//
//Enter the element you want Insert : 4
//Enter the Position where you want to Insert : 2
//Elements are : 5 9 4 2 4 8 8
//Array elements after deleting the first element.Elements are : 9 4 2 4 8 8
//Array elements after deleting the end element.Elements are : 9 4 2 4 8
//Array elements after deleting the element at a position.Enter the Position where you want to delete : 2
//Elements are : 9 2 4 8


//Routput 2 :

//Enter the size of the list : 2
//Enter the Node 1 : 9
//Enter the Node 2 : 8
//
//Elements are : 9 8
//
//There are 2 data elements in the Linked List
//Sum of all the data elements in the List is 17
//9 8
//8 9
//Maximum element in the List is 9
//Minimum element in the List is 8
//8 is found in the List
//8 is found at address 1994608 in the List
//Enter the element you want Insert at beginning: 4
//Elements are : 4 9 8
//
//Enter the element you want Insert at end: 5
//Elements are : 4 9 8 5
//
//Enter the element you want Insert : 2
//Enter the Position where you want to Insert : 0
//Elements are : 2 4 9 8 5
//Array elements after deleting the first element.Elements are : 4 9 8 5
//Array elements after deleting the end element.Elements are : 4 9 8
//Array elements after deleting the element at a position.Enter the Position where you want to remove : 1
//Elements are : 9 8

