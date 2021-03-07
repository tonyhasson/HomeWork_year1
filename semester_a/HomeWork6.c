#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

/*
//question 1:
int x_n(x,n);
void main()
{
    int x,n;
    printf("enter x and n: ");
    scanf("%d%d",&x,&n);
    printf("\nx^n= %d",x_n(x,n));
}
int x_n(x,n)
{
    int var;
    if(n==0)
    {
        return(1);
    }
    if(n%2==0)
    {
        var=0;
    }
    else
    {
        var=1;
    }
    return(x_n(x,n/2)*x_n(x,n/2)*pow(x,var));
}
*/

/*
//question 2:
int lucas(n); // recursive;
int lucas_b(n); // not recursive;
void main()
{
    int n;
    printf("enter n: ");
    scanf("%d",&n);
    printf("\nthe value of number is position %d is = %d",n,lucas(n));
    printf("\nthe value of number is position %d is = %d",n,lucas_b(n));
}
int lucas(n)
{
    if(n==0)
    {
        return(2);
    }
    else if (n==1)
    {
        return(1);
    }
    else
    {
        return(lucas(n-1)+lucas(n-2));
    }
}
int lucas_b(n)
{
    int i,sum=3,temp=1;
    if(n==0)
    {
        return(2);
    }
    else if(n==1)
    {
        return(1);
    }
    for(i=0;i<n-2;i++)
    {
        sum+=temp;
        temp=sum-temp;
    }
    return(sum);
}
*/
/*
//question 3:
int pal(n); // recursive
int pal_b(n);  // not recursive
void main()
{
     int n;
    printf("enter n: ");
    scanf("%d",&n);
    printf("\nthe value of number is position %d is = %d",n,pal(n));
    printf("\nthe value of number is position %d is = %d",n,pal_b(n));
}
int pal(n)
{
    if(n==0)
    {
        return(0);
    }
    else if(n==1)
    {
        return(1);
    }
    else
    {
        return(2*pal(n-1)+pal(n-2));
    }
}
int pal_b(n)
{
     int i,sum=1,temp=0,new_temp;
    if(n==0)
    {
        return(0);
    }
    else if(n==1)
    {
        return(1);
    }
    for(i=0;i<n-1;i++)
    {
        new_temp=sum;
        sum=2*sum+temp;
        temp=new_temp;
    }
    return(sum);
}
*/
/*
//question 4:
int EvenOdd(n);//recursive;
int EvenOdd_b(n);//not recursive;
void main()
{
     int n,i;
    printf("enter n: ");
    scanf("%d",&n);
    printf("\nthe value of number is position %d is = %d",n,EvenOdd(n));
    printf("\nthe value of number is position %d is = %d",n,EvenOdd_b(n));
}
int EvenOdd(n)
{
    if(n<=2)
    {
        return(1);
    }
    else
    {
        if(n%2==0)
        {
            return(EvenOdd(n-1)+EvenOdd(n-2)+EvenOdd(n-3));
        }
        else
        {
            return(EvenOdd(n-1)-EvenOdd(n-3));
        }
    }
}
int EvenOdd_b(n)
{
    int i,sum=1,temp=1;
    if(n<=2)
    {
        return(1);
    }
    if(n==3)
    {
        return(0);
    }
    if(n%2==1)
    {
        n-=5;
    }
    for(i=0;i<n-2;i+=2)
    {
        sum+=temp;
        temp=sum-temp;
    }
    return(sum);
}
*/
/*
//question 5:
int max(n);
void main()
{
    int n;
    printf("enter n: ");
    scanf("%d",&n);
    printf("the biggest number is : %d",max(n));
}
int max(n)
{
    int x,y;
    if(n==0)
    {
        return(0);
    }
    printf("enter a number: ");
    scanf("%d",&x);
    y=max(n-1);
    if(x>=y)
    {
        return(x);
    }
    else
    {
        return(y);
    }
}
*/

/*
//question 6:
int min(n);
void main()
{
    int n;
    printf("enter n: ");
    scanf("%d",&n);
    printf("the smallest number is : %d",min(n));
}
int min(n)
{
    int x,y;
    if(n==0)
    {
        return(-1);
    }
    printf("enter a number: ");
    scanf("%d",&x);
    y=min(n-1);
    if(y==-1)
    {
        return(x);
    }
    if(x<=y)
    {
        return(x);
    }
    else
    {
        return(y);
    }
}
*/
/*
//question 7:
int base2(num);
void main()
{
    int num;
    printf("enter num: ");
    scanf("%d",&num);
    printf("\n%d in base 2 is : %d",num,base2(num));
}
int base2(num)
{
    if(num==0)
    {
        printf("\n0");
        return(0);
    }
    else if(num==1)
    {
        printf("\n1");
        return(1);
    }
    else
    {
        int y=base2(num/2)*10+num%2;
        printf("\n%d  num:%d",y,num);
        return(y);
    }
}
*/
/*
//question 8:
void str(ch1,ch2,num);
void main()
{
    int num;
    char c1,c2;
    printf("enter num: ");
    scanf("%d",&num);
    printf("enter two letters: ");
    scanf(" %c %c",&c1,&c2);
    str(c1,c2,num);
}
void str(ch1,ch2,num)
{
    if(num>0)
    {
        printf("%c",ch1);
        str(ch1,ch2,num-1);
         printf("%c%c",ch2,ch2);
    }
}
*/
/*
//question 9:
int minus1(num);
int plus1(num);
void main()
{
    int num;
    printf("enter num: ");
    scanf("%d",&num);
    printf("\n minus one is : %d",minus1(num));
    printf("\n plus one is : %d",plus1(num));
}
int minus1(num)
{
    if(num<10&&num>=0)
    {
        return((num+9)%10);
    }
    return((minus1(num/10))*10+(minus1(num%10)));
}
int plus1(num)
{
    if(num<10&&num>=0)
    {
        return((num+1)%10);
    }
    return((plus1(num/10))*10+(plus1(num%10)));
}
*/


//question 10:
/*
int zugi_or_not(num);
void main()
{
    int num;
    printf("enter num: ");
    scanf("%d",&num);
    printf("\n zugi or not : %d",zugi_or_not(num));
}
int zugi_or_not(num)
{
   if(num<10)
   {
     if(num%2==0)
     {
       return(1);
     }
     else
     {
       return(0);
     }
   }
   else
   {
       int x;
       x=(zugi_or_not(num%10)-1+zugi_or_not(num/10)-1);
       if(x%2==0)
       {
           return(1);
       }
       else
       {
           return(0);
       }
   }
}
*/

/*
//question 11:
int sequel(num);
void main()
{
  int num;
    printf("enter num: ");
    scanf("%d",&num);
    printf("\n sequel or not : %d",sequel(num));
}
int sequel(num)
{
    if(num<10)
   {
     if(num%2==0)
     {
       return(1);
     }
     else
     {
       return(0);
     }
   }
   else
   {
       if((sequel(num%10)-1)%2==0&&(sequel(num/10)-1)%2!=0&&(sequel(num/100)-1)%2==0)
       {
            return(1);
       }
       else
       {
           return(0);
       }
   }
}
*/

/*
//question 12:
int switchable(num);
void main()
{
    int num;
    printf("enter number:");
    scanf("%d",&num);
    printf("switchable or not: %d",switchable(num));
}
int switchable(num)
{
  if(num<10)
  {
      return(1);
  }
   int x,y;
   x=num%10;
   y=(num%100)/10;
  if(x%2==0 && y%2!=0 || x%2!=0 && y%2==0)
  {
      switchable(num/10);
  }
  else
  {
      return(0);
  }
}
*/
