#include <stdio.h>

//funksiya ishet pervuyu (niznuyu pravuyu) tochku i stavit ee index pervim v massive indexov

int find_first (double x[], double y[], int ind[], int m) //Gubenko Olesya 112
{
	int i;
	for (i=1; i<m; i++) {
		if (y[i]<y[ind[0]])
			ind[0]=i;
		else {
			if (y[i]==y[ind[0]]) {
				if (x[i]>x[ind[0]])
					ind[0]=i;
			}
		}
	}
	if (ind[0]!=0)
		ind[ind[0]]=0;
	return 0;
}
