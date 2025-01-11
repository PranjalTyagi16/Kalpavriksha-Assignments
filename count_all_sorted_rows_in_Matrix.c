#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int check(int *a,int n)
{
    int prev=a[0];
    for(int i=1;i<n-1;i++)
    {
        int cur=a[i];
        int next=a[i+1];
        if(cur>prev&&cur<next||cur<prev&&cur>next)
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int solve(int **a,int m,int n)
{
   int count=0;
   for(int i=0;i<m;i++)
   {
     count+=check(a[i],n);
   }
   return count;
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
    int ans=solve(a,m,n);
    
    printf("%d\n",ans);
    return 0;
}


