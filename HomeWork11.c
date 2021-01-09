#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>



/*
//question 1:



void print_array(int* a, int n);
void sort_array(int* a, int k);
void input_array(int* a, int n);
void main()
{
	int n;
	printf("enter n: ");
	scanf_s("%d", &n);
	int* a = (int*)calloc(n, sizeof(int));
	input_array(a, n);
	sort_array(a, n/2);
	print_array(a, n);
	free(a);
}
void input_array(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\nenter number to array: ");
		scanf_s("%d", &a[i]);
	}
}
void sort_array(int* a, int k)
{
	int i,temp;
	for (i = 0; i <= k * 2; i+=2)
	{
		if(a[i+1]<a[i])
		{
			temp = a[i + 1];
			a[i + 1] = a[i];
			a[i] = temp;
		}
	}
}
void print_array(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\na[%d]= %d ", i, a[i]);

	}
}


*/


/*


//question 2:

void print_array(int* a, int n);
void sort_array(int* a, int n);
void input_array(int* a, int n);
void main()
{
	int n;
	printf("enter n: ");
	scanf_s("%d", &n);
	int* a = (int*)calloc(n, sizeof(int));
	input_array(a, n);
	sort_array(a, n);
	print_array(a, n);
	free(a);
}
void input_array(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\nenter number to array: ");
		scanf_s("%d", &a[i]);
	}
}
void sort_array(int* a, int n)
{
	int count_0 = 0, count_1 = 0, count_2 = 0,i;
	for (i = 0; i < n; i++)
	{
		switch (a[i])
		{
		case 0:
			count_0++;
			break;
		case 1:
			count_1++;
			break;
		case 2:
			count_2++;
			break;
		}
	}
	
	i = 0;
	while (count_0 > 0)
		{
			a[i] = 0;
			i++;
			count_0--;
		}
	while (count_1>0)
		{
			a[i] = 1;
			i++;
			count_1--;
		}
	while (count_2>0)
		{
			a[i] = 2;
			i++;
			count_2--;
		}
	
}
void print_array(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\na[%d]= %d ", i, a[i]);

	}
}

*/


/*




//question 3:

void print_array(int* a, int n);
void sort_array(int* a, int n);
void input_array(int* a, int n);
void main()
{
	int n;
	printf("enter n: ");
	scanf_s("%d", &n);
	int* a = (int*)calloc(n, sizeof(int));
	input_array(a, n);
	sort_array(a, n);
	print_array(a, n);
	free(a);
}
void input_array(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\nenter number to array: ");
		scanf_s("%d", &a[i]);
	}
}
void sort_array(int* a, int n)
{
	int* count = (int*)calloc(n + 1, sizeof(int));
	int i,j=0;
	if (count == NULL)
	{
		printf("error!");
		exit(1);
	}
	for (i = 0; i < n; i++)
	{
		count[a[i]]++;
		
	}
	for (i = 0; i <= n; i++)
	{
		while (count[i] > 0)
		{
			a[j] = i;
			j++;
			count[i]--;
		}
	}
	free(count);

}
void print_array(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\na[%d]= %d ", i, a[i]);

	}
}

*/



/*



//question 4:

void print_array(int* a, int n);
void sort_array(int* a, int n);
void input_array(int* a, int n);
void main()
{
	int n;
	printf("enter n: ");
	scanf_s("%d", &n);
	int* a = (int*)calloc(n, sizeof(int));
	input_array(a, n);
	sort_array(a, n);
	print_array(a, n);
	free(a);
}
void input_array(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\nenter number to array: ");
		scanf_s("%d", &a[i]);
	}
}
void sort_array(int* a, int n)
{
	int low = 0, high = n - 1,temp;
	while (low < high)
	{
		while (a[high] < 0)
		{
			high--;
		}
		while (a[low] >= 0)
		{
			low++;
		}
		if (low < high)
		{
			temp = a[low];
			a[low] = a[high];
			a[high] = temp;
		}
	}
	

}
void print_array(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\na[%d]= %d ", i, a[i]);

	}
}
*/




/*

//question 5:

void print_array(int* a, int n);
void func(int* a, int n);
int sort_array_plus_minus(int* a, int n);
void sort_array_odd_even(int* a, int low,int high);
void input_array(int* a, int n);
void main()
{
	int n;
	printf("enter n: ");
	scanf_s("%d", &n);
	int* a = (int*)calloc(n, sizeof(int));
	input_array(a, n);
	func(a, n);
	print_array(a, n);
	free(a);
}
void input_array(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\nenter number to array: ");
		scanf_s("%d", &a[i]);
	}
}
void func(int* a, int n)
{
	int pos,low=0,high=n-1;
	pos=sort_array_plus_minus(a, n);
	sort_array_odd_even(a, low,pos-1);//sorting the left side
	sort_array_odd_even(a, pos, high);//sorting the right side

}
int sort_array_plus_minus(int* a, int n)
{
	int low = 0, high = n - 1, temp;
	while (low < high)
	{
		while (a[high] >=0)
		{
			high--;
		}
		while (a[low] <= 0)
		{
			low++;
		}
		if (low < high)
		{
			temp = a[low];
			a[low] = a[high];
			a[high] = temp;
		}
	}
	while (a[high] < 0)
	{
		high++;
	}
	return(high);

}
void sort_array_odd_even(int* a,int low,int high)
{
	int temp;
	while (low<high)
	{
		while (a[high] % 2 == 1)
		{
			high--;
		}
		while (a[low] % 2 == 0)
		{
			low++;
		}
		if (low < high)
		{
			temp = a[low];
			a[low] = a[high];
			a[high] = temp;
		}
	}
}
void print_array(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\na[%d]= %d ", i, a[i]);

	}
}

*/


/*





//question 6:

int sort_to_3(int* a, int low,int high,int k);
void print_array(int* a, int n);
void sort_array(int* a, int n);
void input_array(int* a, int n);
void main()
{
	int n;
	printf("enter n: ");
	scanf_s("%d", &n);
	int* a = (int*)calloc(n, sizeof(int));
	input_array(a, n);
	sort_array(a, n);
	print_array(a, n);
	free(a);
}
void input_array(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\nenter number to array: ");
		scanf_s("%d", &a[i]);
	}
}
void sort_array(int* a, int n)
{
	int k=0,i,pos,low=0,high=n-1;
	pos = sort_to_3(a, low,high, k);//for a%3==0
	k++;
	pos = sort_to_3(a, pos,high, k);//for a%3==1
	k++;
	pos = sort_to_3(a, pos, high, k);//for a%3==2


	

}
int sort_to_3(int* a, int low,int high,int k)
{
	int  temp;
	while (low < high)
	{
		while (a[high] % 3 != k)
		{
			high--;
		}
		while (a[low] % 3 == k)
		{
			low++;
		}
		if (low < high)
		{
			temp = a[low];
			a[low] = a[high];
			a[high] = temp;
		}
	}
	while (a[high] % 3 == k)
	{
		high++;
	}
	return(high);
}
void print_array(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\na[%d]= %d ", i, a[i]);

	}
}

*/




/*

//question 7:


void print_array(int* a, int n);
int check_if_same(int* a,int *b, int n);
void input_array(int* a, int n);
void main()
{
	int n;
	printf("enter n: ");
	scanf_s("%d", &n);
	int* a = (int*)calloc(n, sizeof(int));
	int* b = (int*)calloc(n, sizeof(int));
	if (a == NULL||b==NULL)
	{
		printf("error!");
		exit(1);
	}
	input_array(a, n);
	printf("\nsecond array:");
	input_array(b, n);
	int t=check_if_same(a,b, n);
	printf("\nthe answer is: %d", t);
	free(a);
	free(b);
}
void input_array(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\nenter number to array: ");
		scanf_s("%d", &a[i]);
	}
}
int check_if_same(int* a,int * b, int n)
{
	int min = a[0], max = a[0], i;
	for (i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int* count = (int*)calloc(max - min + 1, sizeof(int));
	if (count == NULL)
	{
		printf("error!");
		exit(1);
	}
	for (i = 0; i < n; i++)
	{
		if (b[i] > max || b[i] < min)
		{
			
			return(0);
		}
		count[a[i]]++;
		count[b[i]]++;
	}
	for (i = 0; i < max-min+1; i++)
	{
		if (count[i]%2==1)
		{
			
			return(0);
		}
	}

	
	return(1);


}
*/


/*

//question 8:


int func(int* a, int n);
void sort_array(int* a, int low, int high);
int partition(int* a, int low, int high);
void input_array(int* a, int n);
void main()
{
	int n;
	printf("enter n: ");
	scanf_s("%d", &n);
	int* a = (int*)calloc(n, sizeof(int));
	if (a == NULL)
	{
		printf("error!");
		exit(1);
	}
	input_array(a, n);
	int t = func(a, n);
	printf("\nthe answer is: %d", t);
	free(a);
	
}
void input_array(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\nenter number to array: ");
		scanf_s("%d", &a[i]);
	}
}
int func(int* a, int n)
{
	if (n == 1)
	{
		return(a[0]);
	}
	int low = 0, high = n-1,sum=0,i=0;
	sort_array(a, low, high);
	while (i < n-1)
	{
		if (sum + a[i] == a[i + 1])
		{
			return(a[i + 1]);
		}
		else
		{
			sum += a[i];
		}
		i++;
	}
}
void sort_array(int* a, int low, int high)
{
	int pos;
	if (low < high)
	{
		pos = partition(a, low, high);
		sort_array(a, low, pos - 1);
		sort_array(a, pos + 1, high);
		
	}
}
int partition(int* a, int low, int high)
{
	int temp;
	int first = low;
	int pivot = a[first];
	while (low < high)
	{
		
		while (a[high] > pivot)
		{
			high--;
		}
		while (low<high  &&  a[low] <= pivot)
		{
			low++;
		}
		if (low < high)
		{
			temp = a[low];
			a[low] = a[high];
			a[high] = temp;
		}
	}
	temp = a[first];
	a[first] = a[high];
	a[high] = temp;
	return(high);
}
*/




/*
//question 9:




int func(int* a, int n);
void sort_array(int* a, int low, int high);
int partition(int* a, int low, int high);
void input_array(int* a, int n);
void main()
{
	int n;
	printf("enter n: ");
	scanf_s("%d", &n);
	int* a = (int*)calloc(n, sizeof(int));
	if (a == NULL)
	{
		printf("error!");
		exit(1);
	}
	input_array(a, n);
	int t = func(a, n);
	printf("\nthe answer is: %d", t);
	free(a);

}
void input_array(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\nenter number to array: ");
		scanf_s("%d", &a[i]);
	}
}
int func(int* a, int n)
{
	int low = 0, high = n - 1,min,i=1,temp;
	sort_array(a, low, high);
	min = a[0] - a[1];
	if (min < 0)
	{
		min *= -1;
	}
	while (i<n-1)
	{
		temp = a[i] - a[i + 1];
		if (temp < 0)
		{
			temp *= -1;
		}
		if (temp < min)
		{
			min = temp;
		}
		i++;
	}
	return(min);
}
void sort_array(int* a, int low, int high)
{
	int pos;
	if (low < high)
	{
		pos = partition(a, low, high);
		sort_array(a, low, pos - 1);
		sort_array(a, pos + 1, high);

	}
}
int partition(int* a, int low, int high)
{
	int temp;
	int first = low;
	int pivot = a[first];
	while (low < high)
	{

		while (a[high] > pivot)
		{
			high--;
		}
		while (low < high && a[low] <= pivot)
		{
			low++;
		}
		if (low < high)
		{
			temp = a[low];
			a[low] = a[high];
			a[high] = temp;
		}
	}
	temp = a[first];
	a[first] = a[high];
	a[high] = temp;
	return(high);
}

*/




/*



//question 10:


int partition(int* a, int low, int high);
void sort_array(int* a, int low, int high);
int* new_arr(int* a, int n,int k);
void input_array(int* a, int n);
void print_array(int* a, int n);
void main()
{
	int n,k;
	printf("enter n: ");
	scanf_s("%d", &n);
	printf("enter k: ");
	scanf_s("%d", &k);
	int* a = (int*)calloc(n, sizeof(int));
	if (a == NULL)
	{
		printf("error!");
		exit(1);
	}
	input_array(a, n);
	int *t = new_arr(a, n,k);
	print_array(t, k);
	free(a);
	free(t);

}
void input_array(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\nenter number to array: ");
		scanf_s("%d", &a[i]);
	}
}
void print_array(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\na[%d]= %d ", i, a[i]);

	}
}
int* new_arr(int* a, int n,int k)
{
	int low = 0, high = n - 1,i;
	sort_array(a, low,high);
	int* t = (int*)calloc(k, sizeof(int));
	if (t == NULL)
	{
		printf("error!");
		exit(1);
	}
	for (i = 0; i < k; i++)
	{
		t[i] = a[i];
	}
	return(t);
}
void sort_array(int* a, int low, int high)
{
	int pos;
	if (low < high)
	{
		pos = partition(a, low, high);
		sort_array(a, low, pos - 1);
		sort_array(a, pos + 1, high);
	}
}
int partition(int* a, int low, int high)
{
	int first = low,temp;
	int pivot = a[first];
	while (low < high)
	{
		while (a[high] > pivot)
		{
			high--;
		}
		while (low < high && a[low] <= pivot)
		{
			low++;
		}
		if (low < high)
		{
			temp = a[low];
			a[low] = a[high];
			a[high] = temp;
		}
	}
	temp = a[high];
	a[high] = a[first];
	a[first] = temp;
	return(high);
}

*/
