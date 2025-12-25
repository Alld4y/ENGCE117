#include <stdio.h>

typedef struct {
    char name[20];
    int age;
    char sex;
    float gpa;
} student;

void GetStudent(student child[][10], int *room);

int main() {
    student children[20][10];
    int group;
    GetStudent(children, &group);
    for(int i = 0 ; i < group ; i++) {
        printf("----- Room %d -----\n", i+1);
        for(int j = 0 ; j < 10 ; j++) {
            printf("%s %d %c %.2f\n", children[i][j].name, children[i][j].age, children[i][j].sex, children[i][j].gpa);
        }
    }
    return 0;
}

void GetStudent(student child[][10], int *room) {
    printf("Enter number of room: ");
    if(scanf("%d", room) != 1) {
        printf("Invalid input.\n");
    }
    for(int i = 0 ; i < *room ; i++) {
        printf("----- Room %d -----\n", i+1);
        for(int j = 0 ; j < 10 ; j++) {
            printf("Enter name, age, sex, gpa: ");
            if(scanf("%s %d %c %f", child[i][j].name, &child[i][j].age, &child[i][j].sex, &child[i][j].gpa) != 4) {
                printf("Invalid input.\n");
            }
        }
    }
}