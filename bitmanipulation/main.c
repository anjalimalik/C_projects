// @author Anjali Malik


// Largest value that can be stored in unsigned int is 4,294,967,295 (or 0xFFFFFFFF in hex)
// Tested: This code can correctly store and output the bits of 4,294,967,295

#include <stdio.h>
#include <string.h> // for strrev

int main() {
    
    // Initialize local variables
    unsigned int num = 0;
    unsigned mask;
    unsigned masklast4;
    unsigned shift;
    int i = 0;
    
    // Store the input integer into num
    scanf("%u", &num);
    
    char b[33];
    unsigned int tmp;
    int index = 31;
    
    tmp = num;
    while(index >= 0){
        b[index] = (tmp % 2) + '0';
        tmp /= 2;
        index--;
    }
    b[32] = '\0';
    printf("%s", b);

    // Mask all bits except the last 4
    mask = (num & 15);
    
    // Print out the value of least significant 4 bits in dec and hex
    printf("\n%u, %02x\n", mask, mask);
    
    // Mask the last 4 bits
    masklast4 = (num & 0xFFFFFFF0);
    shift = masklast4;

    // Loop to right shift 4 bits at a time (7 times for 28 bits)
    for ( i = 0; i < 7; i++){
        shift = (shift >> 4);       // Right shift
        mask = (shift & 0xF);       // Mask each time to get least significant 4 bits
        printf("%u, %02x\n", mask, mask);
    }
    
    return 0;
}
