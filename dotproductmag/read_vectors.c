// @author Anjali Malik

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "dotheader.h"

int read_vectors(int *vecsize, float *x, float *y) {
    // Read line for N
    char string0[100];
    int n0 = 0;
    char c0;
    while((c0 = getchar()) != '\n') {
        string0[n0] = c0;
        n0++;
    }
    string0[n0] = '\0';
    *vecsize = atoi(string0);   // Assign to pointer of vecsize
    
    // Check if input is not numerical
    if ((strcmp(string0,"0")!= 0) && (*vecsize==0)) {
        return -1;
    }

    // Read line for x's & separate by " " delimiter
    char string1[100];
    int n1 = 0;
    char c1;
    while((c1 = getchar()) != '\n') {
        string1[n1] = c1;
        n1++;
    }
    string1[n1] = '\0';     // This is string form of float vector x

    // Read line for y's & separate by " " delimiter
    char string2[100];
    int n2 = 0;
    char c2;
    while((c2 = getchar()) != '\n') {
        string2[n2] = c2;
        n2++;
    }
    string2[n2] = '\0';     // This is string form of float vector y

    // Splitting string1 into x floats using " " delimiter
    char * tmp1;
    tmp1 = strtok(string1," ");
    int i = 0;
    
    while (tmp1 != NULL){
        float a = atof(tmp1);
        // Check if input is not numerical
        if ((strcmp(tmp1,"0")!= 0) && (a==0)) {
            return -1;
        }
        x[i] = a;
        tmp1 = strtok (NULL, " ");
        i++;
    }
   
    // Check if user has entered number of floats not equal to vecsize (which is wrong)
    if (i != *vecsize) {
      return -1;
    }
 
    // Splitting string2 into y floats using "space" delimiter
    char * tmp2;
    tmp2 = strtok(string2," ");
    int j = 0;
    while (tmp2 != NULL){
        float b = atof(tmp2);
       // Check if input is not numerical
        if ((strcmp(tmp2,"0")!= 0) && (b==0)) {
            return -1;
        }
        y[j] = b;
        tmp2 = strtok (NULL, " ");
        j++;
    }
    
    // Check if user has entered number of floats not equal to vecsize (which is wrong)
    if (j != *vecsize) {
      return -1;
    }
    
    
    return 1;
}
