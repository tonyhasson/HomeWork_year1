#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

/*
//question 1:
void swap(int *pt1,int *pt2,int *pt3);
void main()
{
    int num1,num2,num3;
    int *pt1,*pt2,*pt3;
    printf("enter three numbers: ");
    scanf("%d%d%d",&num1,&num2,&num3);
    pt1=&num1;
    pt2=&num2;
    pt3=&num3;
    swap(pt1,pt2,pt3);
    printf("\n num1: %d num2: %d num3 :  %d",num1,num2,num3);
}
void swap(int *pt1,int *pt2,int *pt3)
{
    int max=0,min=*pt1,i,a[]={*pt1,*pt2,*pt3};
    for(i=0;i<3;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
        if(a[i]<min)
        {
            min=a[i];
        }
    }
    *pt1=max;
    *pt3=min;
}
*/

/*
//question 2:
double check(int *digit,int num);
void main()
{
    int num,digit;
    printf("enter number and digit: ");
    scanf("%d%d",&num,&digit);
    printf("\n the amount of number: %d,the avrage: %lf",digit,check(&digit,num));
}
double check(int *digit,int num)
{
    int dig=*digit;
    double avg,sum=0,count=0;
    if(num!=0)
    {
        if(num<0)
        {
            num*=-1;
        }
     while (num>0)
       {
            if(num%10<dig)
            {
                sum+=num%10;
                count++;
            }
            num/=10;
        }
        *digit=count;
        if(count>0)
        {
            avg=(sum/count);
        }
        else
        {
            avg=0;
        }
        return(avg);
    }
    if(num==0)
    {
        if(num<dig)
        {
            *digit=1;
            return(0);
        }
        else
        {
            *digit=0;
            return(0);
        }
    }
}
*/

/*
/question 3:
double nigzeret(double *c,double *n,double x);
void main()
{
    double c,n,x,temp_c,temp_n;
    printf("enter c n and x:  ");
    scanf("%lf%lf%lf",&c,&n,&x);
    temp_c=c;
    temp_n=n;
    printf("\n (%lfx^%lf)' when x is:%lf is: %lf ",temp_c,temp_n,x,nigzeret(&c,&n,x));
}
double nigzeret(double *c,double *n,double x)
{
    *c *= *n;
    *n -= 1;
    return(*c*pow(x,*n));
}
*/

/*
//question 4:
void input_arry(int *a,int n);
int biggest_pair(int *a,int n);
void main()
{
    int n;
    printf("enter n:");
    scanf("%d",&n);
    int a[n];
    input_arry(a,n);
    printf("\nthe biggest pair : %d",biggest_pair(a,n));
}
int biggest_pair(int *a,int n)
{
    int i,sum=a[0]+a[1];
    for(i=0;i<n-1;i++)
    {
        if(a[i]+a[i+1]>sum)
        {
            sum=a[i]+a[i+1];
        }
    }
    return(sum);
}
void input_arry(int *a,int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("\nenter a[%d]: ",i);
        scanf("%d",&a[i]);
    }
}
*/


/*
//question 5:
int check_key(int *a,int *n,int *key);
void input_arry(int *a,int n);
void main()
{
    int n,key,res;
    printf("enter n and key:");
    scanf("%d%d",&n,&key);
    int a[n];
    input_arry(a,n);
    res=check_key(a,&n,&key);
    printf("\nreturn:%d  %d   %d  ",res,key,n);
}
void input_arry(int *a,int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("\nenter a[%d]: ",i);
        scanf("%d",&a[i]);
    }
}
int check_key(int *a,int *n,int *key)
{
    int i,j;
    for(j=0;j<*n;j++)
    {
        for(i=0;i<*n;i++)
        {
            if(i!=j)
            {
                if(a[i]+a[j]<*key)
                {
                    printf("\nkey:%d n:%d ",*key,*n);
                    *key=a[i];
                    *n=a[j];
                    printf("\nkey:%d n:%d ",*key,*n);
                    return(1);
                }
            }
        }
    }
    *key=-1;
    *n=-1;
    return(0);
}
*/

/*
//question 6:
void input_arry(int *a,int n);
void maxmax(int *a, int n, int *max_even, int *even, int *max_odd, int *odd);
void main()
{
    int n,max_even,max_odd,even,odd;
    printf("enter n:");
    scanf("%d",&n);
    int a[n];
    input_arry(a,n);
    maxmax(a,n,&max_even,&even,&max_odd,&odd);
    printf("\nmax even: %d \nmax odd: %d \neven : %d \nodd: %d",max_even,max_odd,even,odd);
}
void input_arry(int *a,int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("\nenter a[%d]: ",i);
        scanf("%d",&a[i]);
    }
}
void maxmax(int *a, int n, int *max_even, int *even, int *max_odd, int *odd)
{
    *even=0,*odd=0,*max_odd=0,*max_even=0;
    int i,count_even=0,count_odd=0;
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            count_even++;
            if(a[i]>*max_even)
            {
                *max_even=a[i];
            }
        }
        else
        {
            count_odd++;
            if(a[i]>*max_odd)
            {
                *max_odd=a[i];
            }
        }
    }
    if(count_even>0)
    {
        *even=1;
    }
     if(count_odd>0)
    {
        *odd=1;
    }
}
*/


/*
//question 7:
int recursive(int *a,int n);
int itiretive(int *a,int n);
void input_arry(int *a,int n);
void main()
{
    int n;
    printf("enter n: ");
    scanf("%d",&n);
    int a[n];
    input_arry(a,n);
    printf("\nreturn:%d  ",recursive(a,n));
    printf("\nreturn:%d  ",itiretive(a,n));
}
void input_arry(int *a,int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("\nenter a[%d]: ",i);
        scanf("%d",&a[i]);
    }
}
int recursive(int *a,int n)
{
 if(n<=1)
 {
     return(1);
 }
 else
 {
     
     if(a[0]!=a[n-1])
     {
         return(0);
     }
     else
     {
         return(recursive(a+1,n-2));
     }
 }
int itiretive(int *a,int n)
{
    int i,new_n;
    if(n%2==0)
    {
        new_n=(n/2) -1;
    }
    else
    {
        new_n=n/2;
    }
    for(i=0;i<=new_n;i++)
    {
        if(a[i]!=a[n-1-i])
        {
            return(0);
        }
    }
    return(1);
}
*/

/*
//question 8:
void print_opos(int *a,int n);
void print_same(int *a,int n);
void input_arry(int *a,int n);
void main()
{
    int n;
    printf("enter n: ");
    scanf("%d",&n);
    int a[n];
    input_arry(a,n);
    print_opos(a,n);
    printf("\n\n");
    print_same(a,n);
}
void input_arry(int *a,int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("\nenter a[%d]: ",i);
        scanf("%d",&a[i]);
    }
}
void print_opos(int *a,int n)
{
   if(n>0)
    {
    printf("\na[%d]=%d",n-1,a[n-1]);
    print_opos(a,n-1);
    }
}
void print_same(int *a,int n)
{
     if(n>0)
    {
    printf("\n%d",a[0]);
    print_same(a+1,n-1);
    }
}
*/


/*
//question 9:
double findAvg(int *a,int n);
void input_arry(int *a,int n);
void main()
{
    int n;
    printf("enter n: ");
    scanf("%d",&n);
    int a[n];
    input_arry(a,n);
    printf("the avrage is: %lf",findAvg(a,n));
}
void input_arry(int *a,int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("\nenter a[%d]: ",i);
        scanf("%d",&a[i]);
    }
}
double findAvg(int *a,int n)
{
    double sum,avg;
    if(n==1)
    {
        sum=a[0];
    }
    else
    {
       
        sum= a[n-1]+ (n-1) * findAvg(a,n-1);
    }
    avg = sum/n;
    return avg;
}
*/



/*
//question 10:
int recursive(double *a,int n);
void input_arry(double *a,int n);
void main()
{
    int n;
    printf("enter n: ");
    scanf("%d",&n);
    double a[n];
    input_arry(a,n);
    printf("\nreturn is: %d",recursive(a,n));
}
void input_arry(double *a,int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("\nenter a[%d]: ",i);
        scanf("%lf",&a[i]);
    }
}
int recursive(double *a,int n)
{
    if(n==1)
    {
        return(1);
    }
    else
    {
        double ls1=floor(a[n-1]),ls2=floor(a[n-2]),rs1=a[n-1]-ls1,rs2=a[n-2]-floor(a[n-2]);
        if( ls1 < ls2 || rs1 > rs2)
        {
            return(0);
        }
        else
        {
            recursive(a,n-1);
        }
    }
}
*/

/*
//question 11:
int recursive(int *a,int n);
int itiretive(int *a,int n);
void input_arry(int *a,int n);
void main()
{
    int n;
    printf("enter n: ");
    scanf("%d",&n);
    int a[n];
    input_arry(a,n);
    printf("\nthe return in itiretive is: %d",itiretive(a,n));
    printf("\nthe return in recursive is: %d",recursive(a,n));
}
void input_arry(int *a,int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("\nenter a[%d]: ",i);
        scanf("%d",&a[i]);
    }
}
int recursive(int *a,int n)
{
 if(n==1)
 {
     return(1);
 }
 else
 {
     if(a[0]<a[1])
     {
         a[1]+=a[0];
         recursive(a+1,n-1);
     }
     else
     {
         return(0);
     }
 }
}
int itiretive(int *a,int n)
{
 int i;
 for(i=0;i<n-1;i++)
 {
     if(a[i]<a[i+1])
     {
         a[i+1]+=a[i];
     }
     else
     {
         return(0);
     }
 }
 return(1);
}
*/
