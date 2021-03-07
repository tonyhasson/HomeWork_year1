#pragma once
#include <stdio.h>


//structs

typedef struct student_init_data
{
	
	int test_num;
	int* ptr_grades;
	long id;


}student_init_data;

typedef struct student_processed_data
{
	double average;
	long id;

}student_processed_data;

typedef struct statistics
{
	int size_a;
	int size_b;
	double total_average;
	student_processed_data* group_a;
	student_processed_data* group_b;

}statistics;


//functions: 

int* Input_Data(int test_num);
double Student_Average(double* arr, int size);
double Total_Average(double* arr,int size);
void Classification(statistics* stat,student_init_data* arr,int size);
void Print_Tab(statistics stat);
void Free_Memory(student_init_data* arr,statistics stat,int size);
