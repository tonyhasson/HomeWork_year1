#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>



typedef struct
{
	int num;
	struct Node* n;
}Node;

int enter_numbers(Node** l1, Node** l2)
{
	int input, count = 0;
	Node* head1;
	Node* head2;
	Node* temp1;
	Node* temp2;
	head1 =(Node*)malloc(sizeof(Node));
	head2 = (Node*)malloc(sizeof(Node));
	temp1 =head1;
	temp2 = head2;
	printf("enter a number\n");
	scanf_s("%d", &input);
	while (input != -1)
	{
		count++;
		if (input % 2 == 0)
		{
			if (temp2->n == NULL)
			{
				temp2->n = (Node*)malloc(sizeof(Node));
				temp2 = temp2->n;
			}
			temp2->num = input;
			temp2->n = NULL;

		}
		else
		{
			if (temp1->n == NULL)
			{
				temp1->n = (Node*)malloc(sizeof(Node));
				temp1 = temp1->n;
			}
			temp1->num = input;
			temp1->n = NULL;
		}



		printf("enter a number\n");
		scanf_s("%d", &input);
	}
	if (temp2->n != NULL)
	{
		temp2 = NULL;
		head2 = NULL;
	}
	if (temp1->n != NULL)
	{
		temp1 = NULL;
		head1 = NULL;
	}
	*l1 = head1;
	*l2 = head2;
	return(count);

}
void print_list(Node* head)
{
	Node* temp = head;
	while (temp)
	{
		printf("number is: %d\n", temp->num);
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
int sum_list(Node* head, int* max, int* min)
{
	Node* temp;
	temp = head;
	int sum = 0;
	if (temp)
	{
		*max = temp->num;
		*min = temp->num;
	}
	else
	{
		*max = -1;
		*min = -1;
	}
	while (temp)
	{
		sum += temp->num;
		if (temp->num > *max)
		{
			*max = temp->num;
		}
		if (temp->num < *min)
		{
			*min = temp->num;
		}
		temp = temp->n;
	}
	return(sum);

}


void main()
{
	
	Node* l1 ;
	Node* l2;
	int count = enter_numbers(&l1, &l2), sum, max, min;
	printf("\n\n");
	printf("amount of numbers entered is : %d\n", count);
	printf("\n\n");
	print_list(l1);
	printf("\n\n");
	print_list(l2);
	printf("\n\n");
	sum = sum_list(l1, &max, &min);
	printf("the summary of l1 is: %d\nmin is: %d\nmax is %d", sum, min, max);
	printf("\n\n");
	sum = sum_list(l2, &max, &min);
	printf("the summary of l2 is: %d\nmin is: %d\nmax is %d", sum, min, max);
	delete_list(&l1);
	delete_list(&l2);
}

