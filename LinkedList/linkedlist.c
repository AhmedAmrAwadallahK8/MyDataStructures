#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include "list_node.h"
#include "linkedlist.h"



struct List create_list(){
    struct List l;
    l.head = NULL;
    l.len = 0;
    return l;
}



void list_push_int(struct List *l, int data){
    int d[1] = {data};
    struct List_Node *curr_n = l->head;
    struct List_Node *new_n = ln_create_node((void*)d, sizeof(int), "int");

    //List Is Empty
    if(l->len == 0){
        l->head = new_n;
    }
    //List Has Atleast One Element
    else{
        while(curr_n->next_node != NULL){
            curr_n = curr_n->next_node;
        }
        curr_n->next_node = new_n;
    }
    l->len++;
}

void list_print(struct List *l){
    struct List_Node *curr_n = l->head;
    void * data_ptr;
    int index = 0;
    char curr_type[20];

    while(curr_n != NULL){
        strcpy(curr_type, ln_get_type(curr_n));
        data_ptr = ln_get_data(curr_n);
        //Node contains int type
        if(strcmp(curr_type,"int") == 0){
            int int_data = *(int*)data_ptr;
            printf("\nType: %s Data: %d", curr_type, int_data);
        }
        //Node contains type that hasn't been programmed with any print behavior
        else{
            printf("\nType: %s Data: Data printing for this type is unspecified", curr_type);
        }
        curr_n = curr_n->next_node;
    }


}
void list_pop(struct List *l){

}

void list_rem_ind(struct List *l){

}
