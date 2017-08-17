/* 	version 8 of z = x + y */

/* bonus */
#include <stdio.h>

void myadd(float *, float *, float *);

int main() 
{
float x, y, z;

// read input
  scanf("%f %f", &x, &y);

// compute addition
  myadd(&x, &y, &z);

// print result
  printf("result of %f + %f = %.2f\n", x, y, z);

}


/*	function myadd(*a,*b, *c) takes three
	arguments of type float *, adds them */

void myadd(float *a, float *b, float *c)
{
// add argument a to argument b
// and store the result in local variable c
  *c = *a + *b;

}
