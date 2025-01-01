#include <stdio.h>
#include <string.h>

void reverse(char* begin, char* end);
char* reversewords(char* s);

int main() {
    char str[1001]; 

    scanf("%[^\n]%*c", str); 


    char* result = reversewords(str);

    printf("%s", result);

    return 0;
}

void reverse(char* begin, char* end) {
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}
char* reversewords(char* s) {
    while (*s==' ') {
        s++;
    }
    int len=strlen(s);
    while (len>0&&s[len - 1]==' ') {
        s[len]='\0';
        len--;
    }

    char* word_start = s;
    char* temp = s;
    while (*temp) {
        temp++;
        if (*temp==' ' || *temp=='\0') {
            reverse(word_start,temp - 1);
            word_start=temp + 1;
        }
    }

    reverse(s, temp - 1);

    char* ans = s;
    temp = s;
    while (*temp) {
        if (*temp != ' ' || (*(temp + 1) != ' '&&*(temp + 1) != '\0')) {
            *ans++ = *temp;
        }
        temp++;
    }
    *ans = '\0';

    return s;
}