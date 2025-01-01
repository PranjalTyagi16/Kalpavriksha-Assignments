#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char str[101], words[100][100];
    int freq[100] = {0};
    int i, j, index = 0;
    
     scanf("%[^\n]%*c",str);
    
    char *token = strtok(str, " ");
    while (token != NULL) {
        strcpy(words[index], token);
        index++;
        token = strtok(NULL, " ");
    }
    
    for (i=0;i<index;i++) {
        for (j=0; j<index;j++) {
            if (strcmp(words[i], words[j]) == 0) {
                freq[i]++;
            }
        }
    }
    
    for (i=0;i<index;i++) {
        if (freq[i] == 1) {
            printf("%s\n", words[i]);
            return 0;
        }
    }
    printf("\n");
    return 0;
}
