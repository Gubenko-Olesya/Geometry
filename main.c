#include <stdio.h>
#include "func.h"
#define SIZE 100

int main(void)		//Gubenko Olesya 112
{
	char filename[120];
	double x[SIZE], y[SIZE], point_x, point_y;
	int ind[SIZE], qty=0, n, i;
	FILE *fin, *fout;

	for (i=0; i<SIZE; i++) {
		ind[i]=i;
	}

	printf("The programm constructs convex hull of the given set of points.\n");
	printf("Enter the name of the file with points coordinates.\n");

	scanf("%s", filename);
	fin=fopen(filename, "r");

	if (fin==NULL) {
		printf("File %s is not opened.\n", filename);
		return -1;
	}

	while (fscanf(fin, "%lf %lf", &point_x, &point_y) == 2) {
		x[qty]=point_x;
		y[qty]=point_y;
		qty++;
	}

	fclose(fin);

	n=convex_hull(x, y, ind, SIZE);

	fout=fopen("output.txt", "w");
	if (fout==NULL) {
		printf("File output.txt is not opened.\n");
		return -1;
	}

	for (i=0; i<n; i++)
		fprintf(fout, "%lf %lf\n", x[ind[i]], y[ind[i]]);

	fclose(fout);
	return 0;
}
