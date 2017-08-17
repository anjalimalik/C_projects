// @author Anjali Malik

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "dotheader.h"


 
int main() {

    // Initializing variables
    float x[MAXSIZE], y[MAXSIZE]; 
    int vecsize;
    float x_mag;
    float y_mag;
    float u[MAXSIZE];
    
    // Calling read_vectors to read in x and y vectors in float arrays
    int read = read_vectors(&vecsize, &*x, &*y); 
    // If read is -1, that means there is an error in user input
    if (read == -1) {
        // Descriptive Error message with help is created.
        printf("Error with inputs. Please put inputs in the following manner:\n");
        printf("\tFirst Line: N (Ex. 3)\n");
        printf("\tSecond Line: Floats Vector X (Ex. 1.2 3.2 1.3)\n");
        printf("\tThird Line: Floats Vector Y (Ex. 5.3 8.7 23.98)\n");
        printf("Please press <Enter> after every line\n");
        return 0;
    }
    
    calc_diff(vecsize, x, y, u);
    printf("\nDifference between the two arrays: ");
	int i = 0;
    for(i = 0; i < vecsize; i++){
        printf("%.2f ", u[i]);
    }
    printf("\n");
    
    // Calling dot_product to calculate magnitude (norm) of x and y float vectors and its dot_product
    float dot_product = calc_dotmag(vecsize, &*x, &*y, &x_mag, &y_mag);
    
    printf("Magnitude of Vector X: %.2f \n", x_mag);
    printf("Magnitude of Vector Y: %.2f \n", y_mag);
    printf("Dot Product: %.2f \n\n", dot_product);

    return 0;
}


