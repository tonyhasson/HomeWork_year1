#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>


/*

//question 1:

int find_miss(int *a,int n);
void input_arr(int *a,int n);
void main()
{
 int n;
 printf("enter n: ");
 scanf_s("%d",&n);
 int * a=(int *)calloc(n,sizeof(int));
 input_arr(a,n);
 printf("\nthe missing number is: %d",find_miss(a,n));
 free(a);
}
void input_arr(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter number to array: ");
        scanf_s("%d",&a[i]);
    }
}
int find_miss(int *a,int n)
{
    int i,temp=0;
    for(i=0;i<n;i++)
    {
        temp+=i-a[i];
    }
    temp+=n;
    return(temp);

}


*/







/*

//question 2:



int find_miss(int *a,int n);
void input_arr(int *a,int n);
void main()
{
 int n;
 printf("enter n: ");
 scanf_s("%d",&n);
 int * a=(int *)calloc(n,sizeof(int));
 input_arr(a,n);
 printf("\nthe missing number is: %d",find_miss(a,n));
 free(a);
}
void input_arr(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter number to array: ");
        scanf_s("%d",&a[i]);
    }
}
int find_miss(int *a,int n)
{
    int high=n-1,low=0,mid,temp;

    while(high>=low)
    {
        mid=(high+low)/2;
        if(a[mid]>mid)
        {
            temp=mid;
            high=mid-1;
        }
        if(a[mid]<=mid)
        {
            low=mid+1;
        }
    }
    return(temp);


}


*/




/*




//question 3:


int find_pair(int *a,int k,int key);
void input_arr(int *a,int n);
void main()
{
 int k,key;
 printf("enter k: ");
 scanf_s("%d",&k);
  printf("enter key: ");
 scanf_s("%d",&key);
 int * a=(int *)calloc(k*2,sizeof(int));
 input_arr(a,k*2);
 printf("\nthe position of the pair is: %d",find_pair(a,k,key));
 free(a);
}
void input_arr(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter number to array: ");
        scanf_s("%d",&a[i]);

    }
}
int find_pair(int *a,int k,int key)
{
    int high=k*2-1,low=0,mid,count=1;

    while(high>=low)
    {
        printf("\ncount of times in loop: %d",count);//to show that the function is log n
        mid=(high+low)/2;
        if(mid%2!=0)
        {
            mid-=1;
        }
        if(k>=2&&count==1)
        {
            if(a[mid+2]+a[mid+3]==key)
            {
                return((mid+2)/2);
            }
            if(a[mid]+a[mid+1]==key)
            {

                return(mid/2);
            }
            if(a[mid+2]+a[mid+3]<key)
            {
                low=mid+4;
            }
            if(a[mid]+a[mid+1]>key)
            {
                high=mid-2;
            }

        }
        if(count>1||k<2)
        {


            if(a[mid]+a[mid+1]==key)
            {

                return(mid/2);
            }
            else if(a[mid]+a[mid+1]<key)
            {
                low=mid+2;
            }
            else
            {
                high=mid-2;
            }
        }
        count++;
    }
    return(-1);


}


*/


/*



//question 4:


int lowest_sub(int *a,int n,int k);
void input_arr(int *a,int n);
void main()
{
 int n,k;
 printf("enter n: ");
 scanf_s("%d",&n);
  printf("enter k: ");
 scanf_s("%d",&k);
 int * a=(int *)calloc(n,sizeof(int));
 input_arr(a,n);
 printf("\nthe lowest sub is : %d",lowest_sub(a,n,k));
 free(a);
}
void input_arr(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter number to array: ");
        scanf_s("%d",&a[i]);

    }
}
int lowest_sub(int *a,int n,int k)
{
    int high=n-1,low=0,mid,min=k,temp,pos;
    while(high>=low)
    {
        mid=(high+low)/2;
        temp=k-a[mid];
            if(temp<0)
            {
                temp*=-1;
            }
            if(temp<min)
            {
                min=temp;
                pos=mid;
            }
        if(k>a[mid])
        {
           low=mid+1;
        }
        else if(k<a[mid])
        {
            high=mid-1;
        }
    }

    return(a[pos]);
}

*/






/*



//question 5:



int find_pos(int *a,int n);
void input_arr(int *a,int n);
void main()
{
 int n;
 printf("enter n: ");
 scanf_s("%d",&n);
 int * a=(int *)calloc(n,sizeof(int));
 input_arr(a,n);
 printf("\nthe position of smallest number is : %d",find_pos(a,n));
 free(a);
}
void input_arr(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter number to array: ");
        scanf_s("%d",&a[i]);

    }
}
int find_pos(int *a,int n)
{
    int high=n-1,low=0,mid,temp_pos=a[0];
    while(high>=low)
    {
        mid=(high+low)/2;
        if(a[mid]<a[mid+1]&&a[mid]<a[mid-1])
        {
            return(mid);
        }
        if(a[mid]>a[mid+1]&&a[mid]>a[mid-1])
        {
            return(mid+1);
        }
        if(a[mid]<temp_pos)
        {
            high=mid-1;
        }
        else if(a[mid]>temp_pos)
        {
            low=mid+1;
            temp_pos=a[mid];
        }

    }

}


*/






/*



//question 6:

int find_zero_sum(int *pos,int *neg,int n);
void input_arr(int *a,int n);
void main()
{
 int n;
 printf("enter n: ");
 scanf_s("%d",&n);
 int * a=(int *)calloc(n,sizeof(int));
 int * b=(int *)calloc(n,sizeof(int));
 printf("\nenter positive array:");
 input_arr(a,n);
 printf("\nenter negative array:");
 input_arr(b,n);
 int res=find_zero_sum(a,b,n);
 printf("\n has zero sum: %d,the positions: %d ,%d",res,a[0],b[0]);
 free(a);
 free(b);
}
void input_arr(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter number to array: ");
        scanf_s("%d",&a[i]);

    }
}
int find_zero_sum(int *pos,int *neg,int n)
{
    int i=n-1,j=0,x=0,y=n-1;
    while(n>0)
    {
        if(pos[i]+neg[j]>0)
        {
            i--;
        }
        else if(pos[i]+neg[j]<0)
        {
            j++;
        }

        else if(pos[i]+neg[j]==0)
        {
            pos[0]=i;
            neg[0]=j;
            return(1);
        }


        if(pos[x]+neg[y]>0)
        {
            y--;
        }
        else if(pos[x]+neg[y]<0)
        {
            x++;
        }

        else if(pos[x]+neg[y]==0)
        {
            pos[0]=x;
            neg[0]=y;
            return(1);
        }
        n--;
    }

    pos[0]=-1;
    neg[0]=-1;
    return(0);


}



*/





/*


//question 7:  // didn't understand how log t works in the explanations


int find_t(int *a,int n);
void input_arr(int *a,int n);
void main()
{
 int n;
 printf("enter n: ");
 scanf_s("%d",&n);
 int * a=(int *)calloc(n,sizeof(int));
 input_arr(a,n);
 printf("\nthe amount of t is : %d",find_t(a,n));
 free(a);
}
void input_arr(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter number to array: ");
        scanf_s("%d",&a[i]);

    }
}
int find_t(int *a,int n)
{
    int high=n-1,low=0,mid,count=0,ins=1;
    while(high>low)
    {
        printf("\ninside:%d",ins);
        mid=(high+low)/2;
        if(a[high]==1)
        {
            return(high+1);
        }
        if(a[low]==0)
        {
            printf("\nhaha");
            return(count);
        }
        if(a[high]==0&&a[mid]==0  &&a[low]!=0)
        {
            high=mid-1;
        }
        if(a[high]==0&&a[mid]==1)
        {
            count=mid+1;
            low=mid+1;
        }



        ins++;
    }
    if(high==low)
    {
        if(a[high]==1)
        {
            count++;
        }
    }
    return(count);

}


*/






/*

//question 8:




int find_d_pos(int *a,int n,int d);
void input_arr(int *a,int n);
void main()
{
 int n,d;
 printf("enter n: ");
 scanf_s("%d",&n);
 printf("enter d: ");
 scanf_s("%d",&d);
 int * a=(int *)calloc(n,sizeof(int));
 input_arr(a,n);
 printf("\nthe pos of d is : %d",find_d_pos(a,n,d));
 free(a);
}
void input_arr(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter number to array: ");
        scanf_s("%d",&a[i]);

    }
}
int find_d_pos(int *a,int n,int d)
{
    int high=n-2,low=0,mid,inside=1;

    while(high>=low)
    {

        mid=(high+low)/2;
        if(a[mid+1]-a[mid]==d)
        {
            return((2*mid+1)/2);
        }
        else if(a[mid+1]-a[mid]>d)
        {
            high=mid-1;
        }
        else if(a[mid+1]-a[mid]<d)
        {
            low=mid+1;
        }

    }
    return(-1);

}



*/




/*





//question 9:


int find_missing_num(int *a,int *b,int n);
void input_arr(int *a,int n);
void main()
{
 int n;
 printf("enter n: ");
 scanf_s("%d",&n);
 printf("\nenter array b: ");
 int * b=(int *)calloc(n+1,sizeof(int));
 input_arr(b,n+1);
  printf("\nenter array a: ");
 int * a=(int *)calloc(n,sizeof(int));
 input_arr(a,n);
 printf("\nthe missing number is : %d",find_missing_num(a,b,n));
 free(a);
 free(b);
}
void input_arr(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter number to array: ");
        scanf_s("%d",&a[i]);

    }
}
int find_missing_num(int *a,int *b,int n)
{
    int high=n-1,low=0,mid,inside=1;
    while(high>=low)
    {
        printf("\ninside :%d",inside);
        mid=(high+low)/2;
        if(a[mid]==b[mid]&&a[mid+1]==b[mid+1])
        {
            low=mid+1;
        }
        else if(a[mid]!=b[mid]&&a[mid]==b[mid+1])
        {
            high=mid-1;
        }
        else if(a[mid]==b[mid]&&a[mid]!=b[mid+1])
        {
                return(b[mid+1]);
        }
        inside++;
    }
}




*/


/*

//question 10:


int count_x(int *a,int n,int x);
void input_arr(int *a,int n);
void main()
{
 int n,x;
 printf("enter n: ");
 scanf_s("%d",&n);
 printf("enter x: ");
 scanf_s("%d",&x);
 int * a=(int *)calloc(n,sizeof(int));
 input_arr(a,n);
 printf("\nthe amount of x is : %d",count_x(a,n,x));
 free(a);

}
void input_arr(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nenter number to array: ");
        scanf_s("%d",&a[i]);

    }
}
int count_x(int *a,int n,int x)
{
    int high1=n-1,low1=0,mid1,high2=n-1,low2=0,mid2,first=-1,last=-1;
   while(first==-1||last==-1)
   {


    if(first==-1)//searching for the first occurrence of x;
    {
        if(high1<low1)
        {
            first=-2;
        }
        mid1=(high1+low1)/2;
        if(a[mid1]==x&&a[mid1-1]!=x)
        {
            first=mid1;
        }
        if(a[mid1]==x&&a[mid1-1]==x)
        {
            high1=mid1-1;
        }
        if(a[mid1]>x)
        {

            high1=mid1-1;
        }
        if(a[mid1]<x)
        {
            low1=mid1+1;
        }
    }


    if(last==-1)//searching for the last occurrence of x;
    {
        if(high2<low2)
        {
            last=-2;
        }
        mid2=(high2+low2)/2;
        if(a[mid2]==x&&a[mid2+1]!=x)
        {
            last=mid2;
        }
        if(a[mid2]==x&&a[mid2+1]==x)
        {
            low2=mid2+1;
        }
        if(a[mid2]>x)
        {

            high2=mid2-1;
        }
        if(a[mid2]<x)
        {
            low2=mid2+1;
        }
    }

   }
    if(last+first==-4)
    {
        return(0);
    }
    return(last-first+1);
}


*/
