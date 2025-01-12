#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
int median(int **nums,int m,int n)
{
    int *ans=(int *)malloc(m*n*sizeof(int));
    int index=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[index++]=nums[i][j];
        }
    }
    int length=m*n;
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length-1;j++)
        {
            if(ans[j]>ans[j+1])
            {
                int temp=ans[j];
                ans[j]=ans[j+1];
                ans[j+1]=temp;
            }
        }
    }
    if(index%2!=0)
    {
        return ans[(index-1)/2];
    }
    return ((ans[index/2]+ans[(index-1)/2])/2);
}


int main()
{
   char input[1000];
   scanf("%[^\n]%*c",input);
   int *temp=(int *)malloc(100*sizeof(int));
   char *ptr=input;
   int index=0;
   while(*ptr!='\0')
   {
     if(isdigit(*ptr))
     {
        int num;
        sscanf(ptr,"%d",&num);
        temp[index++]=num;
        while(isdigit(*ptr))
        {
            ptr++;
        }
     }
     else{
        ptr++;
     }
   }
   int rows=0;
   int cols=0;
   int spaces=0;
   for(int i=2;input[i]!=']'&&input[i]!='\0';i++)
   {
     if(input[i]==' ')
     {
        spaces++;
     }
   }
    cols=spaces+1;
   rows=index/cols;
    int **matrix=(int **)malloc(rows*sizeof(int *));
    for(int i=0;i<rows;i++)
    {
        matrix[i]=(int *)malloc(cols*sizeof(int));
    }
    index=0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            matrix[i][j]=temp[index++];
        }
    }
    int ans=median(matrix,rows,cols);
    printf("%d\n",ans);
    

    return 0;
}

