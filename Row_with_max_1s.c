#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int count(int *a,int n,int target)
{
    int ans=0;
  for(int i=0;i<n;i++)
  {
    if(a[i]==target)
    {
       ans++;
    }
  }
  return ans;
}
int solve(int **a,int m,int n)
{
    int c=count(a[0],n,1);
    int index=0;
    for(int i=1;i<m;i++)
    {
        if(c<count(a[i],n,1))
        {
            c=count(a[i],n,1);
            index=i;
        }
    }
    return index;
}


int main()
{
    int m,n;
    printf("enter the rows and cols\n");
    scanf("%d %d\n",&m,&n);
    int **matrix=(int **)malloc(m*sizeof(int *));
    for(int i=0;i<m;i++)
    {
      matrix[i]=(int *)malloc(n*sizeof(int));
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    int ans=solve(matrix,m,n);
    printf("%d",ans);
    printf("\n");
    return 0;
}