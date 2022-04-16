#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list_node.h"

//Create Node
struct List_Node * create_node(void *data, size_t s){
    struct List_Node n_temp;
    n_temp.data = data;
    n_temp.next_node = NULL;
    struct List_Node * n = malloc(16*sizeof(int)); //For now give a static amount of memory
    n->data = malloc(s);
    memmove(n->data, data, s);
    n->next_node = NULL;
    return n;
}

void *get_data(struct List_Node *n){
    return n->data;
}

//Delete Unused Node
void destroy_node(struct List_Node *n){
    free(n->data);
    free(n);
}