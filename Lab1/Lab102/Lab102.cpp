#include <stdio.h>

void GetSet(int [], int *);

int main() {
    int data[100];
    int num;

    GetSet(data, &num);

    for(int i = 0; i < num; i++) {
        printf("[%d]: %d\n", i, data[i]);
    }
    
    return 0;
}

void GetSet(int data[], int *num) {
    scanf("%d", num);

    for(int i = 0; i < *num; i++) {
        scanf("%d", &data[i]);
    }
}