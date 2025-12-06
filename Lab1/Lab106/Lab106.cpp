#include <stdio.h>

int *GetMatrix (int *row, int *col);

int main () {
    int *data, m, n;
    data = GetMatrix(&m, &n);

    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            printf("%d  ",data[i * n + j]);
        }
        printf("\n");
    }
    delete[] data;
    return 0;
}

int *GetMatrix (int *row, int *col) {
    int *matrix;
    scanf("%d %d", row, col);
    matrix = new int[*row * *col];

    for(int i = 0 ; i < *row ; i++) {
        for(int j = 0 ; j < *col ; j++) {
            scanf("%d",&(matrix[i * *col + j]));
        }
    }

    return matrix;
}

