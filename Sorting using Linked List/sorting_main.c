//
//  sorting_main.c
//  Created by Anjali Malik
//
//
#include "sorting.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int main(int argc, char** argv)
{
    clock_t input = clock();        //start io time
    
    char* infile = argv[1];         //input file
    char* outfile = argv[2];        //output file
    double sortingtime, iotime;     //computation time variables
    Node *head = NULL;              //used for freeing memory
    int num = 0;
    Node *inlist = Load_From_File(infile); //loading unsorted list from input file
    
    //sorting inlist
    clock_t start = clock();               //start sorting time
    Node *outlist = Shell_Sort(inlist);    //sorted linked list
    clock_t end = clock();                 //end sorting time
    
    num = Save_To_File(outfile, inlist);      //saving sorted list to output text file
    clock_t output = clock();           //end io time
    
    //calculating sorting time
    sortingtime = (double)(end - start) / CLOCKS_PER_SEC;
    //calculating i/o time
    iotime = (double)(output - input - sortingtime) / CLOCKS_PER_SEC;
    
    //print statements

    printf("\nI/O time: %le\n", iotime);
    printf("Sorting time: %le\n\n", sortingtime);
    
    //free memory of list 'inlist'
    free(inlist);
    
    //free memory of linked list 'outlist'
    while(outlist != NULL) {
        head = outlist;
        free(head);
        outlist = outlist->next;
    }
    
    return 0;
}
