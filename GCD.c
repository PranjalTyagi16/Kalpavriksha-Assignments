#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
void gcd(long long a,long long b)
{
    if(a==0)
    {
        printf("%lld",b);
        return;
    }
    if(b==0)
    {
         printf("%lld",a);
        return;
    }
    if(a>b)
    {
        gcd(a-b,b);
    }
    else
    {
        gcd(a,b-a);
    }
    return;
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char input[1000];
    scanf("%[^\n]%*c",input);
    long long temp[1000];
    int index=0;
    char *ptr=input;
    while(*ptr!='\0')
    {
        if(isdigit(*ptr))
        {
            long long num;
            sscanf(ptr,"%lld",&num);
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
    long long a=temp[0];
    long long b=temp[1];
     gcd(a,b);
    return 0;
}
