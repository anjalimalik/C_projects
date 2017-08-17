//
//  sorting.c
//  
//
//  Created by Anjali Malik
//
//

#include "sorting.h"

#include <math.h>

long* Load_From_File(char* Filename, int *Size)
{
    FILE * file = fopen(Filename, "rb");
    
    int bfsize, size_first, size_last;
    
    fseek(file, 0, SEEK_END);
    size_first = ftell(file);
    size_last = fseek(file, 0, SEEK_SET);
    
    bfsize = size_first;
    
    int numsize = bfsize/(sizeof(long));
    *Size = numsize;
    
    long* long_arr = malloc(((int)numsize)*sizeof(long));
    
    if(numsize == 0) {
        *Size = 0;
        
        return long_arr;
    }
    else {
        fread(long_arr, sizeof(long), numsize, file);
        rewind(file);
    }
    fclose(file);
    
    return long_arr;
        
}

int Save_To_File(char *Filename, long *Array, int Size)
{
    // Edge Case
    if (Size == 0) {
        fopen(Filename,"wb");
        return 0;
    }
    int num_arr = 0;
    
    FILE *file = fopen(Filename, "wb");
    num_arr = fwrite(Array, sizeof(long), sizeof(Array), file);
    
    fclose(file);
    free(Array);
    return num_arr;
    
}

int* sequencearray(int Size)
{
    int count = 0, p = 0, q = 0, m = 0;
    int num = 0;
    
    int* seq = malloc(Size*sizeof(int));
    while(1) {
        p = m;
        q = 0;
        while(p >= 0) {
            num = pow(2,p) * pow(3,q);
            if (num >= Size) {
                break;
            }
            p--;
            q++;
            seq[count] = num;
            count++;
        }
        m++;
        
    }
    
    return seq;
}

int countarray(int Size)
{
    int count = 0, p = 0, q = 0, m = 0;
    int num = 0;
    
    
    while(1) {
        p = m;
        q = 0;
        while(p >= 0) {
            num = pow(2, p) * pow(3,q);
            if (num >= Size) {
                break;
            }
            p--;
            q++;
            
            count++;
        }
        m++;
        
    }
    return count;
}


void Shell_Insertion_Sort(long *Array, int Size, double* N_Comp, double* N_Move)
{
    int* seq_array = sequencearray(Size);
    int length = countarray(Size);
    int gap, i, j, tmp = 0;
    int p = 1;
    gap = seq_array[length-p];
    while(1) {
        if (gap <=0) {
            break;
        }
        for(i = gap; i < length; i++) {
            tmp = Array[i];
            for(j = i; ((j >= gap) && tmp < (Array[j-gap])); j = j-gap ) {
                //Swap
                Array[j] = Array[j-gap];
                (*N_Comp)++;
                (*N_Move)++;
            }
            
            (*N_Comp)++;
            Array[j] = tmp;
            *N_Move += 2;
        
        }
        p++;
        gap = seq_array[length - p];
    }
        
    free(seq_array);
}

void Shell_Selection_Sort(long *Array, int Size, double *N_Comp, double *N_Move)
{
    int current, swap = 0;
    int* seq_array = sequencearray(Size);
    int length = countarray(Size);
    int gap, i, j;
    int p = 1;
    gap = seq_array[length-p];
    while(1) {
        if (gap <= 0) {
            break;
        }
        for (i = 0; i < Size - 1; i++) {
            current = i;
            for (j = i + 1; j < Size; j++)
            {
                if(Array[current] > Array[j]) {
                    current = j;
                    (*N_Comp)++;
                }
                if(current != i)
                {
                    swap = Array[i];
                    Array[i] = Array[current];
                    Array[current] = swap;
                    *N_Move += 3;
                }
            }
            
        }
        p++;
        gap = seq_array[length - p];
    }
        free(seq_array);
}

int Print_Seq(char* Filename, int Size)
{
    // Edge Case
    if (Size == 0 || (Size == 1)) {
        fopen(Filename,"w+");
        return 0;
    }
    
    FILE *fn_output = fopen(Filename,"w+");
    
    int count = 0, p = 0, q = 0, m = 0;
    int num = 0;
    
    while(1) {
        p = m;
        q = 0;
        while(p >= 0) {
            num = pow(2,p) * pow(3,q);
            if (num >= Size) {
                break;
            }
            p--;
            q++;
            fprintf(fn_output, "%d\n", num);
            count++;
        }
        m++;
        
    }
    return count;
}

