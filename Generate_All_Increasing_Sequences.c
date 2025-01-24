#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void solve(int n,int k,int index,int count,int *ans,int ans_index)
{
    if(count==k)
    {
        for(int i=0;i<ans_index;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
        return;
    }
    for(int i=index;i<=n;i++)
    {
        ans[ans_index]=i;
        solve(n,k,i+1,count+1,ans,ans_index+1);
    }
    return;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,k;
    scanf("%d %d",&k,&n);
    int *ans=(int *)malloc(k*sizeof(int));
    solve(n,k,1,0,ans,0);
    return 0;
}
