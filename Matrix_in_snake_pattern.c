#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int * solve(int **a,int m,int n)
{
    int index=0;
   int *ans=(int *)malloc(m*n*sizeof(int));
   for(int i=0;i<m;i++)
   {
    if(i%2==0)
    {
        for(int j=0;j<n;j++)
        {
            ans[index++]=a[i][j];
        }
    }
    else{
        for(int j=n-1;j>=0;j--)
        {
            ans[index++]=a[i][j];
        }
    }
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
    for(int i=0;i<m*n;i++)
    {
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}