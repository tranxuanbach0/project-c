#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "datatypes.h"

#define MAX_STUDENTS 100

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;

    loadStudentsFromFile(students, &studentCount, "students.dat");

    while (1) {
        int choice;
        printf("\n--- STUDENT MANAGEMENT SYSTEM ---\n");
        printf("1. Show Students\n");
        printf("2. Add Student\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Search Student by Name\n");
        printf("6. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showStudentList(students, studentCount);
                break;
            case 2:
                addStudent(students, &studentCount);
                break;
            case 3:
                updateStudent(students, studentCount);
                break;
            case 4:
                deleteStudent(students, &studentCount);
                break;
            case 5:
                searchStudentByName(students, studentCount);
                break;
            case 6:
                saveStudentsToFile(students, studentCount, "students.dat");
                printf("Exiting... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

