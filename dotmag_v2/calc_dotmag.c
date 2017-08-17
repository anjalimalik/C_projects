// @author Anjali Malik

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "dotheader.h"

float calc_dotmag(int vecsize, float *x, float *y, float *x_mag, float *y_mag) {
    // Initialize variables and referenced pointers
    *x_mag = 0;
    *y_mag = 0;
    float dot_product = 0;      // dot product variable of x and y vectors
	int i = 0;
    
    for (i = 0; i < vecsize; i++) {
        // Calculate sum of squares of vector elements
        *x_mag = *x_mag + ((x[i]) * (x[i]));
        *y_mag = *y_mag + ((y[i]) * (y[i]));
        // Multiply each element and calculate sum for dot product
        dot_product = dot_product + ((x[i]) * (y[i]));
    }
    // Calculate square roots of magnitude
    *x_mag = sqrt(*x_mag);
    *y_mag = sqrt(*y_mag);
    
    return dot_product;
}
