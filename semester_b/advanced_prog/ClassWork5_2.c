//example done with linked lists
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>


typedef struct {
	char address[30];
	int rooms;
	double price;
} apart;

typedef struct{
	apart a;
	struct Node* n;

}Node;


void enter_apart(apart* q)
{
	printf("enter address: \n");
	scanf_s(" %[^\n]s", &(q->address), sizeof(q->address) - 1);
	printf("enter number of rooms: \n");
	scanf_s("%d", &(q->rooms));
	printf("enter price: \n");
	scanf_s("%lf", &(q->price));
}
void print_apart(apart q)
{
	printf("adress: %s ,rooms: %d , price: %lf\n", q.address, q.rooms, q.price);
}

Node* func(int rooms, double price,Node* head,int size,int* c)
{
	int count = 0,i;
	Node* new_head = (Node*)malloc(sizeof(Node));
	Node* new_temp = new_head;
	Node* og_temp = head;
	for (i = 0; i < size; i++)
	{
	
		if (og_temp->a.rooms == rooms && og_temp->a.price <= price)
		{
			count++;
			new_temp->a = og_temp->a;
			og_temp = og_temp->n;
			if (i + 1 < size)
			{
				new_temp->n = (Node*)malloc(sizeof(Node));
				new_temp = new_temp->n;
			}
			else
			{
				new_temp->n = NULL;
			}

		}
		else
		{
			og_temp = og_temp->n;
		}

	}
	if (count == 0)
	{
		new_head = NULL;
	}
	*c = count;
	return(new_head);
	
}

void main()
{
	int size, i;
	Node* head = (Node*)malloc(sizeof(Node));
	Node* temp = head;
	printf("enter amount of apartments: \n");
	scanf_s("%d", &size);
	for (i = 0; i < size; i++)
	{
		printf("\n\n");
        
		enter_apart(&(temp->a));
		if (i + 1 < size)
		{
			temp->n = (Node*)malloc(sizeof(Node));
			temp = temp->n;
		}
		else
		{
			temp->n = NULL;
		}
		
	}
	
	int rooms,new_size;
	double price;
	printf("\n\n");
	printf("enter amount of rooms desired: \n");
	scanf_s("%d", &rooms);
	printf("\n\n");
	printf("enter price desired: \n");
	scanf_s("%lf", &price);
	printf("\n\n");
	Node* new_head = func(rooms, price, head, size, &new_size);
	for (i = 0; i < new_size; i++)
	{
		if (i == 0)
		{
			print_apart(new_head->a);
			temp = new_head->n;
		}
		else
		{
			print_apart(temp->a);
			temp = temp->n;
		}
	}


}
