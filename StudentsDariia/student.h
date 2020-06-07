#ifndef _STUDENT_H
#define _STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */
#define MAX_LENGTH 20
#define MAX_NUM_OF_STUDENTS 30
#define NUM_OF_GRADES 5
#define MIN_AGE 1920
#define MAX_AGE (CURRENT_YEAR - 1)
#define CURRENT_YEAR 2020
#define MIN_GRADE 0
#define MAX_GRADE 100
#define TRUE 1
#define FALSE 0
#define SUCCESS 0
#define FAILURE 1

#pragma warning (disable: 4996)

typedef struct
{
	char * name;
	int age;
	int grades[NUM_OF_GRADES];
	float average;
} Student;

/* newStudent
-------------------------------------------------------------------------------
Description: Create new student

Arguments:
	• database - all students in class
	• size - number of students in class

Return value: void */
void newStudent(Student * database, int * size);

/* isStudentInClass
-------------------------------------------------------------------------------
Description: Check if student in database.

Arguments:
	• database - all students in class
	• size - number of students in class
	• studentName - student name

Return value: Student * */
Student * isStudentInClass(Student * database, int size, char studentName[MAX_LENGTH]);

/* scanAgeFromUser
-------------------------------------------------------------------------------
Description: Recieve student age from user and validate it.

Arguments:
	• database - all students in class
	• size - number of students in class

Return value: void */
void scanAgeFromUser(Student * database, int size);

/* scanGradesFromUser
-------------------------------------------------------------------------------
Description: Recieve students grades from user and validate it.

Arguments:
	• database - all students in class
	• size - number of students in class

Return value: void */
void scanGradesFromUser(Student * database, int size);

/* culcAverageForAllStudents
-------------------------------------------------------------------------------
Description: Calculate average for all students.

Arguments:
	• database - all students in class
	• size - number of students in class

Return value: void */
void calcAverageForAllStudents(Student * database, int size);

/* infoOneStudent
-------------------------------------------------------------------------------
Description: print infromation about student by name recieved from user.

Arguments:
	• database - all students in class
	• size - number of students in class

Return value: void */
void infoOneStudent(Student * database, int size);

#endif // _STUDENT_H