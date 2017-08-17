// author @ Anjali Malik

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int CloneRunApp(char * binary){
    
    // Initialize local variables
    pid_t k;
    int status;
    int x, a;
    
    char temp[100];         // temporary array for binary
    char * s[100];          // create char * array to store the entire command
    
    
    strcpy(temp, binary);

    // Using strtok with delimiter as " "
    s[0] = strtok(temp, " ");
    a = 1;
    while(1){
        s[a] = strtok(NULL, " " );
        if(s[a] == NULL){
            break;
        }		
        a++;
    }
    s[a] = NULL;
    
    k = fork();
    
    if(k < 0){
	// Forking fails
        return -1;
    } else if(k == 0){
        /* CHILD */
        x = execvp(s[0], s);
     
        // if command doesn't exist
        if(x == -1){
            fprintf(stdout, "Failure to execute: -eesh: no such command found\n");
            exit(1);
        }
    } else {
        /* PARENT */
        return k;
    }
    
    return 0;
}
