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
    printf("\n");
}

void list_pop(struct List *l){
    struct List_Node *curr_n = l->head;
    struct List_Node *next_n = curr_n->next_node;
    //Empty List Just Return
    if(curr_n == NULL){return; }
    //Find the tail node
    while(next_n->next_node!=NULL){
        curr_n = curr_n->next_node;
        next_n = next_n->next_node;
    }
    //Free memory belonging to tail node
    ln_free_node(next_n);
    //Dereference pointer to removed node
    curr_n->next_node = NULL;
    //Decrement list size by 1
    l->len--;

}

struct List_Node * list_get_node(struct List *l, int get_ind){
    struct List_Node *curr_n = l->head;
    int curr_ind = 0;

    //List index is out of range
    if((get_ind >= l->len) | (get_ind < 0)){printf("\nIndex out of bounds"); }
    else{
        while(curr_ind != get_ind){
            curr_n = curr_n->next_node;
            curr_ind++;
        }  
        return curr_n;
    }
}

void list_rem_ind(struct List *l, int rem_ind){
    struct List_Node *curr_n = l->head;
    struct List_Node *next_n = curr_n->next_node;
    struct List_Node *free_n = NULL;
    int curr_ind = 0;

    //List index is out of range
    if((rem_ind >= l->len) | (rem_ind < 0)){printf("\nIndex out of bounds"); }

    //Remove final Element
    if(rem_ind == (l->len - 1)){list_pop(l); }
    //Remove first element
    else if(rem_ind == 0){
        l->head = next_n;
        ln_free_node(curr_n);
    }
    //Somewhere in between
    else{
        //Find node to remove
        while(curr_ind != (rem_ind-1)){
            curr_n = curr_n->next_node;
            next_n = next_n->next_node;
        }
        //Handle pointers
        free_n = next_n;
        curr_n->next_node = next_n->next_node;

        //Free and decrement list length
        ln_free_node(free_n);
        l->len--;
    }
}
