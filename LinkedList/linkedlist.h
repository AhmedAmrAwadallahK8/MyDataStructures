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
void add_list_node(struct List *l, void *data, size_t s, char ln_type[]);

#endif