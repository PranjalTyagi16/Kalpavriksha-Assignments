#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int binary_search(int *nums,int n,int target)
{
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(nums[mid]==target)
        {
            return 1;
        }
        if(nums[mid]<target)
        {
            start++;
        }
        else{
            end--;
        }
    }
    return 0;
}


int main()
{
    int m,n;
    printf("enter the rows and cols\n");
    scanf("%d %d",&m,&n);
    int target;
    printf("enter the target\n");
    scanf("%d",&target);
    int **matrix=(int **)malloc(m*sizeof(int *));
    for(int i=0;i<m;i++)
    {
      matrix[i]=(int *)malloc(n*sizeof(int));
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    int i=0;
    for(i=0;i<m;i++)
    {
        int ans=binary_search(matrix[i],n,target);
        if(ans==1)
        {
            break;
            
        }
    }
    if(i<m){
        printf("True\n");
    }
    else{
    printf("False\n");
    }

    return 0;
}
