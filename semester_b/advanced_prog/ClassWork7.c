#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>



typedef struct
{
	char c;
	struct Node* n;
}Node;


int Is_empty(Node* head)
{
	if (head->n == NULL)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
Node* opos_list(Node* head)
{
	Node* previous=NULL;
	Node* temp;
	Node* next=head;
	while (next != NULL)
	{
		temp = next->n;
		next->n = previous;
		previous = next;
		next = temp;
	}
	return(previous);

}
Node* char_pos(char c,Node* head)
{
	Node* temp = head;
	Node* next;
	Node* previous;
	next = NULL;
	previous = NULL;
	int tf = 0;
	if(Is_empty(temp)==1)
	{
		if (temp->c >= 'a' && temp->c <= 'z')
		{
			
			if (c < temp->c)
			{
				Node* new_node = (Node*)malloc(sizeof(Node));
				new_node->c = c;
				new_node->n = temp;
				head = new_node;
				
				
			}
			else
			{
				Node* new_node = (Node*)malloc(sizeof(Node));
				new_node->c = c;
				new_node->n = NULL;
				temp->n = new_node;
			}
			
		}
		else
		{
			temp->c = c;
		}
		
	}
	else 
	{
		while (temp != NULL&&tf==0)
		{
			if (c < temp->c)
			{
				if (previous == NULL)//if you are in first element
				{
					Node* new_node = (Node*)malloc(sizeof(Node));
					new_node->c = c;
					new_node->n = head;
					head = new_node;
					tf = 1;
				}
				else
				{
					Node* new_node = (Node*)malloc(sizeof(Node));
					new_node->c = c;
					new_node->n = temp;
					previous->n = new_node;
					tf = 1;
				}
			}
			else
			{
				previous = temp;
				temp = temp->n;
			}
		}
		if (tf == 0)
		{
			Node* new_node = (Node*)malloc(sizeof(Node));
			new_node->c = c;
			new_node->n = NULL;
			if (temp == NULL)
			{
				previous->n = new_node;
			}
			else
			{
				temp->n = new_node;
			}
		}
	}
	return(head);
	
}
Node* enter_list()
{
	Node* head = (Node*)malloc(sizeof(Node));
	Node* temp = head;
	temp->n = NULL;
	char c;
	printf("enter a char or 1 to stop :\n");
	scanf_s(" %c", &c);
	while (c!='1')
	{
		temp=char_pos(c, temp);
		printf("enter a char or 1 to stop :\n");
		scanf_s(" %c", &c);
	}
	head = temp;
	return(head);
}
void print_list(Node* head)
{
	Node* temp = head;
	while (temp)
	{
		printf("char is: %c\n", temp->c);
		temp = temp->n;
	}
}
void delete_list(Node* head)
{
	Node* previous = NULL;
	Node* temp = head->n;
	while (temp)
	{
		previous = temp;
		temp = temp->n;
		free(previous);
	}
	free(head);
}



void main()
{
	Node* head=enter_list();
	print_list(head);
	printf("\n\n");
	head = opos_list(head);
	print_list(head);
	delete_list(head);
}
