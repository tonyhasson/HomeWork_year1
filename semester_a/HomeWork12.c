#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>


/*

//question 1:


#define C 3
#define R 3

void print_array(double * a);
void input_array(int a[][C]);
double* avg(int a[][C]);
void main()
{
	int a[R][C];
	input_array(a);
	double* t = avg(a);
	print_array(t);


    

}
void input_array(int a[][C])
{
	int i, j;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			printf("enter to a[%d][%d]: ", i, j);
			scanf_s("%d", &a[i][j]);
		}
	}
}
void print_array(double * a)
{
	int i;
	for (i = 0; i < R; i++)
	{
		printf("%.2f ",a[i] );
	}
}
double* avg(int a[][C])
{
	int i, j,sum=0;
	double* t = (double*)calloc(R, sizeof(double));
	for (i = 0; i < R; i++)
	{
		sum = 0;
		for (j = 0; j < C; j++)
		{
			sum += a[i][j];
		}
		t[i] = (double)sum / (double)C;
	}
	return(t);
} 

*/




/*

//question 2:


#define N 3

void print_array(int * a);
void input_array(int a[][N]);
int * sum_sub(int a[][N]);
void main()
{
	int a[N][N];
	input_array(a);
	int* t = sum_sub(a);
	print_array(t);
	free(t);




}
void input_array(int a[][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("enter to a[%d][%d]: ", i, j);
			scanf_s("%d", &a[i][j]);
		}
	}
}
void print_array(int * a)
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
}
int* sum_sub(int a[][N])
{
	int i, j, sum_row = 0, sum_col = 0;
	int* t = (int*)calloc(N, sizeof(int));
	if (t == NULL)
	{
		printf("error!");
		exit(1);
	}
	for (i = 0; i < N; i++)
	{
		sum_row = 0;
		sum_col = 0;
		for (j = 0; j < N; j++)
		{
			sum_row += a[i][j];
			sum_col += a[j][i];
		}
		t[i] = sum_row - sum_col;
	}
	return(t);
}
*/


/*


//question 3:



#define N 4

void print_array(int* a);
void input_array(int a[][N]);
int skalar_calc(int a[][N]);
void main()
{
	int a[N][N];
	input_array(a);
	printf("the answer is : %d", skalar_calc(a));



}
void input_array(int a[][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("enter to a[%d][%d]: ", i, j);
			scanf_s("%d", &a[i][j]);
		}
		if (i < N - 1)
		{
			printf("\nnew row\n");
		}
	}
}
int skalar_calc(int a[][N])
{
	int sum=0,mult=1,i,main_index=0,sec_index=N-1;
	for (i = 0; i < N; i++)
	{
		mult = a[i][main_index] * a[i][sec_index];
		sum += mult;
		main_index++;
		sec_index--;
	}
	return(sum);

}

*/



/*

//question 4:

#define N 3

void print_array(int* a);
void input_array(int a[][N]);
int simetrical(int a[][N]);
void main()
{
	int a[N][N];
	input_array(a);
	printf("the answer is : %d", simetrical(a));



}
void input_array(int a[][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("enter to a[%d][%d]: ", i, j);
			scanf_s("%d", &a[i][j]);
		}
		if (i < N - 1)
		{
			printf("\nnew row\n");
		}
	}
}
int simetrical(int a[][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (a[i][j] != a[j][i])
			{
				return(0);
			}
		}
	}
	return(1);

}

*/



/*

//question 5:



#define N 4

void print_array(int* a);
void input_array(int a[][N]);
int in_order(int a[][N]);
void main()
{
	int a[N][N];
	input_array(a);
	printf("the answer is : %d", in_order(a));



}
void input_array(int a[][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("enter to a[%d][%d]: ", i, j);
			scanf_s("%d", &a[i][j]);
		}
		if (i < N - 1)
		{
			printf("\nnew row\n");
		}
	}
}
int in_order(int a[][N])
{
	int i, j=N-1;
	for (i = 0; i < N-1; i++)
	{
		if (a[i][i] > a[i + 1][i + 1])
		{
			return(0);
		}
	}
	if (a[N - 1][N - 1] > a[0][N - 1])
	{
		return(0);
	}
	for (i = 0; i < N-1; i++)
	{
		if (a[i][j] > a[i + 1][j - 1])
		{
			return(0);
		}
		j--;


	}
	return(1);

}
*/



/*


//question 6:



#define N 3

void print_array(int* a);
void input_array(int a[][N]);
void find_key_pos(int a[][N],  int* i_pos, int* j_pos, int key);
void main()
{
	int a[N][N],i_pos,j_pos,key;
	input_array(a);
	printf("enter key: ");
	scanf_s("%d", &key);
	find_key_pos(a, &i_pos, &j_pos, key);
	printf("the position of key is :[%d][%d]",i_pos,j_pos );



}
void input_array(int a[][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("enter to a[%d][%d]: ", i, j);
			scanf_s("%d", &a[i][j]);
		}
		if (i < N - 1)
		{
			printf("\nnew row\n");
		}
	}
}
void find_key_pos(int a[][N],int * i_pos,int * j_pos,int key)
{
	int i, j,mid, high=N-1, low=0,min_main=a[0][0],max_main=a[N-1][N-1],min_sec=a[0][N-1],max_sec=a[N-1][0];
	*i_pos = -1;
	*j_pos = -1;

	int* new_arr = (int*)calloc(N, sizeof(int));
	if (new_arr == NULL)
	{
		printf("error!");
		exit(1);
	}
	if (key >= min_main && key <= max_main)
	{
		for (i = 0; i < N; i++)
		{
			new_arr[i] = a[i][i];
		}
		while (low < high)
		{
			mid = (high + low) / 2;
			if (new_arr[mid] < key)
			{
				low = mid + 1;
			}
			else if (new_arr[mid] > key)
			{
				high = mid - 1;
			}
			else
			{
				*i_pos = mid;
				*j_pos = mid;
				low = high;
				
			}
		}
		
	}
	else if (key >= min_sec && key <= max_sec)
	{
		for (i = 0; i < N; i++)
		{
			new_arr[i] = a[i][N-1-i];
		}
		while (low < high)
		{
			mid = (high + low) / 2;
			if (new_arr[mid] < key)
			{
				low = mid + 1;
			}
			else if (new_arr[mid] > key)
			{
				high = mid - 1;
			}
			else
			{
				*i_pos = mid;
				*j_pos = N-1-mid;
				low = high;
			}
		}

	}
	free(new_arr);

}

*/


/*



//question 7:



#define C 3
#define R 4


void input_array(int a[][C]);
int check_order(int a[][C]);
void main()
{
	int a[R][C];
	input_array(a);
	printf("the answer is: %d", check_order(a));




}
void input_array(int a[][C])
{
	int i, j;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			printf("enter to a[%d][%d]: ", i, j);
			scanf_s("%d", &a[i][j]);
		}
		if (i < R - 1)
		{
			printf("\nnew row\n");
		}
	}
}
int check_order(int a[][C])
{
	int i, j;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C-1; j++)
		{
			if (a[i][j] > a[i][j + 1])
			{
				return(0);
			}
		}
		if (i < R - 1)
		{
			if (a[i][C - 1] > a[i + 1][0])
			{
				return(0);
			}
		}
	}
	return(1);
}


*/




/*

//question 8:



#define C 3
#define R 4


void input_array(int a[][C]);
void find_key_pos(int a[][C], int* i_pos, int* j_pos, int key);
void main()
{
	int a[R][C],key,i_pos,j_pos;
	input_array(a);
	printf("\nenter key: ");
	scanf_s("%d", &key);
	find_key_pos(a, &i_pos, &j_pos, key);
	printf("\nthe position of key is: [%d][%d]",i_pos,j_pos);




}
void input_array(int a[][C])
{
	int i, j;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			printf("enter to a[%d][%d]: ", i, j);
			scanf_s("%d", &a[i][j]);
		}
		if (i < R - 1)
		{
			printf("\nnew row\n");
		}
	}
}
void find_key_pos(int a[][C],int * i_pos,int *j_pos,int key)
{
	int i, j, high = C - 1, low = 0, mid,row=-1;
	*i_pos = -1;
	*j_pos = -1;
	for (i = 0; i < R; i++)
	{
		
		if (key >= a[i][0] && key <= a[i][C - 1])
		{
			row = i;
			i = R;
		}
	}
	if (row != -1)
	{
		
		while (low < high)
		{
			
			mid = (high + low) / 2;
			if (a[row][mid] < key)
			{
				low = mid + 1;
			}
			else if (a[row][mid] > key)
			{
				high = mid - 1;
			}
			else
			{
				*i_pos = row;
				*j_pos = mid;
				low = high;
			}
		}
	}
	
}


*/




/*



//question 9:



#define N 3


void input_array(int a[][N]);
int in_order(int a[][N]);
void main()
{
	int a[N][N];
	input_array(a);
	printf("the answer is : %d", in_order(a));



}
void input_array(int a[][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("enter to a[%d][%d]: ", i, j);
			scanf_s("%d", &a[i][j]);
		}
		if (i < N - 1)
		{
			printf("\nnew row\n");
		}
	}
}
int in_order(int a[][N])
{
	int i, j;
	int* count = (int*)calloc(N * N, sizeof(int));
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (a[i][j] > 9 || a[i][j] < 1)
			{
				return(0);
			}
			else
			{
				count[a[i][j] - 1]++;
			}
		}
	}
	
	for (i = 0; i < N*N; i++)
	{
		if (count[i] < 1 || count[i]>1)
		{
			return(0);
		}
	}
	return(1);

}

*/






/*

//question 10:

#define C 3
#define R 4


void input_array(int a[][C]);
void change_order(int a[][C]);
void print_array(int* a[][C]);
void main()
{
	int a[R][C];
	input_array(a);
	change_order(a);
	print_array(a);




}
void input_array(int a[][C])
{
	int i, j;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			printf("enter to a[%d][%d]: ", i, j);
			scanf_s("%d", &a[i][j]);
		}
		if (i < R - 1)
		{
			printf("\nnew row\n");
		}
	}
}
void change_order(int a[][C])
{
	int i, j,temp1;
	int* temp = (int*)calloc(C, sizeof(int));
	for (i = 0; i <R; i++)
	{
		for (j = 0; j < C ; j++)
		{
			if (i == 0)
			{
				temp[j] = a[i][j];
				a[i][j] = a[R - 1][j];
			}
			else
			{
				temp1 = temp[j];
				temp[j] = a[i][j];
				a[i][j] = temp1;

			}
		}
		
	}
	
	
}
void print_array(int* a[][C])
{
	int i,j;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}


*/





/*


//question 11 hard mode:





#define N 6

void print_array(int* a[][N]);
void input_array(int a[][N]);
void change_order(int a[][N], int temp_size,int temp_i,int temp_j);
void main()
{
	int a[N][N], temp_size = N,temp_i=0,temp_j=0;
	input_array(a);
	change_order(a, temp_size,temp_i,temp_j);
	



}
void input_array(int a[][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("enter to a[%d][%d]: ", i, j);
			scanf_s("%d", &a[i][j]);
		}
		if (i < N - 1)
		{
			printf("\nnew row\n");
		}
	}
}
void change_order(int a[][N], int temp_size,int temp_i,int temp_j)
{
	printf("first array inputed: \n");
	print_array(a);
	int i, j, temp_square, temp_tri, count, temp_end_row_3, temp_end_col_2;
	if (temp_size > 2)//when size of matrix is bigger than 2
	{
		for (count = 0; count < temp_size - 1; count++)
		{
			for (i = temp_i; i < temp_size+temp_i; i++)
			{
				for (j = temp_j; j < temp_size+temp_j; j++)
				{
					if (i == temp_i)//row 1
					{
						if (j == temp_j && i == temp_i)
						{
							temp_square = a[i][j];
						}
						else
						{
							temp_tri = a[i][j];
							a[i][j] = temp_square;
							temp_square = temp_tri;
						}
					}
					if (j == temp_size - 1+temp_j && i > temp_i && i < temp_size+temp_i - 1)//col 2
					{
						temp_tri = a[i][j];
						a[i][j] = temp_square;
						temp_square = temp_tri;
						if (i == temp_size - 2+temp_i)
						{
							temp_end_col_2 = temp_square;
						}
					}
					if (i == temp_size - 1+temp_i)//row 3
					{
						if (j == temp_size - 1+temp_j)
						{
							a[i][j - 1] = a[i][j];
							a[i][j] = temp_end_col_2;
						}

						if (j > temp_j && j < temp_size - 1+temp_j)
						{
							a[i][j - 1] = a[i][j];
						}

					}
					if (j == temp_j && i < temp_size - 1+temp_i)//col 4
					{

						a[i][j] = a[i + 1][j];


					}
				}
			}
			printf("\n\n");
			print_array(a);
		}
	}
	if (temp_size == 2)//when size of matrix is 2
	{
		temp_square = a[temp_i][temp_j+1];
		a[temp_i][temp_j+1] = a[temp_i][temp_j];

		temp_tri = a[temp_i+1][temp_j+1];
		a[temp_i + 1][temp_j + 1] = temp_square;
		temp_square = temp_tri;

		temp_tri = a[temp_i+1][temp_j];
		a[temp_i + 1][temp_j] = temp_square;
		temp_square = temp_tri;

		a[temp_i][temp_j] = temp_square;

		printf("\n\n");
		print_array(a);
	}
	if (temp_size - 2 > 1)//recursive to deal with the inside of the matrix
	{
		change_order(a, temp_size - 2,temp_i+1,temp_j+1);
	}

}
void print_array(int* a[][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

*/
