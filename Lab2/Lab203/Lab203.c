#include <stdio.h>

void explode(char str1[], char splitter, char str[][10], int *count);

int main () {
    char out[20][10];
    int count = 0;

    explode("I/Love/You", '/', out, &count);

    for(int i = 0 ; i < count ; i++){
        printf("str2[%d] = %s\n", i, out[i]);  // print each token
    }

    printf("count = %d", count);  // print number of tokens
    return 0;
}

void explode(char str1[], char splitter, char str[][10], int *count) {
    int i = 0;  // index for str1
    int j = 0;  // index for str

    if(str1[0] != '\0')
        (*count) = 1; 

    while(str1[i] != '\0') {  
        if(str1[i] == splitter) {  // if splitter found
            str[(*count)-1][j] = '\0';  // end current
            (*count) += 1;
            j = 0;
        } else {
            str[(*count)-1][j] = str1[i];  // copy character
            j += 1;  // move to next position
        }
        i += 1;  // move to next character in str1
    }
}
