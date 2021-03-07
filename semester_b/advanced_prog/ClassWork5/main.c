#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "structs.h"



void main()
{
	student_init_data student_data[4];
	int size = 4;
	int i;
	for (i = 0; i<size; i++)
	{
		printf("\nstudent number %d:\n", i + 1);
		printf("\nenter id : ");
		scanf_s("%ld", &student_data[i].id);
		printf("\nenter amount of tests : ");
		scanf_s("%d", &student_data[i].test_num);
		student_data[i].ptr_grades = Input_Data(student_data[i].test_num);
	}
	statistics s1;
	Classification(&s1, student_data,size);
	Print_Tab(s1);
	Free_Memory(student_data, s1,size);
}
