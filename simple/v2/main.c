// Pointers and arrays
#include <stdio.h>

void main()
{
  // Changing initialization h to an array which contains three desired values 
  // *h now points to the firt element of h array
  int h[] = {100, 200, 300};
  
  // Using pointer arithmetic to print array elements of desired values
  // no change to code
  printf("%d\n",*h);		
  printf("%d\n",*(h+1));	
  printf("%d\n",*(h+2));	

}
