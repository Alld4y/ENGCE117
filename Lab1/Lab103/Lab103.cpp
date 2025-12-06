#include <stdio.h>

int *GetSet(int *);

int main () {
    int *data, num;
    data = GetSet(&num);
    for(int i = 0; i < num; i++) {
        printf("[%d]: %d\n", i, data[i]);
    }
    delete[] data;
    return 0;
}

int *GetSet(int *num) {
    scanf("%d", num);
    int *data = new int[*num];
    for(int i = 0; i < *num ; i++) {
        scanf("%d", &data[i]);
    }
    return data;
}