#include <stdio.h>
#include <stdlib.h>

int ** solve(int **a,int m,int n)
{
    //do the transpose
    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
    }
    for(int i=0;i<m;i++)
    {
         int start=0;
         int end=n-1;
        while(start<end)
        {
            int temp=a[i][start];
            a[i][start]=a[i][end];
            a[i][end]=temp;
            start++;
            end--;
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