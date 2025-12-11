#include <stdio.h>

void explode(char str1[], char splitter, char str[][10], int *count);

int main () {
    char out[20][10];
    int num;
    int count = 0;
    explode("I/Love/You", '/', out, &count );
    for(int i = 0 ; i < count ; i++){
        printf("str2[%d] = %s\n",i, out[i]);
    }
    printf("count = %d",count);
    return 0;
}

void explode(char str1[], char splitter, char str[][10], int *count) {
    int i = 0;
    int j = 0;

    if(str1[0] != '\0')
        (*count) = 1;
    while(str1[i] != '\0') {
        if(str1[i] == splitter) {
            str[(*count)-1][j] = '\0';
            (*count) += 1;
            j = 0;
        } else {
            str[(*count)-1][j] = str1[i];
            j += 1;
        }
        i += 1;
    } 
}


