#ifndef _S_CLASS_H
#define _S_CLASS_H

#include "student.h"

/* infoAllStudents
-------------------------------------------------------------------------------
Description: Print all information about all students.

Arguments:
	• database - all students in class
	• size - number of students in class

Return value: none */
void infoAllStudents(Student *database, int size);

/* averageGreaterThen
-------------------------------------------------------------------------------
Description: Print names of students with average above insert by uesr.

Arguments:
	• database - all students in class
	• size - number of students in class

Return value: none */
void averageGreaterThen(Student *database, int size);

#endif // _S_CLASS_H