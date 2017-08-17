//
//  sorting.h
//  Created by Anjali Malik 
//
//

#ifndef sorting_h
#define sorting_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

//to store integers
typedef struct _Node{
    long value;
    struct _Node *next;
}Node;

//for multiple linked lists
typedef struct _List{
    Node *node;
    struct _List *next;
}List;

Node *Load_From_File(char *Filename);
int Save_To_File(char *Filename, Node *list);
int ListSize(Node *list);
Node *Shell_Sort(Node *list);



#endif /* sorting_h */
