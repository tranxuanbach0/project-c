#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "datatypes.h"

void showStudentList(Student students[], int count);
void addStudent(Student students[], int *count);
void updateStudent(Student students[], int count);
void deleteStudent(Student students[], int *count);
void searchStudentByName(Student students[], int count);
void saveStudentsToFile(Student students[], int count, const char *filename);
void loadStudentsFromFile(Student students[], int *count, const char *filename);

#endif

