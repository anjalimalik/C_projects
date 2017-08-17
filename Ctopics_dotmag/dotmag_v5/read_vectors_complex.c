//  read_vectors_complex.c
// @author Anjali Malik

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "dotprod_header.h"

complex_num_t* read_vectors_complex(int vecsize, char * file) {
   
   // Initialize the local variables
    FILE *fp;
    int i = 0;
    int count = 0;
    complex_num_t num;
    complex_num_t* vec = (complex_num_t*) malloc(vecsize*sizeof(complex_num_t));
    
    // open file to read
    fp = fopen(file, "r");
    // store complex numbers from file into complex vector
    for (i = 0; i < vecsize; i++){
        fscanf(fp, "%f %f", &num.x, &num.y);
        vec[i] = num;
    }
    
    // close file 
    fclose(fp);

    // return complex vector
    return vec;
}

