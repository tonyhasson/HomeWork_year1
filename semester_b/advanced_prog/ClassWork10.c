#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#pragma warning(disable:4996)


//question1
int countLines(char* filename)
{
  FILE* tmp;
  int count = 0;
  tmp = fopen(filename, "r");
  while (!feof(tmp))
  {
      if (fgetc(tmp) == '\n')
      {
          count++;
      }
      
  }
  fclose(tmp);
  return(count);
}


//question2
void letterFrequency(char* filename, int counts[])
{
    FILE* tmp;
    char c;
    tmp = fopen(filename, "r");
    fscanf(tmp, " %c", &c);
    while (!feof(tmp))
    {
       
        if (c >= 'a' && c <= 'z')
        {
            counts[c - 'a']++;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            counts[c - 'A']++;
        }
        fscanf(tmp, " %c", &c);
    }
    int i;
    for (i = 0; i < 25; i++)
    {
        printf("amount of %c = %d\n", i + 'A', counts[i]);
    }
    fclose(tmp);
}

//question3
void removeSpaces(char* infile, char* outfile)
{
    FILE* tmp_og,*tmp_new;
    tmp_og = fopen(infile, "r");
    tmp_new = fopen(outfile, "w");
    char c;
    c = fgetc(tmp_og);
    while (!feof(tmp_og))
    {
        if(c!=' ')
        fprintf(tmp_new, "%c",c);
        c = fgetc(tmp_og);
    }

    fclose(tmp_og);
    fclose(tmp_new);

    
}


//printing text file

void print_file(char* filename)
{
    FILE* tmp;
    char c;
    tmp = fopen(filename, "r");
    c = fgetc(tmp);
    while (!feof(tmp))
    {
        if (c != '\n')
        {
            printf("%c", c);
        }
        else
        {
            printf("\n");
        }
        c = fgetc(tmp);
    }



    fclose(tmp);
}





void main()
{
   
   

    //creating file

    FILE* tmp;
    tmp = fopen("tst.txt","w");
    if (tmp == NULL)
    {
        printf("file not available");
        exit(1);
    }
    fprintf(tmp, "hello this is my first test page\n");
    fprintf(tmp, "hello this is my first test page\n");
    fprintf(tmp, "hello this is my first test page\n");
    fprintf(tmp, "hello this is my first test page\n");
    fprintf(tmp, "hello this is my first test page\n");
    fprintf(tmp, "hello this is my first test page\n");
    fclose(tmp);

    //question1:

    int numLines;
    numLines = countLines("tst.txt");
    printf("The number of lines is %d", numLines);

    printf("\n\n\n");
    //question2:

    int counts[25] = {0};
    letterFrequency("tst.txt",counts);

    printf("\n\n\n");
   //question3:

    removeSpaces("tst.txt", "tst2.txt");
    print_file("tst2.txt");
}

