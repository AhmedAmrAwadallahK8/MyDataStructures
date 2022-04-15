#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "list_node.h"

//Create Node
struct List_Node * create_node(void *data){
    struct List_Node n_temp;
    n_temp.data = data;
    n_temp.next_node = NULL;
    struct List_Node * n = malloc(256*sizeof(int)); //For now give a static amount of memory
    n->data = data;
    n->next_node = NULL;
    return n;
}

void *get_data(struct List_Node *n){
    return n->data;
}

//Delete Unused Node
void destroy_node(struct List_Node *n){
    free(n);
}