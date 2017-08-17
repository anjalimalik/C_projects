//  strconcatenate.c
//  @author Anjali Malik


#include <stdio.h>

void strconcatenate(char *s1, char *s2){
    
    int len = 0;
    int i = 0;

    // we know that the string length of s1 is 5, however, to make the
    // function universally useful, this loop is used to count length of s1.
    while(s1[len]!='\0'){
        ++len;
    }

    // To separate strings by a space (ASCII - 32)
    s1[len] = 32;
    len++;
    
    for(i = 0; s2[i]!='\0'; i++)
    {
        s1[len] = s2[i];
        len++;
    }
    // Terminate the string with \0
    s1[len]='\0';
    
}


