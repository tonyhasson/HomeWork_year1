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


Node* opos_list(Node* head)
{
	Node* previous = NULL;
	Node* temp;
	Node* next = head;
	while (next != NULL)
	{
		temp = next->n;
		next->n = previous;
		previous = next;
		next = temp;
	}
	return(previous);

}
Node* char_pos(char c, Node* head)
{
	Node* temp = head;
	Node* previous = NULL;
	int tf = 0;//indicates if I entered the char into the list
	while (temp!=NULL&&tf==0)
	{
		if (temp->c >= 'a' && temp->c <= 'z')//if inserted a letter in the past
		{

			if (c < temp->c)//input char is less than char in linked list
			{
				Node* new_node = (Node*)malloc(sizeof(Node));
				new_node->c = c;
				new_node->n = temp;
				if (previous == NULL)//if adding the char in the first node
				{
					head = new_node;
				}
				else//adding the char between nodes
				{
					previous->n = new_node;
				}
				tf = 1;

			}
			else//input char is greater than char in linked list
			{
				if (temp->n == NULL)//if I reached last position
				{
					Node* new_node = (Node*)malloc(sizeof(Node));
					new_node->c = c;
					new_node->n = NULL;
					temp->n = new_node;
					tf = 1;
				}
				else//move temp forward and update keep track of previous node
				{
					previous = temp;
					temp = temp->n;
					
				}
				
			}

		}
		else//first element
		{
			temp->c = c;
			tf = 1;
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
	while (c != '1')
	{
		temp = char_pos(c, temp);
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
void delete_list(Node** head)
{

	Node* next = NULL;
	Node* temp = *head;
	while (temp)
	{
		next = temp->n;
		free(temp);
		temp = next;
	}
	*head = NULL;
}



void main()
{
	Node* head = enter_list();
	print_list(head);
	printf("\n\n");
	head = opos_list(head);
	print_list(head);
	delete_list(&head);
}

