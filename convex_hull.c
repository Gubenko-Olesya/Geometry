#include <stdio.h>
#include "func.h"

int convex_hull(double x[], double y[], int ind[], int m) //Gubenko Olesya 112
{
	int n=1;
	find_first(x, y, ind, m);
	while (ind[n]!=ind[0])
		n=find_next(x, y, ind, m, n);
	return n;
}
