#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "list_node.h"
#include "linkedlist.h"

//Future additions
    //Replace data at index()
    //Replace data and change type that node holds
    //push functions for more types
        //structs(generic)
        //long
        //long long
        //float
        //double
        //long double



struct List create_list(){
    struct List l;
    l.head = NULL;
    l.len = 0;
    return l;
}

//Adds given node to end of list
void list_add_node(struct List *l, struct List_Node *new_n){
    struct List_Node *curr_n = l->head;
    //List Is Empty
    if(l->head == NULL){
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

//Prepares an integer node to be added to the list
void list_push_int(struct List *l, int data){
    int d[1] = {data};
    struct List_Node *new_n = ln_create_node((void*)d, sizeof(int), "int");
    list_add_node(l, new_n);
}

//Prepares a long node to be added to the list
void list_push_long(struct List *l, long data){
    long d[1] = {data};
    struct List_Node *new_n = ln_create_node((void*)d, sizeof(long), "long");
    list_add_node(l, new_n);
}

//Prepares a long long node to be added to the list
void list_push_ll(struct List *l, long long data){
    long long d[1] = {data};
    struct List_Node *new_n = ln_create_node((void*)d, sizeof(long long), "long long");
    list_add_node(l, new_n);
}

//Prepares a float node to be added to the list
void list_push_float(struct List *l, float data){
    float d[1] = {data};
    struct List_Node *new_n = ln_create_node((void*)d, sizeof(float), "float");
    list_add_node(l, new_n);
}

//Prepares a double node to be added to the list
void list_push_double(struct List *l, double data){
    double d[1] = {data};
    struct List_Node *new_n = ln_create_node((void*)d, sizeof(double), "double");
    list_add_node(l, new_n);
}

//Prepares a long double node to be added to the list
void list_push_ld(struct List *l, long double data){
    long double d[1] = {data};
    struct List_Node *new_n = ln_create_node((void*)d, sizeof(long double), "long double");
    list_add_node(l, new_n);
}

//Prepares a bool node to be added to the list
void list_push_bool(struct List *l, bool data){
    bool d[1] = {data};
    struct List_Node *new_n = ln_create_node((void*)d, sizeof(bool), "bool");
    list_add_node(l, new_n);
}

//Prepares a char node to be added to the list
void list_push_char(struct List *l, char data){
    char d[1] = {data};
    struct List_Node *new_n = ln_create_node((void*)d, sizeof(char), "char");
    list_add_node(l, new_n);
}

//Prepares a string node to be added to the list
void list_push_string(struct List *l, char data[]){
    int str_len = strlen(data);

    //Code for specifying exact size of string(Disabled for now and requires adjustments in ln_print_node if enabled)
    /**char type[16] = "";
    char type_p1[6] = "char[";
    char type_p2[10] = "";
    char type_p3[2] = "]";
    sprintf(type_p2, "%d", str_len);
    strncat(type, type_p1, 5);
    strncat(type, type_p2, 9);
    strncat(type, type_p3, 1);**/

    struct List_Node *new_n = ln_create_node((void*)data, sizeof(char)*(str_len+1), "char[]");
    list_add_node(l, new_n);
}

//Print List
void list_print(struct List *l){
    struct List_Node *curr_n = l->head;

    while(curr_n != NULL){
        ln_print_node(curr_n);
        curr_n = curr_n->next_node;
    }
    printf("\n");
}

//Remove tail node in list
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

//Get pointer to specified index node
struct List_Node * list_get_ind(struct List *l, int get_ind){
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
    return NULL;
}

//Remove Specific Index
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


