#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
void subset(int *arr,int n,int index,int *ans,int ans_index,int *isFirst)
{
      if(*isFirst) {
        printf("[");
        *isFirst = 0;
    } 
    else 
    {
        printf(", [");
    }
    
    for(int i=0;i<ans_index;i++)
    {
        if(i<ans_index-1){
        printf("%d, ",ans[i]);
        }
        else
        {
            printf("%d",ans[i]);
        }
    }
    printf("]");
    for(int i=index;i<n;i++)
    {
        ans[ans_index]=arr[i];
        subset(arr,n,i+1,ans,ans_index+1,isFirst);
    }
    return;
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char input[1000];
    scanf("%[^\n]%*c",input);
    int *arr=(int *)malloc(1000*sizeof(int));
    int index=0;
    char *ptr=input;
    while(*ptr!='\0')
    {
        if(isdigit(*ptr))
        {
            int num;
            sscanf(ptr,"%d",&num);
            arr[index++]=num;
            while(isdigit(*ptr))
            {
                ptr++;
            }
        }
        else
        {
            ptr++;
        }
    }
    int *ans=(int *)malloc(index*sizeof(int));
    int isFirst=1;
    printf("[");
    subset(arr,index,0,ans,0,&isFirst);
    printf("]");
    return 0;
}