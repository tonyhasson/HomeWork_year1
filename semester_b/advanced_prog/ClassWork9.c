#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>




int func1(char* str, char c)
{
	int i=0,pos=-1;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			pos = i;
		}

		i++;
	}
	return(pos);
}

void func2(char* str1, char* str2)
{
	char tmp[30];
	strcpy_s(tmp,30, str1);
	strcpy_s(str1,30, str2);
	strcpy_s(str2,30, tmp);
}

