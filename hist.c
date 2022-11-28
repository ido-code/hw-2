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
	//int num = 0;
	const int NUMOFCHARS = 11;
	char path[NUMOFCHARS];
	// ASSUME THE FIRST IS PATH AND THE SECOND IS N_BINS
	int n_bins;
	if(argc < 3)
	{
		n_bins = 10;
		if((argc == 1)||(strcmp((char *)argv[1],"-") == 0))
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
	}
	else
	{
		n_bins = atoi(argv[2]);
		if(strcmp((char *)argv[1],"-") != 0)
		{
			strncpy(path,argv[1],strlen(argv[1]));
		}

		else
		{
			if(fgets(path, NUMOFCHARS*sizeof(char), stdin) == NULL)
			{
				fprintf(stderr,"The path was not read\n");
			}
		}
	}
	fd = fopen(path,"r");
	char grade_char[5];
	int grade;
	int *hist = (int *)malloc(n_bins*sizeof(int));
	while (fgets(grade_char, sizeof(grade_char), fd))
	{
		if(sscanf (grade_char, "%d", &grade) == 0)
		{
			fprintf(stderr,"The input was not string\n");
			return 0;
		}
		int index_to_add = (grade*n_bins)/100;
		if(index_to_add == n_bins)
			index_to_add--;
		hist[index_to_add]++;
	}
	fclose(fd);
	for(int ind=0;ind < n_bins;ind++)
	{
		if(ind < n_bins-1)
			fprintf(stdout,"%d-%d	",ind*100/n_bins,-1 + ((ind+1)*100)/n_bins);
		else
			fprintf(stdout,"%d-%d	",ind*100/n_bins,100);

		fprintf(stdout, "%d\n",hist[ind]);
	}
	free(hist);
	return 0;
}
