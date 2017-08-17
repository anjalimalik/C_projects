//
//  sorting_main.c
//  
//
//  Created by Anjali Malik
//

#include <time.h>
#include<limits.h>
#include <stdio.h>
#include<string.h>
#include "sorting.h"

int main(int argc, char** argv) {
    
    clock_t input = clock();
    
    char* sort_sel = argv[1];
    char* inp_fName = argv[2];
    char* seq_tName = argv[3];
    char* out_fName = argv[4];
    
    int Size = 0;
    long* loaded_arr = Load_From_File(inp_fName, &Size);
    
    double sortingtime, iotime;
    double N_Comp = 0;
    double N_Move = 0;
    
    clock_t start = clock();
    if (strcmp(sort_sel,"i") == 0) {
        Shell_Insertion_Sort(loaded_arr, Size, &N_Comp, &N_Move);
    }
    else if (strcmp(sort_sel,"s") == 0) {
        Shell_Selection_Sort(loaded_arr, Size, &N_Comp, &N_Move);
    }
    clock_t end = clock();
    
    sortingtime = (double)(end - start)/ CLOCKS_PER_SEC;
    
    int lenseq = Print_Seq(seq_tName, Size);
    
    int stored_num  = Save_To_File(out_fName, loaded_arr, Size);
    
    clock_t output = clock();
    iotime = (double)(output - input)/CLOCKS_PER_SEC;
    
    printf("Number of long integers read: %d\n", Size);
    printf("Number of long integers stored: %d\n", stored_num);
    printf("Length of sequence: %d\n", lenseq);
    printf("Number of comparisons: %le\n", N_Comp);
    printf("Number of moves: %le\n", N_Move);
    printf("I/O time: %le\n", iotime);
    printf("Sorting time: %le\n", sortingtime);
    
    return 0;
    
}
