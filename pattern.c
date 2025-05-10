#include <stdio.h>

int main() 
{

    int n;
    scanf("%d", &n);
    int rows=(2*n)-1;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<rows;j++)
        {
            int min;
            if(i<j)
            {
                min=i;
            }
            else
            {
                min=j;
            }
            min=min<rows-j-1?min:rows-j-1;
            min=min<rows-i-1?min:rows-i-1;
            printf("%d ",n-min);
            
        }
        printf("\n");
    }
    return 0;
}