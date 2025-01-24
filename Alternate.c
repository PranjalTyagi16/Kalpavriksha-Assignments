#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int solve(int n) {
    int *arr=(int *)malloc(n*sizeof(int));
    int size=n;


    for(int i=0;i<n;i++)
    {
        arr[i]=i+1;
    }

    int flag=1; 

    while(size>1)
    {
        int newsize = 0;
        if (flag==1) 
        {
            for (int i=1;i<size;i+=2) 
            {
                arr[newsize++]=arr[i];
            }
        } 
        else 
        {
            for (int i=size-2;i>=0;i-=2)
            {
                arr[newsize++]=arr[i];
            }
            
             for (int i=0;i<newsize/2;i++) 
             {
                int temp=arr[i];
                arr[i]=arr[newsize-i-1];
                arr[newsize-i-1]=temp;
            }

        }
        size=newsize;
        flag=!flag;
    }

    return arr[0];
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d",&n);
    int ans=solve(n);
    printf("%d",ans);
    return 0;
}
