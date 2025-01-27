#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

int solve(int *arr,int n)
{
    int min=INT_MAX;
    for(int i=0;i<n-1;i++)
    {
        if(min>(arr[i+1]-arr[i]))
        {
            min=(arr[i+1]-arr[i]);
        }
    }
    return min;
}

int compare(const void *a,const void *b)
{
    return (*(int *)a-*(int *)b);
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
    int first=1;
    qsort(arr,index,sizeof(int),compare);
    int min=solve(arr,index);
    for(int i=0;i<index-1;i++)
    {
        if(arr[i+1]-arr[i]==min)
        {
            if(!first)
            {
                printf(",");
            }
            printf("[%d,%d]",arr[i],arr[i+1]);
            first=0;
            
        }
    }
    
    return 0;
}
