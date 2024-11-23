#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
int solve(int a, int b, char op){
    switch (op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': 
            if(b==0){
                printf("Error: Division by zero.\n");
                exit(0);
            }
            return a/b;
    }
    return 0;
}
int prec(char op){
    if (op =='+'||op=='-')
         return 1;
    if (op=='*'||op=='/')
         return 2;
    return 0;
}
int cal(char* expression){
    int i;
    int num[MAX],top1=-1;   
    char ops[MAX], top2 = -1;
    for(i=0;i<strlen(expression);i++){
        if(expression[i]==' ') 
              continue;
        if(isdigit(expression[i])){
            int value=0;
            while(i<strlen(expression)&&isdigit(expression[i])){
                value=value*10+(expression[i]-'0');
                i++;
            }
            i--;
            num[++top1]=value;
        }
        else if(expression[i]=='+'||expression[i]=='-'||
                 expression[i]=='*'||expression[i]=='/'){
            while(top2!=-1&&prec(ops[top2])>=prec(expression[i])){
                int val2=num[top1--];
                int val1=num[top1--];
                char op=ops[top2--];
               num[++top1]=solve(val1, val2, op);
            }            
            ops[++top2]=expression[i];
        }else{
            printf("Error: Invalid expression.\n");
            exit(0);
        }
    }
    while(top2!=-1){
        int val2=num[top1--];
        int val1=num[top1--];
        char op=ops[top2--];
        num[++top1]=solve(val1, val2, op);
    }
    return num[top1];
}
int main(){
    char expression[MAX];
    printf("Enter the mathematical expression: ");
    scanf("%[^\n]",expression); 
    int result =cal(expression);
    printf("Answer for the expression: %d\n", result);
    return 0;
}