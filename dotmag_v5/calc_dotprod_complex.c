// @author Anjali Malik

#include <stdio.h>
#include "dotprod_header.h"

complex_num_t calc_dotprod_complex(int vecsize, complex_num_t vec1[], complex_num_t vec2[])
{

    // Initialize local variables
    complex_num_t num;
    complex_num_t dot; // dot product variable of x and y vectors
    int i = 0;
    
    // Intialize values in dot
    dot.x = 0;
    dot.y = 0;

    // For loop to find the dot product
    for (i = 0; i < vecsize; i++)
    {
        // multiply complex numbers
        num.x = (((vec1[i].x) * (vec2[i].x)) - ((vec1[i].y) * (vec2[i].y)));
        num.y = (((vec1[i].x) * (vec2[i].y)) + ((vec1[i].y) * (vec2[i].x)));

        // add complex numbers
        dot.x = (dot.x + num.x);
        dot.y = (dot.y + num.y);
    }

    // return dot to main
    return dot;
}
