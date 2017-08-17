// Function: string compare as an alternative of strcmp() C library function as
//           we have to make our own processing code
// @author Anjali Malik

#include <stdio.h>
#include "parseURL.h"


int strcompare(char *s1, char *s2){
    
    // Local Variables
    int i = 0;
    int x;
    int y;
    int diff = 0;
    
    // Check one by one if difference between characters is 0 and get length
    while ((x = s1[i]) && (y = s2[i]) && (diff = y - x) == 0)
        i++;
    
    // Return the difference (0 if strings equal)
    if (diff)
        return diff;
    else if (x == '\0')
        y = s2[i];
    return (y - x);
}
