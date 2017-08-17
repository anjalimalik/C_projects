// @author Anjali Malik

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "dotheader.h"

int read_vectors(int *vecsize, float *x, float *y) {
    // Read line for N
    FILE *fp;
    int i = 0;
    
    fp = fopen("vecin.dat", "r");
    fscanf(fp, "%d", vecsize);
    
    // Check if vecsize is zero
    if (*vecsize==0) {
        return -1;
    }
	
    for(i = 0; i < *vecsize; i++){
    	fscanf(fp, "%f", &x[i]);
    }
    for(i = 0; i < *vecsize; i++){
    	fscanf(fp, "%f", &y[i]);
    }

    fclose(fp);

    return 1;
}
