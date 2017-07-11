
// @author Anjali Malik

#include <stdio.h>
#include <stdlib.h>

int main() {


	size_t size_int = sizeof(int);
	size_t size_char = sizeof(char);
	size_t size_float = sizeof(float);
	size_t size_double = sizeof(double);

	size_t size_short_int = sizeof(short);
    size_t size_long_int = sizeof(long);

	printf("Size of Int: %zu", size_int);
	printf("\nSize of Char: %zu", size_char);
	printf("\nSize of Float: %zu", size_float);
	printf("\nSize of Double: %zu", size_double);
    
	printf("\nSize of Short Int: %zu", size_short_int);
	printf("\nSize of Long Int: %zu\n", size_long_int);
    
    return EXIT_SUCCESS;

}
