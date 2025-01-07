#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

void spiralorder(int mat[][10], int rows, int cols) {
    int left=0;
    int right=cols-1;
    int top=0;
    int bottom=rows-1;
    int total=rows*cols;
    int count=0;
    int result[total];
    int index=0;

    while (count<total) {
        for (int i=left;count<total&&i<=right;i++) {
            result[index++]=mat[top][i];
            count++;
        }
        top++;
        for (int i=top;count<total&&i<=bottom;i++) {
            result[index++]=mat[i][right];
            count++;
        }
        right--;
        for (int i=right;count<total&&i>=left;i--) {
            result[index++]=mat[bottom][i];
            count++;
        }
        bottom--;
        for (int i=bottom;count<total&&i>=top;i--) {
            result[index++]=mat[i][left];
            count++;
        }
        left++;
    }

    printf("[");
    for (int i=0;i<total;i++) {
        printf("%d",result[i]);
        if (i<total-1) {
            printf(" ");
        }
    }
    printf("]");
}

int main() {
    char read[1000];
    fgets(read, sizeof(read), stdin);

    int rows=0,cols=0;
    int matrix[10][10];
    int temp[100];
    int index=0;
    char *ptr=read;
    while (*ptr) {
        if (isdigit(*ptr)) {
            int num;
            sscanf(ptr, "%d", &num);
            temp[index++] = num;
            while (isdigit(*ptr)) {
                ptr++;
            }
        } else {
            ptr++;
        }
    }
    int spaces=0;
    for (int i=2;read[i]!=']'&&read[i]!='\0';i++) {
        if (read[i]==' ')spaces++;
    }
    cols=spaces+1;
    rows=index/cols;

    index=0;
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            matrix[i][j]=temp[index++];
        }
    }

    spiralorder(matrix,rows,cols);

    return 0;
}