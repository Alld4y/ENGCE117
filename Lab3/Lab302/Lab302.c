#include <stdio.h>

typedef struct {
    char name[20];
    int age;
    char sex;
    float gpa;
} student;

void upgrade(student *child);

int main() {
    student aBoy = {.sex = 'M', .gpa = 3.00};
    upgrade(&aBoy);
    printf("%.2f\n", aBoy.gpa);
    printf("upgrading GPA is changed because struct is passed by reference.\n");
    return 0;
}

void upgrade(student *child) {
    //printf("Before upgrading, GPA = %.2f\n", child->gpa);
    if(child->sex == 'M') {
        child->gpa += 0.1 * child->gpa;
    } else if (child->sex == 'F') {
        child->gpa += 0.2 * child->gpa;
    }   
}