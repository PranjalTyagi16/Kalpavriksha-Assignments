#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
     char *input=(char *)malloc(100000*sizeof(char));
    scanf("%[^\n]%*c",input);
    long long *arr=(long long *)malloc(100000*sizeof(long long));
    int index=0;
    char *ptr=input;
    while(*ptr!='\0')
    {
        if(isdigit(*ptr)||*ptr=='-')
        {
            long long num;
            sscanf(ptr,"%lld",&num);
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
    long long count=0;
    for(int i=0;i<index;i++)
    {
        for(int j=0;j<index-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                long long temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                count++;
            }
        }
    }
    printf("%lld",count);
    return 0;
}
