#include <stdio.h>

int GetSet(int []);

int main() {
    int *data, num;

    num = GetSet((int*)&data); 

    for (int i = 0; i < num; i++) {
        printf("[%d]: %d\n", i, data[i]);
    }

    delete[] data;
    return 0;
}

int GetSet(int data[]) {
    int **p = (int**)data;
    int num;
    scanf("%d", &num);

    *p = new int[num];

    for (int i = 0; i < num; i++) {
        scanf("%d", &((*p)[i]));
    }
    return num;
}