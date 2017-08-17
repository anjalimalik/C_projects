
// @author Anjali Malik

#include <stdio.h>
#include <string.h>
#include "dotprod_header.h"
#include <stdlib.h>


int main(int argc, char *argv[]){
    
    // Initialize local variables
    int vecsize = 0;
    char * file1; 
    char * file2;
    
    // store vecsize from argv
    vecsize = atoi(argv[1]);

    // store names of files containing vectors in char arrays
    file1 = strdup(argv[2]);
    file2 = strdup(argv[3]);
    
    // Initialize complex_num_t variables
    complex_num_t dot;
    complex_num_t* vec1 = (complex_num_t*) malloc(vecsize*sizeof(complex_num_t));
    complex_num_t* vec2 = (complex_num_t*) malloc(vecsize*sizeof(complex_num_t));

    // Check if vecsize is zero
    if (vecsize == 0) {
        // Descriptive Error message with help is created.
        printf("Error with inputs. Please put inputs in the following manner:\n");
        printf("\tFirst Argument: N (Ex. 3)\n");
        printf("\tSecond Argument: .dat file containing floats vector X (Ex. 1.2 3.2 1.3)\n");
        printf("\tThird Argument: .dat file containing floats vector Y (Ex. 5.3 8.7 23.98)\n");
        printf("Please press <Enter> after the 4 arguments including executable\n");
        return 0;
    } else {
        vec1 = read_vectors_complex(vecsize, file1);
        vec2 = read_vectors_complex(vecsize, file2);

        // free file1 and file2 as strdup was used
        free(file1);
        free(file2);
    }

    // getting dotproduct of the vectors
    dot = calc_dotprod_complex(vecsize, vec1, vec2);
    
    // free complex vectors 
    free(vec1);
    free(vec2);
    
    // Print to stdout
    char* string = (char*) malloc(100*sizeof(char));
    sprintf(string, "Dot Product of the complex vectors = %.2f + i %.2f", dot.x, dot.y);
    fprintf(stdout, "\n%s\n\n", string);
    
    free(string);
    
    return 0;
}
