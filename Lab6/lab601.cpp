#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

// ใช้ Reference (&) ในสไตล์ C++ เพื่อให้เขียนง่ายขึ้น แต่ข้างในยังเป็น Logic ภาษา C
struct studentNode *AddNode(struct studentNode **start, const char *n, int a, char s, float g);
void InsNode(struct studentNode **start, struct studentNode *now, const char *n, int a, char s, float g);
void GoBack(struct studentNode **now);
void DelNode(struct studentNode **start, struct studentNode **now);
void ShowAll(struct studentNode *walk);

int main() {
    struct studentNode *start = NULL;
    struct studentNode *now = NULL;

    // การเพิ่มโหนด
    now = AddNode(&start, "one", 6, 'M', 3.11);   ShowAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22);   ShowAll(start);

    // การแทรกโหนด (หน้าโหนดปัจจุบัน)
    InsNode(&start, now, "three", 10, 'M', 3.33); ShowAll(start);
    InsNode(&start, now, "four", 12, 'F', 3.44);  ShowAll(start);

    // ถอยกลับ 1 ก้าว
    GoBack(&now);

    // การลบโหนด
    printf("\n--- Deleting ---\n");
    DelNode(&start, &now); ShowAll(start);
    DelNode(&start, &now); ShowAll(start);
    DelNode(&start, &now); ShowAll(start);

    return 0;
}

// ใช้ new แทน malloc
struct studentNode *AddNode(struct studentNode **start, const char *n, int a, char s, float g) {
    struct studentNode *newNode = new studentNode; // ใช้ new
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;

    if (*start == NULL) {
        newNode->back = NULL;
        *start = newNode;
    } else {
        struct studentNode *temp = *start;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->back = temp;
    }
    return newNode;
}

// ใช้ new ในการแทรกโหนด
void InsNode(struct studentNode **start, struct studentNode *now, const char *n, int a, char s, float g) {
    if (now == NULL) return;
    struct studentNode *newNode = new studentNode; // ใช้ new
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;

    newNode->next = now;
    newNode->back = now->back;

    if (now->back != NULL) {
        now->back->next = newNode;
    } else {
        *start = newNode;
    }
    now->back = newNode;
}

void GoBack(struct studentNode **now) {
    if (*now != NULL && (*now)->back != NULL) {
        *now = (*now)->back;
    }
}

// ใช้ delete แทน free
void DelNode(struct studentNode **start, struct studentNode **now) {
    if (*now == NULL) return;
    
    struct studentNode *temp = *now;
    struct studentNode *p = temp->back;
    struct studentNode *n = temp->next;

    if (p != NULL) p->next = n;
    else *start = n;

    if (n != NULL) n->back = p;

    // อัปเดตตำแหน่ง now ก่อนลบจริง
    if (n != NULL) *now = n;
    else *now = p;

    delete temp; // ใช้ delete
}

void ShowAll(struct studentNode *walk) {
    if (walk == NULL) {
        printf("Empty List\n");
        return;
    }
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}