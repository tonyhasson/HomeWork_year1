#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>



typedef struct
{
	int x;
	struct Node* n;
	struct Node* p;
}Node;

typedef struct
{
	Node* head;
	Node* tail;
}list;


void print_list(Node* head)
{
	Node* temp = head;
	while (temp)
	{
		printf("number is: %d\n", temp->x);
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

list create_two_size_list()
{
	list l;
	l.head= (Node*)malloc(sizeof(Node));
	Node* temp_next=l.head;
	Node* temp_pre=NULL;
	int num;
	printf("enter a positive number:\n");
	scanf_s("%d", &num);
	while (num>-1)
	{
		
		temp_next->p = temp_pre;
		temp_next->x = num;
		temp_next->n= (Node*)malloc(sizeof(Node));
		temp_pre = temp_next;
		l.tail = temp_next;
		temp_next = temp_next->n;
		

		printf("enter a positive number:\n");
		scanf_s("%d", &num);
	}
	free(temp_next);
	l.tail->n = NULL;
	return(l);
}

//question1
int recursive_len(Node* head)
{
	if (head == NULL)
	{
		return(0);
	}
	else
	{
		return(recursive_len(head->n) + 1);
	}
}

int recursive_pal(Node* head, Node* tail,int size)
{
	if (size == 0 || size == 1)
	{
		return(1);
	}
	else
	{
		if (head->x == tail->x)
		{
			return(recursive_pal(head->n,tail->p,size-2));
		}
		else
		{
			return(0);
		}
	}
}

//question2
void InsertBefore(Node* pre, Node* next,int input)
{	
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->x = input;
	new_node->p = pre;
	new_node->n = next;
	if (pre != NULL)
	{
		pre->n = new_node;
	}
	if (next != NULL)
	{
		next->p = new_node;
	}


}

//question 3
void add_zero_before_k_divider(list *l,int k)
{
	Node* temp = l->head;
	Node* pre=NULL;
	while (temp)
	{
		if ((temp->x) % k == 0 && temp->x!=0)
		{
			pre = temp->p;
			InsertBefore(temp->p, temp, 0);
			if (pre == NULL)
			{
				l->head = temp->p;
			}
		}
		temp = temp->n;
	}
	

}

//question 4
void clean_char_list(list* l)
{
	Node* temp = l->head;
	Node* pre = NULL;
	Node* next = NULL;
	Node* new_tail = NULL;
	char c;
	while (temp)
	{
		c = temp->x;
		Node* run = temp->n;
		while (run)
		{
			if (c == run->x)
			{
				pre = run->p;
				next = run->n;
				pre->n = next;
				next->p = pre;
				free(run);
				run = next;
			}
			else
			{
				run = run->n;
			}
		}
		new_tail = temp;
		temp = temp->n;
	}
	l->tail = new_tail;
}

//question 5
void add_abc_to_list(list* l)
{
	Node* temp = l->head;
	Node* pre;
	Node* next;
	Node* new_tail=NULL;
	int size,i;
	while (temp)
	{
		if (temp->x >= '0' && temp->x <= '9')
		{
			size = temp->x-'0';
			pre = temp;
			next = pre->n;
			for (i = 'a'; i < 'a' + size; i++)
			{
				Node* new_node = (Node*)malloc(sizeof(Node));
				new_node->x = i;
				new_node->p = pre;
				new_node->n = next;

				pre->n = new_node;
				if (next != NULL)
				{
					next->p = new_node;
				}

				pre = pre->n;
				next = pre->n;


			}
		}
		new_tail = temp;
		temp = temp->n;
	}
	l->tail = new_tail;
}

//question 6
void merge(list* l1, list* l2)
{
	Node* run1 = l1->head;
	Node* run2 = l2->head;
	Node* pre;
	Node* next;
	Node* temp_pos;
	Node* new_head=l2->head;
	while (run1 && run2)
	{
		if (run1->x < run2->x)
		{
			pre = run2->p;
			next = run2;
			
			temp_pos = run1;
			run1 = run1->n;

			temp_pos->n = next;
			temp_pos->p = pre;
			if (pre != NULL)
			{
				
				pre->n = temp_pos;
			}
			else
			{
				new_head = temp_pos;
			}
			if (next != NULL)
			{
				next->p = temp_pos;
			}
			run2 = temp_pos;
			
			
		}
		else
		{
			run2 = run2->n;
		}
	}
	while (run1)
	{
		pre = l2->tail;
		next = NULL;

		temp_pos = run1;
		run1 = run1->n;

		temp_pos->n = next;
		temp_pos->p = pre;

		pre->n = temp_pos;
		l2->tail = temp_pos;
	}
	l2->head = new_head;
	
}
void main()
{
	list l1 = create_two_size_list();
	print_list(l1.head);
	printf("\n\n");
	list l2 = create_two_size_list();
	print_list(l2.head);
	printf("\n\n");
	merge(&l1, &l2);
	print_list(l2.head);
	delete_list(l2.head);
}
