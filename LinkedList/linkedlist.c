#include <stddef.h>

#include "list_node.h"
#include "linkedlist.h"

/**

struct List create_list(){
    struct List l;
    l.head = NULL;
    l.len = 0;
    return l;
}



void add_list_node(struct List *l, void *data, size_t s, char ln_type[]){
    struct List_Node *curr_n;
    struct List_Node *new_n = create_node(data, s, ln_type);

    //List Is Empty
    if(l->len == 0){
        l->head = create_node(data, s, ln_type);
    }
    //List Has Atleast One Element
    else{
        curr_n = l->head;
        while(curr_n->next_node != NULL){
            curr_n = curr_n->next_node;
        }
        curr_n->next_node = new_n;
    }
    l->len++;
}

void pop_list(){

}

void rem_list_ind(){

}
**/