typedef struct
{
	int num;
	struct Node* n;
}Node;

int enter_numbers(Node* l1, Node* l2)
{
	int input,count=0;
	Node* previous1;
	Node* previous2;
	Node* temp1;
	Node* temp2;
	temp1 = NULL;
	temp2 = NULL;
	previous1 = NULL;
	previous2 = NULL;
	printf("enter a number\n");
	scanf_s("%d", &input);
	while (input!=-1)
	{
		count++;
		if (input % 2 == 0)
		{
			if (temp2 == NULL)
			{
				l2->num = input;
				temp2= (Node*)malloc(sizeof(Node));
				l2->n = temp2;
				previous2 = l2;

			}
			else
			{
				temp2->num = input;
				temp2->n = (Node*)malloc(sizeof(Node));
				previous2 = temp2;
				temp2 = temp2->n;
			}
		}
		else
		{
			if (temp1 == NULL)
			{
				l1->num = input;
				temp1 = (Node*)malloc(sizeof(Node));
				l1->n = temp1;
				previous1 = l1;
			}
			else
			{
				temp1->num = input;
				temp1->n = (Node*)malloc(sizeof(Node));
				previous1 = temp1;
				temp1 = temp1->n;
			}
		}



		printf("enter a number\n");
		scanf_s("%d", &input);
	}
	if (temp1 == NULL)
	{
		l1= NULL;
	}
	else
	{
		previous1->n = NULL;
	}
	if (temp2 == NULL)
	{
		l2 = NULL;
	}
	else
	{
		previous2->n = NULL;
	}
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
int sum_list(Node* head,int* max,int* min)
{
	Node* temp;
	temp = head;
	int sum=0;
	*max = temp->num;
	*min = temp->num;
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
	Node* l1 = (Node*)malloc(sizeof(Node));
	Node* l2 = (Node*)malloc(sizeof(Node));
	int count = enter_numbers(l1, l2),sum,max,min;
	printf("\n\n");
	printf("amount of numbers entered is : %d\n", count);
	printf("\n\n");
	print_list(l1);
	printf("\n\n");
	print_list(l2);
	printf("\n\n");
	sum = sum_list(l1,&max,&min);
	printf("the summary of l1 is: %d\nmin is: %d\nmax is %d", sum, min, max);
	printf("\n\n");
	sum = sum_list(l2, &max, &min);
	printf("the summary of l2 is: %d\nmin is: %d\nmax is %d", sum, min, max);
	delete_list(l1);
	delete_list(l2);
}
