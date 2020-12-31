#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>


/*
//question 1:
int inside(char *s1,char *s2);
void main()
{
    char str1[30],str2[30];
    printf("enter string number 1: ");
    gets(str1);
    printf("enter string number 2: ");
    gets(str2);
    printf("return is: %d",inside(str1,str2));
}
int inside(char *s1,char *s2)
{
    char *tmp=(char *)calloc(27,sizeof(char));
    int i,j=0;
    for(i=0;i<strlen(s2);i++)
    {
        tmp[s2[i]-97]++;
    }
    for(i=0;i<strlen(s1);i++)
    {
        if(tmp[s1[i]-97]>0)
        {
           j++;
           tmp[s1[i]-97]--;
        }
    }
    printf("\n j:%d",j);
    printf("\n len: %d",strlen(s1));
    if(j==strlen(s1))
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
*/

/*
//question 2:
int prometation(char *s1,char *s2);
void main()
{
    char str1[30],str2[30];
    printf("enter string number 1: ");
    gets(str1);
    printf("enter string number 2: ");
    gets(str2);
    printf("return is: %d",prometation(str1,str2));
}
int prometation(char *s1,char *s2)
{
    char *tmp1=(char *)calloc(27,sizeof(char));
    char *tmp2=(char *)calloc(27,sizeof(char));
    int i,j=0;
    for(i=0;i<strlen(s2);i++)
    {
        tmp2[s2[i]-97]++;
        tmp1[s1[i]-97]++;
    }
    while(j<=27)
    {
        if(tmp1[j]!=tmp2[j])
        {
            return(0);
        }
        j++;
    }
        return(1);
}
*/

/*
//question 3:
void new_str(char * str);
void main()
{
  char * s[150];
  printf("enter string: ");
  gets(s);
  new_str(s);
}
void new_str(char * str)
{
   int i=0,j,temp=0;
  while(str[i]!='\0')
    {
        if(str[temp]==str[i+1])
        {
            for(j=i+1;str[j]!='\0';j++)
            {
                str[j]=str[j+1];
            }
            str[j]='\0';
        }
        else if(str[temp]!=str[i+1])
        {
            temp++;
            i++;
        }
    }
    printf("\n%s",str);
}
*/


/*
//question 4:
void amount(char * str);
void main()
{
  char * s[150];
  printf("enter string: ");
  gets(s);
  amount(s);
}
void amount(char * str)
{
   int i=0,j,temp=0,count=0;
   char tmp_ch1,tmp_ch2;
  while(str[i]!='\0')
    {
        if(str[temp]==str[i+1])
        {
            count++;
            for(j=i+1;str[j]!='\0';j++)
            {
                str[j]=str[j+1];
            }
            str[j]='\0';
        }
        else
        {
            if(count>0)
            {
            tmp_ch1=str[i+1];
            str[i+1]=count+49;
            for(j=i+1;str[j]!='\0';j++)
            {
                tmp_ch2=str[j+1];
                str[j+1]=tmp_ch1;
                tmp_ch1=tmp_ch2;
            }
            str[j]='\0';
            printf("\nstr: %s",str);
            count=0;
            temp+=2;
            i+=2;
            }
            else
            {
                count=0;
                temp++;
                i++;
            }
        }
    }
    printf("\n%s",str);
}
*/

/*
//question 5:
int polindrom_comp(char * s);
void main()
{
    char * s[150];
    printf("enter a string: ");
    gets(s);
    printf("\nthe return is: %d",polindrom_comp(s));
}
int polindrom_comp(char * s)
{
  int * tmp=(int *)calloc(26,sizeof(int));
  int i,count=0;
  for(i=0;i<strlen(s);i++)
  {
      tmp[s[i]-97]++;
  }
  if(strlen(s)%2==0)
  {
      for(i=0;i<26;i++)
      {
          if(tmp[i]%2!=0)
          {
              return(0);
          }
      }
      return(1);
  }
  else
  {
       for(i=0;i<26;i++)
      {
          if(tmp[i]%2!=0)
          {
              count++;
          }
      }
      if(count>1)
      {
          return(0);
      }
      else
      {
        return(1);
      }
  }
}
*/



/*
//question 6:
#define SIZE 150
int polindrom_comp(char * s);
char * change_to_pal(char *s);
void main()
{
  char * s[SIZE];
    printf("enter a string: ");
    gets(s);
    char * b=change_to_pal(s);
    printf("\nthe return is: %s and the count is: %c",b,s[0]);
}
char * change_to_pal(char *s)
{
    char * b=calloc(SIZE,sizeof(char));
    int count_len=0;
    if(polindrom_comp(s)==1)
    {
        s[0]=count_len+48;
        return(b);
    }
    else
    {
        int * tmp=(int *)calloc(26,sizeof(int));
        int i,j=0,count_ezugi=0;
        for(i=0;i<strlen(s);i++)
            {
               tmp[s[i]-97]++;
            }
        for(i=0;i<26;i++)
            {
                 if(tmp[i]%2!=0&&count_ezugi>0)
                {
                  b[j]=i+97;
                  j++;
                  count_len++;
                }
                 if(tmp[i]%2!=0&&count_ezugi==0)
                {
                    count_ezugi++;
                }
            }
        s[0]=count_len+48;
        return(b);
    }
}
int polindrom_comp(char * s)
{
  int * tmp=(int *)calloc(26,sizeof(int));
  int i,count=0;
  for(i=0;i<strlen(s);i++)
  {
      tmp[s[i]-97]++;
  }
  if(strlen(s)%2==0)
  {
      for(i=0;i<26;i++)
      {
          if(tmp[i]%2!=0)
          {
              return(0);
          }
      }
      return(1);
  }
  else
  {
       for(i=0;i<26;i++)
      {
          if(tmp[i]%2!=0)
          {
              count++;
          }
      }
      if(count>1)
      {
          return(0);
      }
      else
      {
        return(1);
      }
  }
}
*/


/*
//question 7:
int compare(char * s1,char * s2);
void main()
{
    char * s1[150];
    char * s2[150];
    printf("enter a string: ");
    gets(s1);
    printf("\nenter another string: ");
    gets(s2);
    printf("\nthe return is: %d",compare(s1,s2));
}
int compare(char * s1,char * s2)
{
    int i;
    if(strlen(s1)!=strlen(s2))
    {
        return(0);
    }
    for(i=0;i<strlen(s1);i++)//changing letters to small letters
    {
           if(s1[i]<91)
            {
                s1[i]+=32;
            }
           if(s2[i]<91)
            {
                s2[i]+=32;
            }
    }
    if(strcmp(s1,s2)==0)
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
*/

/*
//question 8:
char * new_str(char * s,int index,int length);
void main()
{
    char * s1[150];
    printf("enter a string: ");
    gets(s1);
    int index,length;
    printf("\nenter index and length: ");
    scanf("%d%d",&index,&length);
    char * new_s=new_str(s1,index,length);
    printf("\nthe return is: %s",new_s);
}
char * new_str(char * s,int index,int length)
{
    char * ch=(char *)calloc(strlen(s),sizeof(char));
    if(strlen(s)<index+length)
    {
        return(NULL);
    }
    else
    {
        int i=0,sum=index+length;
        for(index;index<sum;index++)
        {
            ch[i]=s[index];
            i++;
        }
        return(ch);
    }
}
*/

/*
//question 9:
typedef char* verylong;
verylong input_long(void);
verylong add_verylong(verylong vl1, verylong vl2);
void main()
{
    verylong vl1,vl2,vlsum;
    vl1=input_long();
    vl2=input_long();
    vlsum=add_verylong(vl1,vl2);
    printf("\n%s + %s = %s",vl1,vl2,vlsum);
}
verylong add_verylong(verylong vl1, verylong vl2)
{
    int i=0,new_num1=0,new_num2=0,dig=0,sum,count=0,temp=0;
    while(vl1[i]!='\0')//changing string to number
    {
        new_num1*=10;
        dig=vl1[i]-48;
        new_num1+=dig;
        i++;
    }
    i=0;
    while(vl2[i]!='\0')//changing string to number
    {
        new_num2*=10;
        dig=vl2[i]-48;
        new_num2+=dig;
        i++;
    }
    sum=new_num2+new_num1;
    while(sum>0)//counting amount of digits and turning the number backwards
    {
        temp*=10;
        temp+=sum%10;
        count++;
        sum/=10;
    }
    verylong vlsum=(verylong)calloc(count,sizeof(verylong));
    for(i=0;i<count;i++)//adding the backwards sum to the string
    {
        vlsum[i]=(temp%10)+48;
        temp/=10;
    }
    return(vlsum);
}
verylong input_long(void)
{
char tempstr[80];
verylong longnum;
printf("enter long number\n");
gets(tempstr);
longnum=(verylong) malloc((strlen(tempstr)+1));
strcpy(longnum,tempstr);
return longnum;
}
*/











/*
//question 10:
char * change_str(char * s,char * ToRemove);
void main()
{
 char * s=(char *)malloc(150);
 printf("enter a string: ");
 gets(s);
 char * toRemove[150];
 printf("\nenter another string: ");
 gets(toRemove);
 s=change_str(s,toRemove);
 printf("\nthe new s is: %s ",s);
 free(s);
}
char * change_str(char * s,char * ToRemove)
{
    int * tmp_small=(int *)calloc(26,sizeof(int));
    int * tmp_big=(int *)calloc(26,sizeof(int));
    char * new_str=(char *)calloc(strlen(s),sizeof(char));
    int i,j=0;
    for(i=0;i<strlen(ToRemove);i++)
    {
        if(ToRemove[i]<91)
        {
            tmp_big[ToRemove[i]-65]++;
        }
        else
        {
            tmp_small[ToRemove[i]-97]++;
        }
    }
    for(i=0;i<26;i++)
    {
    }
     for(i=0;i<strlen(s);i++)
    {
        if(s[i]<91)
        {
            if(tmp_big[s[i]-65]==0)
            {
                new_str[j]=s[i];
                j++;
            }
        }
        else
        {
             if(tmp_small[s[i]-97]==0)
            {
                new_str[j]=s[i];
                j++;
            }
        }
    }
    s=new_str;
    free(tmp_small);
    free(tmp_big);
    return(s);
}
*/
