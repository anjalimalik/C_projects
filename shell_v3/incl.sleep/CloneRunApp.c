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
    char c[10];
    char sec[10];
    int t = 0;
    int delay = 0;
    
    strcpy(temp, binary);

    // Using strtok with delimiter as " "
    s[0] = strtok(temp, " ");
    strcpy(c, s[0]);    
    a = 1;

	
    // Check if delay is given and store number of seconds in t
    if((c[0]== 'd') && (c[1]== 'd')){
	strcpy(sec, strtok(c, "dd"));
	t = atoi(sec);
	delay = 1;
    }	

    // Using space delimiter
    while(1){
        s[a] = strtok(NULL, " " );
        if(s[a] == NULL){
            break;
        }		
        a++;
    }
    s[a] = NULL;

    // if delay is given, modify the array of strings to not have argv[0]
    if(delay == 1){
	for(x = 0; x < (a-1); x++){	
		s[x] = s[x+1];
	}
	s[a-1] = NULL;
    }
    x = 0;
    k = fork();

    if(k < 0){
	// Forking fails        
	return -1;
    } else if(k == 0){
        /* CHILD */

	if(delay == 1){
		sleep(t);
        	x = execvp(s[0], s);
	} else {
        	x = execvp(s[0], s);
	}
     
        // if command doesn't exist
        if(x == -1){
            exit(1);
        }
    } else {
        /* PARENT */
        return k;
    }
    
    return 0;
}
