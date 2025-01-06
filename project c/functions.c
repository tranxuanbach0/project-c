#include <stdio.h>
#include <string.h>
#include "functions.h"

void showStudentList(Student students[], int count) {
    int i;

    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n| ID  | Name                | Email               | Phone       |\n");
    printf("-----------------------------------------------------------------\n");
    for (i = 0; i < count; i++) {
        printf("| %-3d | %-19s | %-19s | %-11s |\n", 
               students[i].id, students[i].name, students[i].email, students[i].phone);
    }
    printf("-----------------------------------------------------------------\n");
}

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student list is full.\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &students[*count].id);
    getchar();
    printf("Enter Name: ");
    fgets(students[*count].name, sizeof(students[*count].name), stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0';
    printf("Enter Email: ");
    fgets(students[*count].email, sizeof(students[*count].email), stdin);
    students[*count].email[strcspn(students[*count].email, "\n")] = '\0';
    printf("Enter Phone: ");
    fgets(students[*count].phone, sizeof(students[*count].phone), stdin);
    students[*count].phone[strcspn(students[*count].phone, "\n")] = '\0';

    (*count)++;
    printf("Student added successfully.\n");
}

void updateStudent(Student students[], int count) {
    int id, found = 0;
    int i;

    printf("Enter ID of the student to update: ");
    scanf("%d", &id);
    getchar();

    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            found = 1;
            printf("Enter new Name: ");
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';
            printf("Enter new Email: ");
            fgets(students[i].email, sizeof(students[i].email), stdin);
            students[i].email[strcspn(students[i].email, "\n")] = '\0';
            printf("Enter new Phone: ");
            fgets(students[i].phone, sizeof(students[i].phone), stdin);
            students[i].phone[strcspn(students[i].phone, "\n")] = '\0';

            printf("Student updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void deleteStudent(Student students[], int *count) {
    int id, found = 0;
    int i, j;

    printf("Enter ID of the student to delete: ");
    scanf("%d", &id);

    for (i = 0; i < *count; i++) {
        if (students[i].id == id) {
            found = 1;
            for (j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Student deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void searchStudentByName(Student students[], int count) {
    char name[50];
    int found = 0;
    int i;

    getchar();
    printf("Enter the name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (i = 0; i < count; i++) {
        if (strstr(students[i].name, name) != NULL) {
            if (!found) {
                printf("\n| ID  | Name                | Email               | Phone       |\n");
                printf("-----------------------------------------------------------------\n");
            }
            printf("| %-3d | %-19s | %-19s | %-11s |\n", 
                   students[i].id, students[i].name, students[i].email, students[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("No students found with name \"%s\".\n", name);
    } else {
        printf("-----------------------------------------------------------------\n");
    }
}

