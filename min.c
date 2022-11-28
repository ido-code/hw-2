/* Welcome to Mamat, 044101
 *
 * Use this project as a template for other C/C++ projects.
 * To copy this project, right-click on the project name "hello-world"
 * in the "project explorer" tab (left), then "copy" and finally "paste".
 *
 * To compile the project use "gcc" within the terminal.
 * To debug the project use "gdb" within the terminal.
 *
 * The red vertical line (right) represents the code width limit (80 chars).
 * Make sure not to cross it. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * @brief Application's main entry point
 * @param argc Number of arguments
 * @param argv Pointer to arguments
 * @return Non-zero value in case of an error
 */
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

int main(int argc, char **argv) {
	FILE *fd;
	bool is_first = true;
	int num = 0;
	const int NUMOFCHARS = 11;
	char path[NUMOFCHARS];
	if((argc == 1) ||(strcmp((char *)argv[1],"-") == 0))
	{
		if(fgets(path, NUMOFCHARS*sizeof(char), stdin) == NULL)
		{
			fprintf(stderr,"The path was not read\n");
		}
	}
	else
	{
		strncpy(path,argv[1],strlen(argv[1]));
	}
	fd = fopen(path,"r");
	char grade_char[4];
	int grade;
	while (fgets(grade_char, sizeof(grade_char), fd))
	{
		if(sscanf (grade_char, "%d", &grade) == 0)
		{
			fprintf(stderr,"The input was not string\n");
			return 0;
		}
		if(is_first)
		{
			is_first = false;
			num = grade;
		}
		else
		{
			if(grade < num)
			{
				num = grade;
			}
		}
	}

	fprintf(stdout,"%d", num);
	fclose(fd);

	return 0;
}
