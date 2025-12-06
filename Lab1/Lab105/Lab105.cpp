#include <stdio.h>

void GetMatrix (int value[], int *row, int *col);

int main() {
    int *data;
    int m, n;

    GetMatrix((int*)&data, &m, &n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", data[i * n + j]);
        }
        printf("\n");
    }

    delete[] data;
    return 0;
}

void GetMatrix (int value[], int *row, int *col) {
    int **ptr = (int**)value; 

    scanf("%d %d", row, col);

    *ptr = new int[*row * *col];

    for (int i = 0; i < *row; i++) {
        for (int j = 0; j < *col; j++) {
            scanf("%d", &((*ptr)[i * *col + j]));
        }
    }
}

// #include <stdio.h>

// void GetMatrix (int **value, int *row, int *col);

// int main () {
//     int *data, m, n;
//     GetMatrix(&data, &m, &n);
    
//     for(int i = 0 ; i < m ; i++){
//         for(int j = 0 ; j < n ; j++){
//             printf("%d ", data[i * n + j]);
//         }
//         printf("\n");
//     }

//     delete[] data;
//     return 0;
// }

// void GetMatrix (int **value, int *row, int *col) {
//     scanf("%d %d", row, col);
//     *value = new int[*row * *col];
//     for(int i = 0 ; i < *row ; i++){
//         for(int j = 0 ; j < *col ; j++){
//             scanf("%d",&((*value)[i * *col + j]));
//         }
//     }
// }

// void GetMatrix (int value[], int *row, int *col);