
/******************************************************************************
 * File Name: Linked_List.c
 *
 * Description: Source file for the linked list
 *
 * Created on: September 11, 2019
 *
 ******************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                             *
 *******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "Linked_List.h"

/*******************************************************************************
 *                      Functions Definitions                                   *
 *******************************************************************************/




st_node** create_list(void){
    static st_node** head;
    head = (st_node**)malloc(sizeof(st_node*));
    if(head != NULL){
        *head = NULL;
        return head;
    }else{
        printf("No allocation \n");
        exit(1);
    }
}

void Insert_node(st_node** head ,int data){
    st_node* last = *head;
    st_node* new_node;

    /* */
    new_node = (st_node*) malloc(sizeof(st_node));
    if(new_node != NULL){
        /* Do NOTHING */
    }
    else
    {
        printf("No allocation \n");
        exit(1);
    }

    /* check for first node */
    if (last == NULL){
        /* head points to new(first) node */
        *head = new_node;
        /* Assigning data to new(first) node */
        new_node->Data = data;
        new_node->Next = NULL;

    }
    else
    {
        /* Searching for last node */
        while(last->Next != NULL)
            {
            last = last->Next;
            }
            last->Next = new_node;
            new_node->Data=data;
            new_node->Next = NULL;
 }

}

void Insert_to_list(st_node** head ,int data,int index)
{
    st_node* last = *head;
    st_node* new_node;
    int i,flag = 1;

    /* Create New Node */
    new_node = (st_node*)malloc(sizeof(st_node));

    /* Searching for index node */
    for(i=0;i<index-1;i++){
        if(last->Next == NULL){
           Insert_node(head , data);
            flag = -1;
            break;
        }else{
            last = last->Next;
        }
    }

    if(flag == 1){
        /* Assigning data to new inserted node */
        new_node->Data = data;
        new_node->Next = last->Next;

        /* the node previous inserted node point to the inserted node */
        last->Next = new_node;
    }

}

void print_linkedlist(st_node** head){
    st_node* last = *head;
    printf("Printing Linked List:\n");
    if (last != NULL)
    {
        printf("%d \n",last->Data);

    while(last->Next != NULL)
        {
        last = last->Next;
        printf("%d \n",last->Data);

        }
    }
    else{
    printf("NULL\n");
    }
}

int calc_LstLength(st_node ** head)
{
    st_node* last = *head;
    int count=0;

     while(last != NULL)
        {
        last = last->Next;
        count ++;
        }
    return count;
}

void find_element (st_node** head , int  num)
{

    st_node* last = *head;
    int index=0;

     while(last != NULL)
        {
        if (last->Data == num )
        {
            printf("Found element at index %d\n",index);
            return;
        }
        last = last->Next;

        index ++;
        }
          printf("Element not Found \n");
}

void delete_node(st_node **head,int index)
{
	st_node* last = *head;
    st_node* temp;
    int i,flag = 1;

    /* In Case of first index */
    if(index == 0){
        *head = last->Next;
        free(last);

    }else{

        /* Searching for index node */
        for(i=0;i<index-1;i++){
            if(last->Next == NULL){

                flag = -1;
                break;
            }else{
                last = last->Next;
            }
        }

        if(flag == 1){
            /* saving pointer to free it */
            temp = last->Next;

            /* Pre-deleted node point to the post_deleted node */
            last->Next = last->Next->Next;

            /* free deleted node */
            free(temp);
        }
    }

}
void delete_list(st_node **head)
{
	st_node* last = *head;
    st_node* temp;

    while(last->Next == NULL){
        temp = last;
        last = last->Next;
        free(temp);
    }
    /* For last element */
    temp = last;
    last = last->Next;
    free(temp);

    *head = NULL;
}

void reverse_list(st_node** head)
{
 st_node* temp = *head;
 st_node * ptr; st_node * pre_ptr;

    /* If single node */
    if (temp->Next == NULL)
    {
        pre_ptr = *head;

    /* Multi-Node */
    }
    else
    {
        /* Creating temp node */
        pre_ptr = (st_node*)malloc(sizeof(st_node));
        pre_ptr->Data = temp->Data;
        pre_ptr->Next = NULL;

        while (temp->Next != NULL) {
            ptr = (st_node*)malloc(sizeof(st_node));
            ptr->Data = (temp->Next)->Data;
            ptr->Next = pre_ptr;
            pre_ptr = ptr;
            temp = temp->Next;
      }

    }

    *head = pre_ptr;
}
