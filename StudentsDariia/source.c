// This program create data base for students.
// Lab Work 5. Exercise 12
// 
/********************************************************
*	File name:	lab4ex11.c								*
*	Students:	Dariia Shemiakina and Tamir Yurovskiy	*
*	Deadline:	08.06.2020								*
*	Date:		08.06.2020								*
********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "student.h"
#include "s_class.h"

int main(void)
{
	Student * database = (Student *)malloc(sizeof(Student));
	int size = 0;
	char choise;

	do
	{
		printf("\n1 - Enter new student\n");
		printf("2 - Average grade for each student\n");
		printf("3 - Information about student\n");
		printf("4 - Information about all students\n");
		printf("5 - List of students that have average greater then\n");
		printf("0 - Exit\n");
		printf("Enter your choise => ");
		choise = getch();

		switch (choise)
		{
			case '1':
				newStudent(database, &size);
				break;
			case '2':
				searchAverage(database, size);
				break;
			case '3':
				infoOneStudent(database, size);
				break;
			case '4':
				infoAllStudents(database, size);
				break;
			case '5':
				averageGreaterThen(database, size);
				break;
			case '0':
				printf("\n Goodbay! \n");
				break;
			default:
				break;
		}
	}
	while (choise != '0');

	free(database);

	return(0);
	
}