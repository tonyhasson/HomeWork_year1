#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>



//question 1:
int func1(char* s)
{
	int i,n=strlen(s),ret=1;
	char tmp;
	for (i = 0; i < n / 2; i++)
	{
		if (s[i] != s[n - 1 - i])
		{
			ret = 0;
		}
		tmp = s[i];
		s[i] =s[n-1-i];
		s[n - 1 - i] = tmp;
	}
	
	printf("the opposite string is: %s \n", s);
	return(ret);

}
//quetsion 2
void func2(char* s, int* arr_answer)
{
	int i=0;
	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			arr_answer[0]++;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			arr_answer[1]++;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			arr_answer[2]++;
		}
		else
		{
			arr_answer[3]++;
		}
		i++;
	}
}
//question 3
void func3(char* s)
{
	int i=0,j=0;
	char tmp[30];
	while (s[i] != '\0')
	{
		while (s[i] == 32&&s[i+1]==32)
		{
			i++;
		}
		if (s[i] != '\0')
		{
			tmp[j] = s[i];
			i++;
			j++;
		}
	}
	tmp[j] = '\0';//ends the string

	strcpy_s(s, 30, tmp);
}
