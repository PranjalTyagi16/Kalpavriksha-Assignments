#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct pair{
    long long value;
    long long freq;
    int first;
}Pair;
int contains(Pair *ans,int size,long long value)
{
    for(int i=0;i<size;i++)
    {
        if(ans[i].value==value)
        {
            return i;
        }
    }
    return -1;
}
Pair * solve(long long *arr,int *size,int n){
    Pair *ans=(Pair*)malloc(n*sizeof(Pair));
    int idx=0;
    for(int i=0;i<n;i++)
    {
        int index=contains(ans,idx,arr[i]);
        if(index!=-1)
        {
            ans[index].freq+=1;
        }
        else
        {
            ans[idx].value=arr[i];
            ans[idx].freq=1;
            ans[idx].first=i;
            idx++;
        }
    }
    *size=idx;
    return ans;
}
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
    int size=0;
    Pair *ans=solve(arr,&size,index);
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(ans[j].freq<ans[j+1].freq||(ans[j].freq==ans[j+1].freq&&ans[j].first>ans[j+1].first))
            {
                Pair temp=ans[j];
                ans[j]=ans[j+1];
                ans[j+1]=temp;
            }
        }
    }
    for(int i=0;i<size;i++)
    {
         if(i<size-1){
        for(int j=0;j<ans[i].freq;j++)
        {
            printf("%lld ",ans[i].value);
        }
        }
        else
        {
           for(int j=0;j<ans[i].freq;j++)
          {
               if(j<ans[i].freq-1){
            printf("%lld ",ans[i].value);
               }
               else
               {
                   printf("%lld",ans[i].value);
               }
          }
        }
        
    }
    printf("\n");
    return 0;
}
