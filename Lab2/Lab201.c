#include <stdio.h>

void reverse(char str1[], char str2[]);

int main () {
    char text[50] = "I Love You";
    char out[50];
    reverse(text, out);
    printf("%s",out);
    return 0;
}

void reverse(char str1[], char str2[]) {
    int len = 0;

    while(str1[len] != '\0') {
        len++;
    }

    for(int i = 0 ; i < len ; i++) {
        str2[i] = str1[len-1-i];
    }
    str2[len] = '\0';
}