// @author Anjali Malik

#ifndef dotprod_header
#define dotprod_header

// define struct complex_num
typedef struct complex_num {
    float x;
    float y;
} complex_num_t;

// declare functions
complex_num_t calc_dotprod_complex(int vecsize, complex_num_t vec1[], complex_num_t vec2[]);
complex_num_t* read_vectors_complex(int vecsize, char * file);

#endif /* dotprod_header */
