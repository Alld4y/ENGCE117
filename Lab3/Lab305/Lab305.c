#include <stdio.h>

typedef struct {
    char name[20];
    int age;
    char sex;
    float gpa;
} student;

student (*GetStudent(int *room))[10];

int main() {
    student (*children)[10];
    int group;
    children = GetStudent(&group);
    for(int i = 0 ; i < group ; i++) {
        printf("----- Room %d -----\n", i+1);
        for(int j = 0 ; j < 10 ; j++) {
            printf("%s %d %c %.2f\n", children[i][j].name, children[i][j].age, children[i][j].sex, children[i][j].gpa);
        }
    }
    return 0;
}

student (*GetStudent(int *room))[10] {
    static student children[20][10];  // static to persist after function returns
    printf("Enter number of room: ");
    if(scanf("%d", room) != 1) {
        printf("Invalid input.\n");
    }
    for(int i = 0 ; i < *room ; i++) {
        printf("----- Room %d -----\n", i+1);
        for(int j = 0 ; j < 10 ; j++) {
            printf("Enter name, age, sex, gpa: ");
            if(scanf("%s %d %c %f", children[i][j].name, &children[i][j].age, &children[i][j].sex, &children[i][j].gpa) != 4) {
                printf("Invalid input.\n");
            }
        }
    }
    return children;
}