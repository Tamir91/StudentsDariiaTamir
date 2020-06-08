#include "s_class.h"


void infoAllStudents(Student * database, int size)
{
	int i, j;

	printf("\n");

	if (size == 0)
	{
		printf("No found students in database!");
	}
	else
	{
		for (i = 0; i < size; ++i)
		{
			printf("%d. %-10s %d. Grades: ", i + 1, database[i].name, CURRENT_YEAR - database[i].age);

			for (j = 0; j < NUM_OF_GRADES; ++j)
			{
				printf("%-2d, ", database[i].grades[j]);
			}

			printf("Averade: %-2.2f\n", database[i].average);
		}
	}
}

void averageGreaterThen(Student * database, int size)
{
	int i, j;
	float average;

	do
	{
		printf("\nEnter average grade: ");
		scanf("%f", &average);
	}
	while (average < 0.0 || average > 100.0);

	for (i = 0, j = 1; i < size; ++i)
	{
		if (average < database[i].average)
		{
			printf("%d. %s\n", j + 1, database[i].name);
			++j;
		}
	}
}