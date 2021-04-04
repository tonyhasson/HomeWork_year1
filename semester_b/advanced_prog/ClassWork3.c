#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>




int** create_matrix(int row,int col)
{
	int** mat;
	mat= (int**)calloc(row, sizeof(int*));
	int i;
	for (i = 0; i < row; i++)
	{
		mat[i]= (int*)calloc(col, sizeof(int));
	}
	return(mat);

}
void fill_matrix(int row, int col, int*** mat)
{
	int i,j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			(*mat)[i][j] = 10 * i + j;
		}
	}
}
void print_matrix(int row, int col, int** mat)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (mat[i][j] < 10)
			{
				printf("%d  ", mat[i][j]);
			}
			else
			{
				printf("%d ", mat[i][j]);
			}
			
		}
		printf("\n");
	}
}
void delete_matrix(int row, int col, int*** mat)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		free((*mat)[i]);
	}
	free(*mat);
}
void swap_rows(int*** mat,int row1,int row2)
{
	int** temp;
	temp = (*mat)[row1];
	(*mat)[row1] = (*mat)[row2];
	(*mat)[row2] = temp;
	
}
void swap_cols(int*** mat, int col1, int col2,int row)
{
	int i, j, temp;
	for (i = 0; i < row; i++)
	{
		temp = (*mat)[i][col1];
		(*mat)[i][col1] = (*mat)[i][col2];
		(*mat)[i][col2] = temp;
	}

}
void main()
{
	int row, col,change1,change2;
	printf("enter row and col: ");
	scanf_s("%d%d", &row, &col);
	int** matrix = create_matrix(row,col);
	fill_matrix(row, col, &matrix);
	print_matrix(row, col, matrix);
	printf("\n\nenter desired rows to change:");
	scanf_s("%d%d", &change1, &change2);
	swap_rows(&matrix, change1, change2);
	printf("\n");
	print_matrix(row, col, matrix);
	printf("\n\nenter desired cols to change:");
	scanf_s("%d%d", &change1, &change2);
	swap_cols(&matrix, change1, change2, row);
	printf("\n");
	print_matrix(row, col, matrix);
	delete_matrix(row, col, &matrix);
}
