#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list_node.h"

//Create Node
struct List_Node * ln_create_node(void *data, size_t s, char ln_type[]){
    struct List_Node * n = malloc(256*sizeof(int)); //For now give a static amount of memory
    //Allocate heap memory and copy the parameter data
    n->data = malloc(s);
    memcpy(n->data, data, s);

    //Default next node to be null
    n->next_node = NULL;

    //Type Description
    strcpy(n->type, ln_type);
    return n;
}

void *ln_get_data(struct List_Node *n){
    return n->data;
}

char *ln_get_type(struct List_Node *n){
    return n->type;
}

//Delete Unused Node
void ln_free_node(struct List_Node *n){
    free(n->data);
    free(n);
}