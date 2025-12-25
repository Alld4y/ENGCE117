#include <stdio.h>

typedef struct {
    char name[20];
    int age;
    char sex;
    float gpa;
} student;

student upgrade(student child);

int main() {
    student aBoy;
    aBoy.sex = 'M';
    aBoy.gpa = 3.00;
    aBoy = upgrade(aBoy);
    printf("%.2f\n", aBoy.gpa);
    printf("upgrading GPA is changed because struct is returned and reassigned.\n");
    return 0;
}

student upgrade(student child) {
    if(child.sex == 'M') {
        child.gpa += 0.1 * child.gpa;
    } else if (child.sex == 'F') {
        child.gpa += 0.2 * child.gpa;
    }
    return child;
}