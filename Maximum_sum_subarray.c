#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

int maxsum(int *nums,int length)
{
    int max=INT_MIN;
    int sum=0;
    if(length==0)
    {
        return 0;
    }
    for(int i=0;i<length;i++)
    {
        sum+=nums[i];
        if(max<sum)
        {
            max=sum;
        }
        if(sum<0)
        {
            sum=0;
        }
    }
    return max;
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char string[100000];
    scanf("%[^\n]s",string);
    int *nums=(int *)malloc(100000*sizeof(int));
    char *ptr=string;
    int index=0;
    while(*ptr!='\0')
    {
        if(isdigit(*ptr)||*ptr=='-')
        {
            int num;
            sscanf(ptr,"%d",&num);
            nums[index++]=num;
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
    int ans=maxsum(nums,index);
    free(nums);
    printf("%d",ans);
    return 0;
}
