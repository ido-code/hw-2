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

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        fprintf(stdout,"%d ", arr[i]);
    fprintf(stdout,"\n");
}

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

int main(int argc, char **argv) {
	FILE *fd;
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
	char grade_char[5];
	int grade;
	int counter =0;
	while (fgets(grade_char, sizeof(grade_char), fd))
	{
		if(sscanf (grade_char, "%d", &grade) == 0)
		{
			fprintf(stderr,"The input was not string\n");
			return 0;
		}
		counter++;

	}
	fclose(fd);
	fd = fopen(path,"r");
	int ind =0;
	int *all_mumbers = malloc(sizeof(int)*counter);
	while (fgets(grade_char, sizeof(grade_char), fd))
	{
		if(sscanf (grade_char, "%d", &grade) == 0)
		{
			fprintf(stderr,"The input was not string\n");
			return 0;
		}
		if(ind < counter)
			all_mumbers[ind] = grade;
		ind++;
	}
	selectionSort(all_mumbers,counter);
	int index_of_med = (counter+1)/2;
	num = all_mumbers[index_of_med-1];
	fprintf(stdout,"%d", num);
	free(all_mumbers);
	fclose(fd);

	return 0;
}
