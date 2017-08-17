// @author Anjali Malik

#include <stdio.h>
#include "dotheader.h"
#include <math.h>

void calc_power(int vecsize, float *x, float *y, float *u){
    int i = 0;
	float sqr = 0.0;
    	
	for(i = 0; i < vecsize; i++){
        u[i] = y[i] - x[i];
	sqr = pow(u[i], 2);
	u[i] = sqr;
    }
    
}
