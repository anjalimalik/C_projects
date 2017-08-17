// @author Anjali Malik
// Function: to get domain name from string

#include <stdio.h>
#include "parseURL.h"

int getdomain(char host[], int len) {
    
    // Local variables - helper string arrays
    char str1[5];
    
    /* Check if permissible domain name .gov or .org are used */
	int j = 0;    
	for(j = len-3; j < len; j++){
        str1[j-len+3] = host[j];
    }
    str1[3] = '\0';
    
    if((strcompare(str1, "gov") == 0) || (strcompare(str1, "org") == 0)){
        // do nothing
    } else {
        return 1;
    }
    
    return 0;
}
