#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isVowel(char c) {
    c=tolower(c);
    return (c =='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int main() {
    int rows, cols;
    char names[10][50];
    int count = 0;
    char longestname[50] = "";
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter the names:\n");
    int total=rows*cols;
    for (int i=0;i<total;i++) {

        printf("Name at index %d: ",i);
        scanf("%s",names[i]);
        if (isVowel(names[i][0])) {
            count++;
        }
        if (strlen(names[i])>strlen(longestname)) {
            strcpy(longestname,names[i]);
        }
    }

    printf("\nThe 2D array of names is:\n");
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            printf("%s ", names[i*cols+j]);
        }
        printf("\n");
    }

    printf("\nNumber of names starting with a vowel: %d\n", count);
    printf("The longest name: %s\n", longestname);

    return 0;
}
