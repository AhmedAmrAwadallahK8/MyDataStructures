#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include "list_node.h"

struct List{
    struct List_Node *head;
    int len;
};

//Creates Empty List
struct List create_list();

//Adds New Node to List
void list_push_int(struct List *l, int data);

//Print List
void list_print(struct List *l);

//Remove tail node in list
void list_pop(struct List *l);

//Remove Specific Index
void list_rem_ind(struct List *l, int rem_ind);

#endif