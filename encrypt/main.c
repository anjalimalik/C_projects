// @author Anjali Malik


#include <stdio.h>
#include <stdlib.h>

void myencrypt(int, FILE *, FILE *);

int main(int argc, char *argv[]) {
    

    int N = strtol(argv[1], NULL, 10);
    

    FILE *fp1;
    FILE *fp2;
    
    if((fp1 = fopen(argv[2], "r")) == NULL){
        fprintf(stderr,"file does not exist\n");
        exit(1);
    }
    
    
    if((fp2 = fopen(argv[3], "w")) == NULL){
        fprintf(stderr,"creating write file failed\n");
        exit(1);
    }
    
    
    myencrypt(N, fp1, fp2);
    
    
    fclose(fp1);
    fclose(fp2);
    
    return EXIT_SUCCESS;

}

void myencrypt(int N, FILE *fp1, FILE *fp2) {
    
    
    char c = getc(fp1);
    int sum = 0;                    
    char new;
   
    while(c != EOF){
        
        sum = c + N;
        
        if((sum <= 127) && (sum >= 0)) {
            new = sum;              // This is when the sum is between 7-bit ASCII range 0-127
            putc(new, fp2);
        } else if (sum > 127){
            new = sum - 127;        // This is when the sum is greater than 127, it wraps around
            putc(new, fp2);
        } else if (sum < 0) {
            new = sum + 127;        // This is when N is negative (during decryption) and sum is negative
            putc(new, fp2);
        }
        
        c = getc(fp1);              // Get new character from input file to iterate
    }
}
