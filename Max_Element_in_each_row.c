#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int max(int *a,int size)
{
  int max=INT_MIN;
  for(int i=0;i<size;i++)
  {
    if(max<a[i])
    {
        max=a[i];
    }
  }
  return max;
}
int * solve(int **a,int m,int n)
{
   int *ans=(int *)malloc(m*sizeof(int));
   for(int i=0;i<m;i++)
   {
     ans[i]=max(a[i],n);
   }
   return ans;
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
    int *ans=solve(a,m,n);
    for(int i=0;i<m;i++)
    {
        printf("%d ",ans[i]);
        printf("\n");
    }
    printf("\n");
    return 0;
}

