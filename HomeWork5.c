#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
/* //question 1:
int square(num);
int cube(num);
int power(num,pwr);
void main()
{
    int num,pwr;
    printf("enter a number: ");
    scanf("%d",&num);
    printf("enter the power: ");
    scanf("%d",&pwr);
    printf("\nsquare: %d \ncube: %d\npower:  %d",square(num),cube(num),power(num,pwr));
}
int square(num)
{
    return(num*num);
}
int cube(num)
{
    return(num*num*num);
}
int power(num,pwr)
{
    int i,sum=1;
    for(i=0;i<pwr;i++)
    {
        sum*=num;
    }
    return(sum);
}
*/
/*//question 2:
int IsEven(num);
int IsOdd(num);
void main()
{
    int num;
    printf("enter a number: ");
    scanf("%d",&num);
    printf("IsEven: %d \nIsOdd: %d",IsEven(num),IsOdd(num));
}
int IsEven(num)
{
    return((num+1)%2);
}
int IsOdd(num)
{
    return(((IsEven(num))+1)%2);
}
*/

/*//question3:
long change_num(digit);
void main()
{
    int digit;
    printf("enter a digit: ");
    scanf("%d",&digit);
    printf("the new number is : %d",change_num(digit));
}
long change_num(digit)
{
    int i;
    long new_num=0;
    for(i=0;i<digit;i++)
    {
        new_num*=10;
        new_num+=1;
    }
    return(new_num);
}
*/
/*
 //question 4:
int MyToLower(ch);
int MyToUpper(ch);
void main()
{
    char letter;
    printf("enter a letter: ");
    scanf(" %c",&letter);
    if(MyToLower(letter)==-1&&MyToUpper(letter)!=-1)
    {
        printf("MyToLower : %d \nMyToUpper : %c",MyToLower(letter),MyToUpper(letter));
    }
    if(MyToUpper(letter)==-1&&MyToLower(letter)!=-1)
    {
        printf("MyToLower : %c \nMyToUpper : %d",MyToLower(letter),MyToUpper(letter));
    }
    if(MyToUpper(letter)==-1&&MyToLower(letter)==-1)
    {
        printf("MyToLower : %d \nMyToUpper : %d",MyToLower(letter),MyToUpper(letter));
    }
}
int MyToLower(ch)
{
     signed char neg=-1;
    if(isupper(ch))
    {
        return(tolower(ch));
    }
    return(neg);
}
int MyToUpper(ch)
{
     signed char neg=-1;
    if(islower(ch))
    {
        return(toupper(ch));
    }
    return(neg);
}
*/
/* //question 5:
int change_to_int(ch1,ch2,ch3);
void main()
{
    char ch1,ch2,ch3;
    printf("enter three letters/digits: ");
    scanf(" %c %c %c",&ch1,&ch2,&ch3);
    printf("%d",change_to_int(ch1,ch2,ch3));
}
int change_to_int(ch1,ch2,ch3)
{
    int x,y,z;
    if(isdigit(ch1)&&isdigit(ch2)&&isdigit(ch3))
    {
        x=ch1-'0';
        y=ch2-'0';
        z=ch3-'0';
        return(x*100 + y*10 + z);
    }
    else
    {
        return(0);
    }
}
*/
/* //question 6:
int sum_divider(num1,num2);
void main()
{
    int num1,num2;
    printf("enter two numbers:  ");
    scanf("%d%d",&num1,&num2);
    printf("\nthe final sum is: %d",sum_divider(num1,num2));
}
int sum_divider(num1,num2)
{
    int sum=1,i,t;
    if(num1>=num2)
    {
        t=num1;
    }
    if(num2>num1)
    {
        t=num2;
    }
    for(i=2;i<=t;i++)
    {
        if(num1%i==0&&num2%i==0)
        {
            sum+=i;
        }
    }
    return(sum);
}
*/

/*
//question 7:
int isEvenOrNot(num1);
void main()
{
    int num1;
    printf("enter a number:   ");
    scanf("%d",&num1);
    printf("\n%d",isEvenOrNot(num1));
}
int isEvenOrNot(num1)
{
    int x=sqrt(num1);
    if(x*x==num1)
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
int check_min(num1);
void main()
{
    int num1;
    printf("enter a number:   ");
    scanf("%d",&num1);
    printf("\n%d",check_min(num1));
}
int check_min(num1)
{
    int i;
    for (i=2;i<=num1;i++)
    {
        if(num1%i==0)
        {
            return(i);
        }
    }
}
*/
/*
//question 9:
int check_max(num1);
void main()
{
    int num1;
    printf("enter a number:   ");
    scanf("%d",&num1);
    printf("\n%d",check_max(num1));
}
int check_max(num1)
{
    int i;
    for (i=num1-1;i>0;i--)
    {
        if(num1%i==0)
        {
            return(i);
        }
    }
}
*/
/*
//question 10:
int GCD(numerator,denominator);
void main()
{
    int numerator,denominator,x;
    printf("enter two numbers:  ");
    scanf("%d%d",&numerator,&denominator);
    if(denominator==0)
    {
        printf("can't divide by zero!");
    }
    else
    {
    x=GCD(numerator,denominator);
    printf("\n%d/%d = %d/%d",numerator,denominator,numerator/x,denominator/x);
    }
}
int GCD(numerator,denominator)
{
    int i,gcd_num=1;
    for (i=2;i<=numerator;i++)
    {
        if(numerator%i==0&&denominator%i==0)
        {
           gcd_num=i;
           printf("%d",gcd_num);
        }
    }
    return(gcd_num);
}
*/
/*
//question 11:
int LCM(num1,num2);
int big(num1,num2);
int small(num1,num2);
void main()
{
    int num1,num2;
    printf("enter two numbers:  ");
    scanf("%d%d",&num1,&num2);
    printf("\nthe LCM is: %d",LCM(num1,num2));
}
int LCM(num1,num2)
{
  int big_num=big(num1,num2),small_num=small(num1,num2);
  int small_temp=small_num,big_temp=big_num;
  while(big_num!=small_num)
  {
      if(big_num>small_num)
      {
       small_num+=small_temp;
      }
      if(small_num==big_num)
      {
          return(small_num);
      }
      if(small_num>big_num)
      {
          big_num+=big_temp;
      }
  }
}
int big(num1,num2)
{
 if(num1>=num2)
 {
     return(num1);
 }
 if(num1<num2)
 {
      return(num2);
 }
}
int small(num1,num2)
{
 if(num1>=num2)
 {
     return(num2);
 }
 if(num1<num2)
 {
      return(num1);
 }
}
*/
