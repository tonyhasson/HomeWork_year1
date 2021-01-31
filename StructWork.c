#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>


/*

//question 1+2:
typedef struct point {
	double x;
	double y;
} Point;
typedef struct circle {
	Point center;
	double radius;
} Circle;




int func1(Point* a, int n, Circle c);
Point* func2(Point* a, int n, Circle c, int* p);
void main()
{
	int i;
	Point a[] = { {2,5},{3,6},{25,8},{60,3} }, center = {5,8};
	int n = 4,p;
	Circle c = {center,6};
	printf("the answer is : %d", func1(a, n, c));
	
	Point* t = func2(a, n, c, &p);
	for (i = 0; i < p; i++)
	{
		printf("\n(%lf ,%.2lf)", t[i].x, t[i].y);
	}
	free(t);
}
int func1(Point* a, int n, Circle c)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (sqrt(pow(a[i].x - c.center.x, 2) + pow(a[i].y - c.center.y, 2)) > c.radius)
		{
			return(0);
			
		}
	}
	return(1);
}
Point* func2(Point* a, int n, Circle c, int* p)
{
	int i,j=0,count=0;
	for (i = 0; i < n; i++)
	{
		if (sqrt(pow(a[i].x - c.center.x, 2) + pow(a[i].y - c.center.y, 2)) > c.radius)
		{
			count++;

		}
	}
	Point* new_p = (Point*)calloc(count, sizeof(Point));
	assert(new_p);

	for (i = 0; i < n; i++)
	{
		if (sqrt(pow(a[i].x - c.center.x, 2) + pow(a[i].y - c.center.y, 2)) > c.radius)
		{
			new_p[j].x = a[i].x;
			new_p[j].y = a[i].y;
			j++;
		}
	}
	*p = count;
	
	return(new_p);
}

*/





/*

//question 3:


typedef struct date
{
	int day;
	int month;
	int year;
} Date;

typedef struct student
{
	unsigned id;
	char year;
	double average;
	//Date birthday;
} Student;


int func(Student* s,int n,unsigned taz );
void main()
{
	Student s[]= { {316047281, 'a',5},{716047282, 'b',70},{312047281, 'a',16},{316067281, 'a',96},{316042281, 'c',97},{316047285, 'a',6} };
	unsigned taz = 316047281;
	int n = 6;
	printf("the answer is:%d", func(s, n, taz));
	for (int i = 0; i < n; i++)
	{
		printf("\n%lf", s[i].average);
	}
}
int func(Student* s, int n, unsigned taz)
{
	int i,tf=0,pos,j;
	for (i = 0; i < n; i++)
	{
		if (s[i].id == taz)
		{
			
			tf = 1;
			pos = i;
		}
	}
	if (tf == 0)
	{
		return(0);
	}
	else
	{
		int count = 0;
		for (i = 0; i < n; i++)
		{
			if (i != pos)
			{
				if (s[i].average <=s[pos].average )
				{
					count++;
				}
			}
		}
		Student temp = s[count];
		s[count] = s[pos];
		s[pos] = temp;
		i = 0;
		j = n - 1;
		while (i < j)
		{
			while (s[j].average > s[count].average) j--;
			while ((i < j) && (s[i].average <= s[count].average)) i++;
			if (i < j)
			{
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
		return(1);

	}
}

*/
