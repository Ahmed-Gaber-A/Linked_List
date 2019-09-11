/******************************************************************************
 * File Name: Linked_List.h
 *
 * Description: Header file for the linked list
 *
 * Created on: September 11, 2019
 *
 ******************************************************************************/

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>



/*******************************************************************************
 *                         Configurations Structure                            *
 *******************************************************************************/
 typedef struct ST_Node{
    int Data;
    struct ST_Node* Next;
} st_node;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


st_node** create_list(void);

void Insert_node(st_node**,int data);

void Insert_to_list(st_node**,int data,int index);

void print_linkedlist(st_node**);

int calc_LstLength (st_node**);

void find_element (st_node**, int );

void delete_node (st_node** ,int index );

void delete_list (st_node**);

void reverse_list(st_node**);

#endif /* LINKED_LIST_H_ */
