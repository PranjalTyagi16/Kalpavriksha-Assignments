#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    char names[m][101];
    long long total_sum[m];
    for(int i=0;i<n;i++)
    {
        total_sum[i]=0;
    }
    for(int i=0;i<m;i++)
    {
        scanf("%s",names[i]);
        for(int j=0;j<n;j++)
        {
            long long cost;
            scanf("%lld",&cost);
            total_sum[i]+=cost;
        }
    }
    long long max=total_sum[0];
    for(int i=1;i<m;i++)
    {
        if(max<total_sum[i])
        {
            max=total_sum[i];
        }
    }
    for(int i=0;i<m;i++)
    {
        if(max==total_sum[i])
        {
            printf("%s",names[i]);
            printf("\n");
        }
    }
    return 0;
}
