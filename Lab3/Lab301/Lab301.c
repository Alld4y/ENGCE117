#include <stdio.h>

typedef struct {
    char name[20];
    int age;
    char sex;
    float gpa;
} student;

void upgrade(student child);

int main(void) {
    student aBoy;

    /* Initialize student data */
    aBoy.sex = 'M';
    aBoy.gpa = 3.00;

    /* Pass structure by value */
    upgrade(aBoy);

    /* GPA remains unchanged because a copy was modified */
    printf("%.2f\n", aBoy.gpa);
    printf("Upgrading GPA is not changed because struct is passed by value.\n");

    return 0;
}

void upgrade(student child) {
    /* Modify GPA based on gender (local copy only) */
    if (child.sex == 'M') {
        child.gpa = child.gpa + (0.1 * child.gpa);
    }
    else if (child.sex == 'F') {
        child.gpa = child.gpa + (0.2 * child.gpa);
    }
}
