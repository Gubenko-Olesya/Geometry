#include <stdio.h>
#include <math.h>
//funksiya ishet sleduyushuyu (n-nuyu) tochku i stavit ee index n-nim v massive indexov, posle chego uvelichivaet n na 1

int find_next (double x[], double y[], int ind[], int m, int n) //Gubenko Olesya 112
{
	int i, buf;
	double v_x, v_y, w_x, w_y, k=-1, cos;
	if (n==1) {
		v_x=1;
		v_y=0;
	}
	else {
		v_x=x[ind[n-1]]-x[ind[n-2]];
		v_y=y[ind[n-1]]-y[ind[n-2]];
	}
	for (i=n; i<m; i++) {
		w_x=x[ind[i]]-x[ind[n-1]];
		w_y=y[ind[i]]-y[ind[n-1]];
		cos=(v_x*w_x+v_y*w_y)/(sqrt(v_x*v_x+v_y*v_y)*sqrt(w_x*w_x+w_y*w_y));
		if (cos>k) {
			k=cos;
			buf=ind[n];
			ind[n]=ind[i];
			ind[i]=buf;
		}
	}
	//otdelno posle vsekh drugih tochek proveryaem pervuyu tochku
	w_x=x[ind[0]]-x[ind[n-1]];
	w_y=y[ind[0]]-y[ind[n-1]];
	cos=(v_x*w_x+v_y*w_y)/(sqrt(v_x*v_x+w_x*w_x)*sqrt(v_y*v_y+w_y*w_y));
	if (cos>k) {
		ind[n]=ind[0];
		return n;
	}
	return n+1;
}
