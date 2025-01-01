#include <stdio.h>
long solve(long b, long n, long m) {
    long result=1; 
    b=b%m;          
    while (n>0) {
        if (n%2==1) {
            result=(result*b)%m;
        }
        n=n/2;
        b=(b*b)%m;
    }

    return result;
}

int main() {
    long b, n, m;
    printf("Enter the base B: ");
    scanf("%ld", &b);

    printf("Enter the exponent N: ");
    scanf("%ld", &n);

    printf("Enter the modulus M: ");
    scanf("%ld", &m);
    if (m <= 1) {
        printf("Error:M must be greater than 1.\n");
        return 1;
    }
    if (n < 0) {
        printf("Error:N must be a non-negative integer.\n");
        return 1;
    }
    long result = solve(b,n,m);
    printf("Result: %ld\n",result);

    return 0;
}