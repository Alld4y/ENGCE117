#include <stdio.h>

#define MAX_ROOMS 20
#define STUDENTS_PER_ROOM 10

typedef struct {
    char name[20];
    int age;
    char sex;
    float gpa;
} Student;

/* Function to collect student data for each room */
void GetStudents(Student students[][STUDENTS_PER_ROOM], int *totalRooms);

/* Function to display student data */
void PrintStudents(Student students[][STUDENTS_PER_ROOM], int totalRooms);

int main(void) {
    Student students[MAX_ROOMS][STUDENTS_PER_ROOM];
    int totalRooms = 0;

    GetStudents(students, &totalRooms);
    PrintStudents(students, totalRooms);

    return 0;
}

void GetStudents(Student students[][STUDENTS_PER_ROOM], int *totalRooms) {
    printf("Enter number of rooms: ");

    if (scanf("%d", totalRooms) != 1 || *totalRooms <= 0) {
        printf("Invalid room count.\n");
        return;
    }

    for (int roomIndex = 0; roomIndex < *totalRooms; roomIndex++) {
        printf("----- Room %d -----\n", roomIndex + 1);

        for (int studentIndex = 0; studentIndex < STUDENTS_PER_ROOM; studentIndex++) {
            printf("Enter name age sex gpa: ");

            if (scanf("%s %d %c %f",
                    students[roomIndex][studentIndex].name,
                    &students[roomIndex][studentIndex].age,
                    &students[roomIndex][studentIndex].sex,
                    &students[roomIndex][studentIndex].gpa) != 4) {

                printf("Invalid student data.\n");
                return; // Stop to avoid unstable state
            }
        }
    }
}

void PrintStudents(Student students[][STUDENTS_PER_ROOM], int totalRooms) {
    for (int roomIndex = 0; roomIndex < totalRooms; roomIndex++) {
        printf("----- Room %d -----\n", roomIndex + 1);

        for (int studentIndex = 0; studentIndex < STUDENTS_PER_ROOM; studentIndex++) {
            printf("%s %d %c %.2f\n",
                students[roomIndex][studentIndex].name,
                students[roomIndex][studentIndex].age,
                students[roomIndex][studentIndex].sex,
                students[roomIndex][studentIndex].gpa);
        }
    }
}
