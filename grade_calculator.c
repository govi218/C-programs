#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

typedef struct
{
	char* name;
	float percentage, max_percentage;
} Module;

//typedef struct Module Module;

Module grade[7];

void initialize(FILE* fstream) 
{ 
	float pct_sum = 0.00;
	char temp;
	printf("sdv\n");
	fputs("name max_percentage percentage\n", fstream);
	//(errno > 0)? perror("") : 
	printf("Enter \"Module Name, Max Percentage, Percentage[0]\"\n");
	for (int i = 0; i < 8; ++i)
	{
		printf("%d. ", (i + 1));
//		do
//		{
//		scanf("%s", (grade[i].name));
//		} while (!(scanf("%s", grade[i].name) == EOF));
		while(!(scanf("%s", &temp) == EOF))
		{
			grade[i].name = &temp;
		}

		printf(", ");
		while(!(scanf("%s", &temp) == EOF))
		{
			grade[i].max_percentage = strtof(&temp, NULL);
		}
		printf(", ");
		while(!(scanf("%s", &temp) == EOF))
		{
			grade[i].percentage = strtof(&temp, NULL);
		}

		if (!((grade[i].percentage)))
		{
			(grade[i].percentage) = 0;
		}
		pct_sum += (grade[i].percentage);
		printf("\n");
		fprintf(fstream, "%s %f %f\n", (grade[i].name), (grade[i].max_percentage), (grade[i].percentage));
	}
	fprintf(fstream, "%s %f %f\n", "Total", 100.00, pct_sum);
	printf("Written.\n");
	fclose(fstream);
	exit(1);
}

int main(int argc, char const *argv[])
{
	/*
	 *  Variables
	 */

	FILE* fstream;
	float sum = 0.00;
	float max_sum = 0;
	float pct_sum = 0;

	/*
	 *	Check If Initialized
	 */

	fstream = fopen("/home/gov/Documents/CSCB09_grade.txt", "r");
	if (!fstream)
	{
		fstream = fopen("/home/gov/Documents/CSCB09_grade.txt", "a");
		initialize(fstream);
	}

	/*
	 *	Grade Calculation
	 */

	if((argc == 1) || (argc > 8))
	{
		printf("[PCRS][A1][A2][Midterm][A3][A4][Final]\n");
		exit(1);
	}

	for (int i = 0; i < 7; ++i)
	{
		char name;
		float max = 0.00;
		float pct = 0.00;
		fscanf(fstream, "%s %f %f", &name, &max, &pct);
		(grade[i].name)= &name;
		(grade[i].max_percentage) = max;
		(grade[i].percentage) = pct;
	}

	for (int i = 0; i < argc; i++)
	{
		((grade[i].percentage)) = strtof(argv[i + 1], NULL);
		if (((grade[i].percentage)) > 50)
		{
			float temp = (((grade[i].percentage)) / 100) * ((grade[i].max_percentage));
			(grade[i].percentage) = temp;
		}
		else 
		{
			(grade[i].percentage) = strtof(argv[i + 1], NULL);;
		}
		sum += (grade[i].percentage);
		max_sum = (grade[i].max_percentage);
	}

	printf("Percentage: %f, Max: %f\n", sum, max_sum);

	/*
	 *	File Writing
	 */
	printf("Write?(y/n)\n");
	char ch;
	scanf("%c", &ch);

	if (ch == 'y')
	{
		FILE* fwrite;
		fwrite = fopen("/home/gov/Documents/CSCB09_grade_temp.txt", "w");
		char name;
		float max = 0.00;
		float pct = 0.00;

		for ( int i = 0; i < argc; ++i)
		{	

			fscanf(fstream, "%s %f %f", &name, &max, &pct);
			fprintf(fwrite, "%s %f %f", &name, max, (grade[i].percentage));
			pct_sum += (grade[i].percentage);
		}

		for (int i = 0; i < (7 - argc); ++i)
		{
			fscanf(fstream, "%s %f %f", &name, &max, &pct);
			fprintf(fwrite, "%s %f %f", &name, max, pct);
			pct_sum += pct;
		}
		fprintf(fwrite, "%s %f %f", "Total", 100.00, pct_sum);
		fclose(fstream);
		fclose(fwrite);
		remove("/home/gov/Documents/CSCB09_grade.txt");
		rename("/home/gov/Documents/CSCB09_grade_temp.txt", "/home/gov/Documents/CSCB09_grade.txt");
		printf("Written\n");
	}

	else if (ch == 'n')
	{
		fclose(fstream);
		return 0;
	}

	else
	{
		int tolerance = 0;
		while(tolerance < 2) 
		{
			printf("Invalid input\n");
			if (tolerance > 2)
			{
				printf("bye\n");
				exit(1);
			}
			tolerance++;
		}
	}

	fclose(fstream);
	return 0;
}
