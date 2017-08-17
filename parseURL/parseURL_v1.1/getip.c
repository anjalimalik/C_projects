// @author Anjali Malik
// Function: to get IP Address from string in binary form (32 bits)


#include <stdio.h>
#include <stdlib.h>         // for atoi()
#include "parseURL.h"

unsigned int getip(char host[], int len) {
    
    /* Initializing local variables */
    char str1[5];           // Helper string array
    int x = 0;
    char c;
	int i = 0;
    
    // For splitting the address
    int first = 0;
    int second = 0;
    int third = 0;
    int fourth = 0;
    int indices[3];

    /* Make an int array of indices where dot appears in order to divide the 4 numbers */
    // Check when character in host is '.' (ASCII - 46)
    for (i = 0; i < len; i++) {
        c = host[i];
        if(c == 46){
            if(x > 4){
                return 0;
            }
            indices[x] = i;
            x++;
        }
    }
    if(x != 3){
        return 0;
    }
    /* Get the 4 numbers that make the IP address */
    // All numbers should be positive integers from 0-255, inclusive.
    
    // First number
    for(i = 0; i < indices[0]; i++){
        str1[i] = host[i];
    }
    str1[indices[0]-0] = '\0';
    first = atoi(str1);
    
    if((first > 255) || (first < 0)){
        return 0;
    }
        
    // Second number
    for(i = indices[0]+1; i < indices[1]; i++){
        str1[i-indices[0]-1] = host[i];
    }
    str1[indices[1]-indices[0]-1] = '\0';
    second = atoi(str1);
    
    if((second > 255) || (second < 0)){
        return 0;
    }
    
    // Third number
    for(i = indices[1]+1; i < indices[2]; i++){
        str1[i-indices[1]-1] = host[i];
    }
    str1[indices[2]-indices[1]-1] = '\0';
    third = atoi(str1);
    
    if((third > 255) || (third < 0)){
        return 0;
    }
    
    // Fourth number
    for(i = indices[2]+1; i < len; i++){
        str1[i-indices[2]-1] = host[i];
    }
    str1[len-indices[2]-1] = '\0';
    fourth = atoi(str1);
    
    if((fourth > 255) || (fourth < 0)){
        return 0;
    }
    
    // Use these 4 numbers to convert ip address into integer represention
    unsigned int dec = 0;
    //unsigned int tmp = 0;
        
    dec = (first * 16777216) + (second * 65536) + (third * 256) + (fourth);
    
    return dec;

}
