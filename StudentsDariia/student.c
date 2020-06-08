#include "student.h"

void newStudent(Student * database, int * size)
{
	char buffer[MAX_LENGTH];
	int  is_equal = FALSE;
	Student * temp = NULL;

	if (*size < MAX_NUM_OF_STUDENTS)
	{
		do
		{
			is_equal = FALSE;
			printf("\nEnter student's name: ");
			if (scanf("%s", &buffer))
			{
				if (isStudentInClass(database, *size, buffer))
					is_equal = TRUE;
			}
		} while (is_equal);

		if (temp = (Student *)realloc(database, (*size + 1) * sizeof(Student)))
		{
			database = temp;
			if (database[*size].name = (char *)malloc((strlen(buffer) + 1) * sizeof(char)))
			{
				strcpy(database[*size].name, buffer);
			}

			scanAgeFromUser(database, *size);
			scanGradesFromUser(database, *size);
		}
		++*size;
	}

	return ;
}

Student * isStudentInClass(Student * database, int size, char studentName[MAX_LENGTH]) {
	int i;
	int is_equal = FALSE;
	Student *st = NULL;

	for (i = 0; i < size && !is_equal; ++i)
	{
		if (!strcmp(database[i].name, studentName) && !st)
		{
			st = &database[i];
			printf("This student appeared in database. Try another name\n");
		}
	}

	return st;
}

void scanAgeFromUser(Student *database, int size) {
	int age = 18;
	do
	{
		printf("Enter student's birth year: ");
		scanf("%d", &age);
	} while (age < MIN_AGE || age > MAX_AGE);

	database[size].age = age;
	return;
}

void scanGradesFromUser(Student *database, int size) {
	int i, grade;

	for (i = 0; i < NUM_OF_GRADES; ++i)
	{
		do
		{
			printf("Enter grade[%d]: ", i + 1);
			if (scanf("%d", &grade))
			{
				database[size].grades[i] = grade;
			}
		} while (grade < MIN_GRADE || grade > MAX_GRADE);

		database[size].average = 0;
	}

	return;
}

void calcAverageForAllStudents(Student ** database, int size)
{
	int i, j;
	float sum = 0;

	printf("\n");

	if (size == 0)
		printf("No found students in database!");

	for (i = 0; i < size; ++i)
	{

		for (j = 0; j < NUM_OF_GRADES; ++j)
		{
			sum +=  (*database)[i].grades[j];
		}
		
		(*database)[i].average = sum / NUM_OF_GRADES;
		sum = 0;
	}
	return;
}

void infoOneStudent(Student * database, int size)
{
	int i, j, is_appeared = FALSE;
	char name[MAX_LENGTH];

	printf("Enter student's name: ");
	scanf("%s", name);

	for (i = 0; i < size && !is_appeared; ++i)
	{
		if (!strcmp(name, database[i].name))
		{
			printf("%s, %d. Grades: ", database[i].name, CURRENT_YEAR - database[i].age);

			for (j = 0; j < NUM_OF_GRADES; ++j)
			{
				printf("%d, ", database[i].grades[j]);
			}

			printf("Averade: %.2f\n", database[i].average);

			is_appeared = TRUE;
		}
	}
}