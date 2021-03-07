#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>


/*
//question 1:
int * lucas(int n);
void main()
{
    int n,i;
    printf("enter n: ");
    scanf("%d",&n);
    int * arr=lucas(n);
    for(i=0;i<n+1;i++)//printing just to show it works.
    {
        printf("\narr[%d]=%d",i,arr[i]);
    }
    free(arr);
}
int * lucas(int n)
{
    int i;
    int * a=(int *)calloc(n+1,sizeof(int));
    if(a==NULL)
    {
        printf("\nerror!");
        exit(1);
    }
    for(i=0;i<n+1;i++)
    {
        if(i<1)
        {
            a[i]=2;
        }
        else if(i==1)
        {
            a[i]=1;
        }
        else
        {
            a[i]=a[i-1]+a[i-2];
        }
    }
    return(a);
}
*/




/*
//question 2:
void input_array(int *a,int n);
int * change_array(int IsEven,int *a,int *n);
void main()
{
   int n,i,IsEven;
   printf("enter n: ");
   scanf("%d",&n);
   int * a[n];
   input_array(a,n);
   printf("\nenter IsEven: ");
   scanf("%d",&IsEven);
   int *t = change_array(IsEven,a,&n);
   printf("\nthe new array is: ");
   for(i=0;i<n;i++)
   {
       printf("\n%d",t[i]);
   }
   free(t);
}
void input_array(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter a number to array: ");
        scanf("%d",&a[i]);
    }
}
int * change_array(int IsEven,int *a,int *n)
{
    int i,len=*n,count=0;
    int * t=(int *)calloc(n,sizeof(int));
    if(t==NULL)
    {
        printf("\nerror!");
        exit(1);
    }
    if(IsEven==1)//checking for even numbers
    {
        for(i=0;i<len;i++)
        {
            if(a[i]%2==0)
            {
                t[count]=a[i];
                count++;
            }
        }
    }
    else//checking for odd numbers
    {
        for(i=0;i<len;i++)
        {
            if(a[i]%2)
            {
                t[count]=a[i];
                count++;
            }
        }
    }
    realloc(t,count);
    *n=count;
    return(t);
}
*/


/*
//question 3:
int * mult_vec(int *a,int *b);
void input_array(int *a,int n);
void main()
{
   int * a[3],*b[3];
   printf("\n array a:");
   input_array(a,3);
   printf("\n array b:");
   input_array(b,3);
   int *c=mult_vec(a,b);
   printf("\nanswer is:{%d,%d,%d}",c[0],c[1],c[2]);
   free(c);
}
void input_array(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter a number to array: ");
        scanf("%d",&a[i]);
    }
}
int * mult_vec(int *a,int *b)
{
    int *c=(int *)calloc(3,sizeof(int));
    if(c==NULL)
    {
        printf("error!");
        exit(1);
    }
    c[0]=a[1]*b[2]- a[2]*b[1];
    c[1]=a[2]*b[0]-a[0]*b[2];
    c[2]=a[0]*b[1]-a[1]*b[0];
    return(c);
}
*/

/*
//question 4:
int *func(int * arr,int n);
void input_array(int *a,int n);
void main()
{
   int n,i;
   printf("enter n: ");
   scanf("%d",&n);
   int * a[n],*t;
   input_array(a,n);
   t=func(a,n);
   printf("\nthe new array: ");//check here for problem.
    for(i=0;i<n;i++)
   {
       a[i]=t[i];
       printf("\n%d",a[i]);
   }
   free(t);
}
void input_array(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter a number to array: ");
        scanf("%d",&a[i]);
    }
}
int * func(int * arr,int n)
{
    int b,temp,i;
    int * t=(int *)calloc(n,sizeof(int));
    if(t==NULL)
    {
        printf("error!");
        exit(1);
    }
    for(i=0;i<n;i++)
    {
        t[i]=1;//so you won't multiply by zero;
        temp=i;//wanted position of t array;
        b=0;//temporary index to run on;
        while(b<n)
        {
            if(b!=temp)
            {
                t[temp]*=arr[b];
            }
            b++;
        }
    }
    return(t);
}
*/


/*
question 5:
int * missing_digits(int *a,int * n);
void input_array(int *a,int n);
void main()
{
   int n,i;
   printf("enter n: ");
   scanf("%d",&n);
   int * a[n],*t;
   input_array(a,n);
   t=missing_digits(a, &n);
   for(i=0;i<n;i++)
   {
       printf("\n%d",t[i]);
   }
   free(t);
}
void input_array(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter a number to array: ");
        scanf("%d",&a[i]);
    }
}
int * missing_digits(int *a,int *n)
{
    if(*n==0)
    {
        *n=1;
        int * t=(int *)calloc(1,sizeof(int));
        return(t);
    }
    else
    {
    int i,count=0,len=*n+1;
    int * t=(int *)calloc(n+1,sizeof(int));
    if(t==NULL)
    {
        printf("error!");
        exit(1);
    }
    for(i=0;i<len;i++)
    {
        t[a[i]]++;
    }
     for(i=0;i<len;i++)
    {
        if(t[i]==0)
        {
            t[count]=i;
            count++;
        }
    }
    realloc(t,count);
    *n=count;
    return(t);
    }
}
*/

/*
//question 6:
int  is_big(int *a,int  n);
void input_array(int *a,int n);
void main()
{
   int n;
   printf("enter n: ");
   scanf("%d",&n);
   int a[n];
   input_array(a,n);
   printf("\nreturn : %d",is_big(a,n));
}
void input_array(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter a number to array: ");
        scanf("%d",&a[i]);
    }
}
int  is_big(int *a,int n)
{
    int i,count=0;
    int * t=(int *)calloc(n+1,sizeof(int));
    if(t==NULL)
    {
        printf("error!");
        exit(1);
    }
    for(i=0;i<n;i++)
    {
        t[a[i]]++;
    }
     for(i=0;i<n+1;i++)
    {
        if(t[i]>n/2)
        {
            free(t);
            return(1);
        }
    }
    free(t);
    return(-1);
}
*/


/*
//question 7:
int  biggest_sum(int *a,int  n);
void input_array(int *a,int n);
void main()
{
   int n;
   printf("enter n: ");
   scanf("%d",&n);
   int a[n];
   input_array(a,n);
   printf("\nreturn : %d",biggest_sum(a,n));
}
void input_array(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter a number to array: ");
        scanf("%d",&a[i]);
    }
}
int  biggest_sum(int *a,int n)
{
    int i,count=0,temp_i=0;
    int * t=(int *)calloc(n+1,sizeof(int));
    if(t==NULL)
    {
        printf("error!");
        exit(1);
    }
    for(i=0;i<n;i++)
    {
        t[a[i]]+=a[i];
        if(i>0)
        {
            if(t[a[i]]>t[a[temp_i]])
            {
                temp_i=i;
            }
            else if(t[a[i]]==t[a[temp_i]])
            {
                if(a[i]>a[temp_i])
                {
                    temp_i=i;
                }
            }
        }
    }
    temp_i=a[temp_i];
    free(t);
    return(temp_i);
}
*/


/*
//question 8:
int  biggest_missing(int *a,int  n);
void input_array(int *a,int n);
void main()
{
   int n;
   printf("enter n: ");
   scanf("%d",&n);
   int a[n];
   input_array(a,n);
   printf("\nreturn : %d",biggest_missing(a,n));
}
void input_array(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter a number to array: ");
        scanf("%d",&a[i]);
    }
}
int  biggest_missing(int *a,int n)
{
    int i,count=0,temp_i=n,save=0;
    int * t=(int *)calloc(n+1,sizeof(int));
    if(t==NULL)
    {
        printf("error!");
        exit(1);
    }
    for(i=0;i<n;i++)
    {
        t[a[i]]+=1;
        if(a[i]<temp_i)
        {
            save++;
        }
        else if(a[i]==temp_i)
        {
            temp_i=temp_i-save-1;
            save=0;
        }
    }
    free(t);
    return(temp_i);
}
*/


/*
//question 9:
void  switch_array(int *a,int  n,int amount);
void input_array(int *a,int n);
void main()
{
   int n,amount,i;
   printf("enter n and amount: ");
   scanf("%d%d",&n,&amount);
   int a[n];
   input_array(a,n);
   switch_array(a,n,amount);
   printf("\nthe new array:");
   for(i=0;i<n;i++)
   {
       printf("\n%d",a[i]);
   }
}
void input_array(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter a number to array: ");
        scanf("%d",&a[i]);
    }
}
void switch_array(int *a,int n,int amount)
{
    int i,temp1,temp2;
    while(amount>0)
    {
        temp1=0;
        temp2=0;
        for(i=0;i<n;i++)
        {
            if(i==0)
            {
                temp1=a[i];
                a[i]=a[n-1];
            }
            else
            {
                temp2=a[i];
                a[i]=temp1;
                temp1=temp2;
            }
        }
        amount--;
    }
}
*/


/*
//question 10:
void  next_max(int *a,int  n);
void input_array(int *a,int n);
void main()
{
   int n,i;
   printf("enter n: ");
   scanf("%d",&n);
   int a[n];
   input_array(a,n);
   next_max(a,n);
   printf("\nthe new array:");
   for(i=0;i<n;i++)
   {
       printf("\n%d",a[i]);
   }
}
void input_array(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter a number to array: ");
        scanf("%d",&a[i]);
    }
}
void next_max(int *a,int n)
{
    int i,j,temp_amount;
    for(i=0;i<n;i++)
    {
        temp_amount=a[i];
        j=i+1;
        while(j<n)
        {
            if(a[i]<a[j])
            {
                a[i]=a[j];
                j=n;
            }
            j++;
        }
        if(temp_amount==a[i])
        {
            a[i]=-1;
        }
    }
}
*/
