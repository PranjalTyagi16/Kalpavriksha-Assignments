#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int solve(int *nums, int n) {
    int prev = 0;
    int curr = 1;
    int ans = 0;   

    for (int i=1;i<n;i++)
    {
        if (nums[i-1]<nums[i]) 
        {
            curr++;
        } 
        else 
        {
            prev=curr;
            curr=1;    
        }
         ans=ans>curr/2?ans:curr/2;
         ans=ans>(prev<curr?prev:curr)?ans:(prev<curr?prev:curr);
    }
    return ans;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
     char *input=(char *)malloc(100000*sizeof(char));
    scanf("%[^\n]%*c",input);
    int *arr=(int *)malloc(100000*sizeof(int));
    int index=0;
    char *ptr=input;
    while(*ptr!='\0')
    {
        if(isdigit(*ptr)||*ptr=='-')
        {
            int num;
            sscanf(ptr,"%d",&num);
            arr[index++]=num;
            while(isdigit(*ptr)||*ptr=='-')
            {
                ptr++;
            }
        }
        else
        {
            ptr++;
        }
    }
    int ans=solve(arr,index);


    printf("%d\n",ans);
    return 0;
}
