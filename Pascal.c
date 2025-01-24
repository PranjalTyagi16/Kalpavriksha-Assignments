#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long nCr(int n,int r) {
        long ans=1;
        for(int i=0;i<r;i++)
        {
            ans=ans*(n-i);
            ans=ans/(i+1);
        }
    return ans;
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        long ans=nCr(n-1,i-1);
        if(i<n){
        printf("%ld,",ans);
        }
        else{
        printf("%ld",ans);
        }
    }
    return 0;
}
