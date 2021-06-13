#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#pragma warning(disable:4996)



void displaybits(unsigned value)
{
	unsigned c;
	unsigned display_mask = 1 << 31;
	printf("\nvalue is:");
	for (c = 1; c <= 32; c++)
	{
		putchar(value & display_mask ? '1' : '0');
		value <<= 1;
		if (c % 8 == 0)
		{
			putchar(' ');
		}
	}
	putchar('\n');
}


int go_left(unsigned num, int amount)
{
	unsigned i,k,tmp;
	for (i = 0; i < amount; i++)
	{
		k = 1 << 31;
		tmp = num & k;
		tmp >>= 31;
		num <<= 1;
		//displaybits(num);
		num += tmp;
	}
	return(num);
}

int go_right(unsigned num, int amount)
{
	unsigned i, k, tmp;
	for (i = 0; i < amount; i++)
	{
		tmp = num & 1;
		tmp <<= 31;
		num >>= 1;
		num += tmp;
	}
	return(num);
}


void main()
{
	
	unsigned n = 2864905589;
	displaybits(n);
	n = go_left(n, 8);
	displaybits(n);
	n = go_right(n, 8);
	displaybits(n);

}
