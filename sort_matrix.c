#include <stdio.h>
#include <stdlib.h>

int ** solve(int **a,int m,int n)
{
    int length=m*n;
   for(int i=0;i<length;i++)
   {
    for(int j=0;j<length-1;j++)
    {
        if(a[j/n][j%n]>a[(j+1)/n][(j+1)%n])
        {
            int temp=a[j/n][j%n];
            a[j/n][j%n]=a[(j+1)/n][(j+1)%n];
            a[(j+1)/n][(j+1)%n]=temp;
        }
    }
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
