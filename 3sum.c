#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int size_of_ans_array=0;
int * threesum(int *nums,int length)
{
    int *ans=(int *)malloc(length*3*sizeof(int));
    int index=0;
    for(int i=0;i<length;i++)
    {
        if(i>0&&nums[i]==nums[i-1])
        {
            continue;
        }
        int j=i+1;
        int k=length-1;
        while(j<k)
        {
            if(nums[i]+nums[j]+nums[k]==0)
            {
                ans[index++]=nums[i];
                ans[index++]=nums[j];
                ans[index++]=nums[k];
                j++;
                k--;
                while(j<k&&nums[j]==nums[j-1])
               {
                j++;
               }
               while(j<k&&nums[k]==nums[k+1])
               {
                k--;
               }
            }
           else if(nums[i]+nums[j]+nums[k]<0)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    size_of_ans_array=index;
    return ans;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char string[3002];
    scanf("%[^\n]s",string);
    int *nums=(int *)malloc(3000*sizeof(int));
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
    //first sort the array
    for(int i=0;i<index;i++)
    {
        for(int j=0;j<index-1;j++)
        {
            if(nums[j]>nums[j+1])
            {
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    }
    int *ans=threesum(nums,index);
     int rows=size_of_ans_array/3;
    int **matrix=(int **)malloc(rows*sizeof(int *));
    for(int i=0;i<rows;i++)
    {
        matrix[i]=(int *)malloc(3*sizeof(int));
    }
    index=0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<3;j++)
        {
            matrix[i][j]=ans[index++];
        }
    }
    printf("[");
    for(int i=0;i<rows;i++)
    {
        printf("[");
        for(int j=0;j<3;j++)
        {
            if(j<2){
            printf("%d ",matrix[i][j]);
            }
            else
            {
                printf("%d",matrix[i][j]);
            }
        }
        if(i<rows-1){
        printf("],");
        }
        else
        {
            printf("]");
        }
    }
    printf("]");
    return 0;
}
