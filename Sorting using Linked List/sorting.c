//
//  sorting.c
//  Created by Anjali Malik
//
//


#include "sorting.h"

Node *Load_From_File(char *Filename)
{
    long value = 0;         //value of node
    Node *first = NULL;      //first node of the list
    Node *second = NULL;    //second node of the list
    Node *rest = NULL;      //rest of the list
    
    //open and read input file
    FILE *infile = fopen(Filename, "r");
    
    //edge case
    if(infile == NULL) {
        return 0;
    }
    
    //creating the initial linked list
    if(!feof(infile)) {
            
        fscanf(infile, "%ld", &value);
        first->value = value;
        first->next = NULL;
    }
    
    if(!feof(infile)) {
        
        fscanf(infile, "%ld", &value);
        second->value = value;
        second->next = NULL;
        
        first->next = second;
    }
    while(fscanf(infile, "%ld", &value) != EOF) {
        
        rest->value = value;
        rest->next = NULL;
        
        second->next = rest;
        second = second->next;
        
    }
    
    fclose(infile);
    return first;
    
}

int Save_To_File(char *Filename, Node *list)
{
    
    FILE *outfile = fopen(Filename, "w");  //opening file for writing
    int num = 0;                            //number of times file is written
    
    //edge case
    if(outfile == NULL) {
        return 0;
    }
    
    //writing long integers from linked list to file
    while(list != NULL) {
        fprintf(outfile, "%ld\n", list->value);
        list = list->next;
        ++num;
    }
    
    fclose(outfile);
    return num;
}

int ListSize(Node *list)
{
    int size = 0;       //size of the list
    
    //finding out size of the linked list
    while(list != NULL) {
        ++size;
        list = list->next;
    }
    return size;
}

Node *Shell_Sort(Node *list)
{
    int size = ListSize(list);        //size of the list
    int pq = 1;                               //variable for sequence
    int levels = 0;                          //number of levels in the sequence triangle
    /* int seq = 1;                             //number of elements in the sequence */
    int i = 0;                               //index used for transversing
    int interval = 0;                        //interval for shell sorting
    
    //decalaration of different nodes at different locations in the linked list, in order to manipulate to change their pointers/addresses
    Node *node1 = list;
    Node *tmp = NULL;
    int tmpgap = 0; //used for transversing
    Node *node2 = NULL;
    Node *node3 = NULL;
    Node *node4 = NULL;
    Node *node5 = NULL;
    Node *node6 = NULL;

    
    //finding out number of levels in the triangle (*3 because using right side of the triangle)
    while(pq < size) {
        ++levels;
        pq *= 3;
    }
    
    /* //finding out number of elements in the sequence
    for(int j =levels; j >= 0; j--) {
        seq += j;
    } */
    
    //outer loop for levels from down to up in the triangle
    while(levels > 0) {
        
        pq /= 3;       //iterating to move up the levels
        interval = pq; //using sequence for setting intervals
        
        //inner loop for elements on level from right to left in the triangle
        for(i = levels; i > 0; i--) {
            Node* head = node1;
            while(node1 != NULL) {
                tmp = node1;
                tmpgap = interval;
                
                while(tmp != NULL && tmpgap > 0) {
                    --tmpgap;
                    node4 = tmp;
                    tmp = tmp->next;
                }

                node5 = tmp;
                node6 = node5->next;
                // Case 1 - head, no previous nodes
                if (node1 == head) {
                    node2 = node1;
                    node3 = node2->next;
                    while(node2 < node5) {
                        //Swap
                        node2->next = node6;
                        node5->next = node3;
                        node4->next = node2;
                    }
                }
                
                // Case 2 - if node1 is not the head
                else {
                    node3 = node2->next;
                    while(node2<node5) {
                        //Swap
                        node2->next = node6;
                        node5->next = node3;
                        node4->next = node2;
                        node1->next = node5;

                    }
                }
                node1 = node1->next;
            }
            
            //moving from right to left in the sequence (descending)
            interval = (interval / 3) * 2;
        }
        
        //move to upper level of sequence
        --levels;
    }
    
    return list;
    
}

