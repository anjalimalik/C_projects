// @author Anjali Malik

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
    
    // Initialize all local variables
    char buf[100];
    int len;
    char c;
    char check[6];
    int flag = 0;
    char str[100];
    char secret[100];
    char password[100];
    int stop = 0;
    int i = 0;
    int tmp = 0;
    int run = 1;
    
    char rev[100];
    
    // Get secret string for unlocking from txt file   
    FILE *fp;
    fp = fopen("secretstring.txt", "r");
    fscanf(fp, "%s", secret);
    fclose(fp);
    
    // Infinite loop for running esh shell
    while(!stop) {
        
        // Initialize with each loop run
        run = 1;
        len = 0;
        buf[0] = '\0';

        // Print prompt
        if (flag == 0){
            printf("$ ");
        } else if (flag >= 1){
            printf("%s: ", str);
        } else if(flag == -1) {
	    flag = tmp;
        }
	
        // Get user input into buf array
        while(((c = getchar()) != '\n') && (len < 100)) {
            buf[len] = c;
            len++;
        }
        buf[len] = '\0';
        
        // CUSTOM SHELL COMMAND - #1 : enter command which is partially case insensitive (are letters are treated as small letters) using ASCII
        check[0] = buf[0];
        check[1] = '\0';
        if(strcmp("_", check) == 0){
            for(i = 1; i <= len; i++){
                if(buf[i] >= 'A' && buf[i] <= 'Z'){
                    c = buf[i]+32;            // This is when char has to be converted from big to small letters
                    buf[i-1] = c;
                } else{
                    buf[i-1]= buf[i];         // every character other than big letters remain same
                }
            }
            len = len - 1;
            buf[len] = '\0';
            run = 1;
            
        }
        
        // CUSTOM SHELL COMMAND - #2 : reverse the string and then run command
        check[0] = buf[0];
        check[1] = buf[1];
        check[2] = buf[2];
        check[3] = buf[3];
        check[4] = '\0';
        if(strcmp("rev ", check) == 0){
            run = 2;
            rev[0] = '\0';
            len = strlen(buf);
            
            // Reverse string and store in new char array - rev
            for(i = len-1; i >= 4; i--){
                rev[len-1-i] = buf[i];
            }
            rev[len-4] = '\0';
            
        }
        

        // Copy the first 5 characters in buf into check for cprt command
        check[0] = buf[0];
        check[1] = buf[1];
        check[2] = buf[2];
        check[3] = buf[3];
        check[4] = buf[4];
        check[5] = '\0';
        
        // Code for cprt <string> command
        if (strcmp(check, "cprt ") == 0) {
            run = 0;
            flag += 1;
		
	    // Store string for next prompt in str char array
            for(i = 0; buf[i+5] != '\0'; i++){
                str[i] = buf[i+5];
            }
            str[len-5] = '\0';
        }
        
        // If pressed return key without command, just go to the start of the loop
        if(buf[0] == '\n'){
  	     run = 0;
	     if(flag >= 1){
		flag = flag;
	     }
        }
	
        // Exit if entered 'e', 'E', 'x', or 'X' - behaves like "Ctrl+C"
        if((strcmp("E", buf) == 0) || (strcmp("e", buf) == 0) || (strcmp("x", buf) == 0) || (strcmp("X", buf) == 0)){
            stop = 1;
            run = 0;
        }
        // Part of custom shell command #2
        if((strcmp("E", rev) == 0) || (strcmp("e", rev) == 0) || (strcmp("x", rev) == 0) || (strcmp("X", rev) == 0)){
            stop = 1;
            run = 0;
        }
        
        // Custom command lck: Need correct password to unlock
        if((strcmp("lck", rev) == 0) || (strcmp("lck", buf) == 0)){
            run = 0;
            tmp = flag;
            flag = -1;
            password[0] = '\0'; // Initialize
            
	    // Cannot resume the normal operations until secret string is entered
            while(strcmp(password, secret) != 0){
                printf("key to unlock: ");
                scanf("%s", password);
            }
            rev[0] = '\0';
        }	
    

	
        // Only run command using system() if run is 1, otherwise, print prompt
        if(run == 1){
            system(buf);
        } else if(run == 2){
            system(rev); //for custom shell command #2
        }
    } // end of infinite while loop
    return 0;
}
