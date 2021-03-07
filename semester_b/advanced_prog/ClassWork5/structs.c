#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "structs.h"

int* Input_Data(int test_num)
{
	int* grades = (int*)calloc(test_num, sizeof(int));
	assert(grades);
	int i;
	for (i = 0; i < test_num; i++)
	{
		printf("enter grade number %d:\n", i + 1);
		scanf_s("%d", &grades[i]);
	}
	return(grades);
}
double Student_Average(int* arr,int size)
{
	int i,sum = 0;
	double avg;
	for (i = 0; i < size; i++)
	{
		sum += arr[i];
		
	}
	avg= (double) sum / size;
	return (avg);
}
double Total_Average(double* arr,int size)
{
	int i, sum = 0;
	double avg;
	for (i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	avg = (double)sum / size;
	return (avg);
}
void Classification(statistics* stat, student_init_data* arr,int size)
{   
	int i, j,t, size_a = 0, size_b = 0;
	double* avg_arr = (double*)calloc(sizeof(size), sizeof(double));
	assert(avg_arr);
	for (i = 0; i < size; i++)
	{
		avg_arr[i] = Student_Average(arr[i].ptr_grades,arr[i].test_num);
		
	}
	stat->total_average = Total_Average(avg_arr,size);
	for (i = 0; i < size; i++)
	{
		if (avg_arr[i] >= stat->total_average)
		{
			size_a++;
		}   
		else
		{
			size_b++;
		}
	}
	
	student_processed_data* group_a = (student_processed_data*)calloc(size_a, sizeof(student_processed_data));
	student_processed_data* group_b = (student_processed_data*)calloc(size_b, sizeof(student_processed_data));
	j = 0;
	t = 0;
	for (i = 0; i < size; i++)
	{
		if (avg_arr[i] >= stat->total_average)
		{
			group_a[j].average = avg_arr[i];
			group_a[j].id = arr[i].id;
			j++;
		}
		else
		{
			group_b[t].average = avg_arr[i];
			group_b[t].id = arr[i].id;
			t++;
		}
	}
	stat->size_a = size_a;
	stat->size_b = size_b;
	stat->group_a = group_a;
	stat->group_b = group_b;
	free(avg_arr);
}
void Print_Tab(statistics stat)
{
	printf("\ntotal average: %lf\n", stat.total_average);
	int i;
	printf("\ngroup above average,total of %d students: \n", stat.size_a);
	for (i = 0; i < stat.size_a; i++)
	{
		printf("\nid: %ld\n", stat.group_a[i].id);
		printf("average: %lf\n", stat.group_a[i].average);
	}
	printf("\ngroup below average,total of %d students\n", stat.size_b);
	for (i = 0; i < stat.size_b; i++)
	{
		printf("\nid: %ld\n", stat.group_b[i].id);
		printf("average: %lf\n", stat.group_b[i].average);
	}
}
void Free_Memory(student_init_data* arr, statistics stat,int size)
{
	free(stat.group_a);
	free(stat.group_b);
	int i;
	for (i = 0; i < size; i++)
	{
		free(arr[i].ptr_grades);
	}
}
