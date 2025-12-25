#include <stdio.h>

#define MAX_ROOMS 20
#define STUDENTS_PER_ROOM 10

typedef struct {
    char name[20];
    int age;
    char sex;
    float gpa;
} Student;

/* Read student data for a single room */
void ReadRoomStudents(Student room[], int roomNumber);

/* Get all student data and return pointer to rooms */
Student (*GetStudent(int *totalRooms))[STUDENTS_PER_ROOM];

/* Print all student data */
void PrintStudents(Student (*students)[STUDENTS_PER_ROOM], int totalRooms);

int main(void) {
    int totalRooms = 0;
    Student (*students)[STUDENTS_PER_ROOM];

    students = GetStudent(&totalRooms);
    PrintStudents(students, totalRooms);

    return 0;
}

Student (*GetStudent(int *totalRooms))[STUDENTS_PER_ROOM] {
    static Student students[MAX_ROOMS][STUDENTS_PER_ROOM];

    printf("Enter number of rooms: ");
    if (scanf("%d", totalRooms) != 1 || *totalRooms <= 0) {
        printf("Invalid room count.\n");
        return students;
    }

    for (int roomIndex = 0; roomIndex < *totalRooms; roomIndex++) {
        ReadRoomStudents(students[roomIndex], roomIndex + 1);
    }

    return students;
}

void ReadRoomStudents(Student room[], int roomNumber) {
    printf("----- Room %d -----\n", roomNumber);

    for (int studentIndex = 0; studentIndex < STUDENTS_PER_ROOM; studentIndex++) {
        printf("Enter name age sex gpa: ");

        if (scanf("%s %d %c %f",
                room[studentIndex].name,
                &room[studentIndex].age,
                &room[studentIndex].sex,
                &room[studentIndex].gpa) != 4) {

            printf("Invalid student input.\n");
            return;
        }
    }
}

void PrintStudents(Student (*students)[STUDENTS_PER_ROOM], int totalRooms) {
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
