#include <stdio.h>

char* reverse(char str1[]);

int main () {
    char text[50] = "I Love You";
    char *out;
    out = reverse(text);
    printf("%s",out);
    delete [] out;
    return 0;
}

char* reverse(char str1[]) {
    int len = 0;
    while (str1[len] != '\0') {
        len++;
    }
    
    char* str = new char[len+1];

    for(int i = 0 ; i < len ; i++) {
        str[i] = str1[len-i-1];
    }
    str[len] = '\0';
    return str;
}