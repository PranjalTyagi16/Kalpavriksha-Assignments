#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int *solve(int **a,int m,int n)
{
    int principal_diagonal_sum=0;
    int secondary_diagonal_sum=0;
    for(int i=0;i<m;i++)
    {
       principal_diagonal_sum+=a[i][i];
       secondary_diagonal_sum+=a[i][n-i-1];
    }
    int *ans=(int *)malloc(2*sizeof(int));
    ans[0]=principal_diagonal_sum;
    ans[1]=secondary_diagonal_sum;
    return ans;
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
    int *ans=solve(matrix,m,n);
    printf("Principal digonal sum is: %d\n",ans[0]);
     printf("secondary digonal sum is: %d\n",ans[1]);
    printf("\n");
    return 0;
}
