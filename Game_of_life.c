#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
int ** solve(int **matrix,int m,int n)
{
    int dr[]={-1,1,0,0,1,1,-1,-1};
    int dc[]={0,0,1,-1,1,-1,1,-1};
    int **ans=(int **)malloc(m*sizeof(int *));
    for(int i=0;i<m;i++)
    {
        ans[i]=(int *)malloc(n*sizeof(int));
    }
    for(int row=0;row<m;row++)
    {
        for(int col=0;col<n;col++)
        {
            int count=0;
            if(matrix[row][col]==0)
            {
                for(int i=0;i<8;i++)
                {
                    int newrow=row+dr[i];
                    int newcol=col+dc[i];
                    if(newrow>=0&&newrow<m&&newcol>=0&&newcol<n){
                    if(matrix[newrow][newcol]==1)
                    {
                        count++;
                    }
                }
                if(count==3)
                {
                    ans[row][col]=1;
                }
                else
                {
                    ans[row][col]=0;
                }
                }
            }
            else
            {
                for(int i=0;i<8;i++)
                {
                    int newrow=row+dr[i];
                    int newcol=col+dc[i];
                    if(newrow>=0&&newrow<m&&newcol>=0&&newcol<n){
                    if(matrix[newrow][newcol]==1)
                    {
                        count++;
                    }
                }
                if(count<2)
                {
                    ans[row][col]=0;
                }
                else if(count==2||count==3)
                {
                    ans[row][col]=1;
                }
                else if(count>3)
                {
                    ans[row][col]=0;
                }
                }
            }
        }
    }
    return ans;
    
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char string[1000];
    scanf("%[^\n]s",string);
    char *ptr=string;
    int *temp=(int *)malloc(625*sizeof(int));
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
        else
        {
            ptr++;
        }
    }
    int spaces=0;
    for(int i=2;string[i]!=']'&&string[i]!='\0';i++)
    {
        if(string[i]==' ')
        {
            spaces++;
        }
    }
    int cols=spaces+1;
    int rows=index/cols;
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
    int **ans=solve(matrix,rows,cols);
    printf("[");
    for(int i=0;i<rows;i++)
    {
        printf("[");
        for(int j=0;j<cols;j++)
        {
            if(j<cols-1){
            printf("%d ",ans[i][j]);
            }
            else
            {
                printf("%d",ans[i][j]);
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
