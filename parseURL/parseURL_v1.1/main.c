// @author Anjali Malik

#include <stdio.h>
#include <stdlib.h>
#include "parseURL.h"

int main() {
    
    char url[100];
    char host[100];
    int urllen = 0;
    int hostlen = 0;
    char c;                 // used for getting characters into url
    char str1[8];           // helper string array
    int check = 0;          // used to check if there is part of url remaining after domain or ip
    int domORip = 0;        // used to check if consists domain or ip; 1 for domain
	int i = 0;
   
    /* PART A */
    
    /* Get input URL */
    // Use getchar() as required in problem to fill url, str1 & host string arrays
    while((c = getchar()) != '\n') {
        
        url[urllen] = c;
        
        if((0 <= urllen) && (urllen < 7)){
            str1[urllen] = c;
        } else if(urllen >= 7){
            
            // Check if variable check is 0 and,
            // check if c is '/' or ':'; terminate host array if true
            if (check == 0){
                host[urllen-7] = c;
            }
            
            if ((c == 58) && (check == 0)){
                host[urllen-7] = '\0';
                check += 1;
                hostlen = urllen-7;
            } else if ((c == 47) && (check == 0)){
                host[urllen-7] = '\0';
                check += 1;
                hostlen = urllen-7;
            }

        }
        urllen++;
    }
    url[urllen] = '\0';
    str1[7] = '\0';
    
    // If check = 0, then host array has not been terminated already
    if(check == 0){
        host[urllen-7] = '\0';
        hostlen = urllen-7;
    }
    
    // Catch null input
    if(url[0] == '\n'){
        printf("No URL found. Please input a valid URL and press enter.\n");
        return 1;
    }
    
    
    // Convert upper case to lower case for url, host and str1
    for(i = 0; i < (hostlen + 7); i++){
        if(url[i] >= 'A' && url[i] <= 'Z')
            url[i] += 32;
        if(i < hostlen && host[i] >= 'A' && host[i] <= 'Z')
            host[i] += 32;
        if(i < 8 && str1[i] >= 'A' && str1[i] <= 'Z')
            str1[i] += 32;
    }
    
    /* Check if HTTP protocol is correctly followed */
    if(strcompare("http://", str1) != 0){
        printf("Not a valid input! The URL is ill-formatted; HTTP protocol not followed.\n");
        return 1;
    }
    
    /* Check if host is form of domain or ip address */
    // It is IP address if characters are numbers, domain if they are letters,
    // else it is ill-formatted
    c = url[7];
    if((c > 47) && (c < 58)){
        domORip = 0;
    } else if (((c > 64) && (c < 91)) || ((c > 96) && (c < 123))){
        domORip = 1;
    } else {
        printf("Not a valid input! The URL is ill-formatted.\n");
        return 1;
    }
    
    
    /* EXTRACT DOMAIN NAME */
    if(domORip == 1) {
        
        int chk;    // to store return value of function getdomain()
        
        // Call getdomain to check if it is valid
        if(chk == 1){
            printf("Not a valid input! The URL is ill-formatted; Only gov & org domain names are allowed.\n");
            return 1;
        } else {
            printf("\nThe Domain Name from the URL is: %s\n", host);
        }
    }
    
    /* EXTRACT IP ADDRESS */
    if(domORip == 0){
        
        // Call getip to get integer form of ip address
        unsigned int dec = 0;
        dec = getip(host, hostlen);
        
        // IP address should be of the form XXX.XXX.XXX.XXX where numbers are from 0-255
        if(dec == 0){
            printf("Not a valid input! The IP address is ill-formatted.\n");
            return 1;
        }
        
        /* Code to convert decimal to binary to get 32-bits representation of IP address */
        char bin[33];
        int index = 31;
        unsigned int tmp = 0;
        
        tmp = dec;
        while(index >= 0){
            bin[index] = (tmp % 2) + '0';
            tmp /= 2;
            index--;
        }
        bin[32] = '\0';

        printf("\nIP address (32-bit value): %s\n", bin);
    }
    
    /* PART B */
    
    // Initialize as required by problem
    char command[100] = "host";
    
    // Call my string concatenation function; pass by reference
    strconcatenate(command, host);

    /* BONUS PROBLEM - Alternative to system() is using pipes */
    // In this problem, we will use pipe to read from command string and write to standard output.
    
    // Intiliazing pipe and path variable
    FILE *pipe;
    char path[1500];
        
    // Open pipe for reading
    pipe = popen(command, "r");
    
    // Catch for null
    if (pipe == NULL) {
        printf("Error! Failed to get command\n" );
        exit(1);
    }
        
    // Read the output and print to stdout line by line
    while (fgets(path, sizeof(path)-1, pipe) != NULL) {
        printf("%s", path);
    }
    printf("\n");
        
    // Close pipe
    pclose(pipe);
    
    return 0;
}
