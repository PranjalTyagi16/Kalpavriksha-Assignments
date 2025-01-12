#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
int *solve(int **nums,int m,int n)
{
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    int *ans=(int *)malloc(2*sizeof(int));
    for(int row=0;row<m;row++)
    {
       for(int col=0;col<n;col++)
       {
        int i=0;
          for(i=0;i<4;i++)
          {
            int newrow=row+dr[i];
            int newcol=col+dc[i];
            if(newrow<0||newrow>=m||newcol<0||newcol>=n)
            {
                continue;
            }
            if(nums[row][col]<nums[newrow][newcol])
            {
               break;
            }
          }
          if(i==4)
          {
            ans[0]=row;
            ans[1]=col;
            return ans;
          }
       }
    }
    ans[0]=-1;
    ans[1]=-1;
    return ans;
}


int main()
{
   char input[1000];
   scanf("%[^\n]s",input);
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
    int *ans=solve(matrix,rows,cols);
    printf("%d , %d\n",ans[0],ans[1]);
    

    return 0;
}
