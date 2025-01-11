#include <stdio.h>
#include <stdlib.h>

int ** solve(int **a,int m,int n)
{
   int left=0;
   int right=n-1;
   int top=0;
   int bottom=m-1;
   int total=m*n;
   while(left<right)
   {
       int prev=a[left][left];
      for(int i=left;i<=right;i++)
      {  int temp;
         temp=a[top][i];
         a[top][i]=prev;
         prev=temp;
      }
      top++;
      for(int i=top;i<=bottom;i++)
      {  int temp;
         temp=a[i][right];
         a[i][right]=prev;
         prev=temp;
      }
      right--;
      for(int i=right;i>=left;i--)
      {  int temp;
         temp=a[bottom][i];
         a[bottom][i]=prev;
         prev=temp;
      }
      bottom--;
      for(int i=bottom;i>=left;i--)
      {  int temp;
         temp=a[i][left];
         a[i][left]=prev;
         prev=temp;
      }
      left++;
   }
   return a;
}

int main()
{
    int m;
    int n;
    printf("enter the rows and cols\n");
    scanf("%d %d",&m,&n);
    int **a=(int **)malloc(m*sizeof(int *));
    for(int i=0;i<m;i++)
    {
        a[i]=(int *)malloc(n*sizeof(int));
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int **ans=solve(a,m,n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}



