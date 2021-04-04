#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>





void print_matrix_bot(int N, int** mat)
{
	int i, j,x;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			x = pos_bot_tri_mat(mat, i, j);
			if (x < 10)
			{
				printf("%d  ", x);
			}
			else
			{
				printf("%d ", x);
			}
			
		}
		printf("\n");
	}
}

void print_matrix_top(int N, int** mat)
{
	int i, j, x;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			x = pos_top_tri_mat(mat, i, j);
			if (x < 10)
			{
				printf("%d  ", x);
			}
			else
			{
				printf("%d ", x);
			}

		}
		printf("\n");
	}
}


void delete_matrix(int row, int*** mat)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		free((*mat)[i]);
	}
	free(*mat);
}

int** create_bot_tri_mat(int N)
{
	int i, j;
	int** mat = (int**)calloc(N, sizeof(int*));
	for (i = 0; i < N; i++)
	{
		mat[i] = (int*)calloc(i + 1, sizeof(int));
		for (j = 0; j < i + 1; j++)
		{

				mat[i][j] = i + j + 1;
			
		}
	}
	return(mat);
}

int pos_bot_tri_mat(int** mat, int i, int j)
{
	if (i < j)
	{
		return(0);
	}
	else
	{
		return(mat[i][j]);
	}
}

int** create_top_tri_mat(int N)
{
	int i, j;
	int** mat = (int**)calloc(N, sizeof(int*));
	for (i = 0; i < N; i++)
	{

		mat[i] = (int*)calloc(N-i, sizeof(int));
		for (j = 0; j < N-i; j++)
		{
			mat[i][j] = i + j + 1;
			
			
		}
		
	}
	return(mat);
}

int pos_top_tri_mat(int** mat, int i, int j)
{
	if (i > j)
	{
		return(0);
	}
	else
	{
		return(mat[i][j-i]);
	}
}
void main()
{
	int size;
	printf("enter size of matrix:");
	scanf_s("%d", &size);
	int** bot_tri = create_bot_tri_mat(size);
	print_matrix_bot(size, bot_tri);
	printf("\n\n");
	int** top_tri = create_top_tri_mat(size);
	print_matrix_top(size, top_tri);
	delete_matrix(size,&top_tri);
	delete_matrix(size,&bot_tri);
	
}
