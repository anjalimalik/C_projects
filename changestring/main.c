// @author Anjali Malik

#include <stdio.h>

int main()  {
	
	char string[100];                   
	int n = 0;                          
	char c;

    while((c = getchar()) != '\n') {
		string[n] = c;
		n++;
	}
	string[n] = '\0';

	for(int i = 0; i < n; i++){
		if(string[i] >= 'A' && string[i] <= 'Z'){
			string[i] += 32;
		} else if (string[i] >= 'a' && string[i] <= 'z'){
			string[i] -= 32;
		} else if (string[i] >= '0' && string[i] <= '9'){
			string[i] += 17;
		} else {
			string[i] = 32;
		}
	}
    
	printf("%s\n", string);

	return EXIT_SUCCESS;
}

