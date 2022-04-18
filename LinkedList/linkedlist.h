#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include "list_node.h"

struct List{
    struct List_Node *head;
    int len;
};

//Creates Empty List
struct List create_list();

//Adds given node to end of list
void list_add_node(struct List *l, struct List_Node *new_n);

//Prepares an integer node to be added to the list
void list_push_int(struct List *l, int data);

//Prepares a long node to be added to the list
void list_push_long(struct List *l, long data);

//Prepares a long long node to be added to the list
void list_push_ll(struct List *l, long long data);

//Prepares a float node to be added to the list
void list_push_float(struct List *l, float data);

//Prepares a double node to be added to the list
void list_push_double(struct List *l, double data);

//Prepares a long double node to be added to the list
void list_push_ld(struct List *l, long double data);

//Prepares a bool node to be added to the list
void list_push_bool(struct List *l, bool data);

//Prepares a char node to be added to the list
void list_push_char(struct List *l, char data);

//Prepares a string node to be added to the list
void list_push_string(struct List *l, char data[]);

//Print List
void list_print(struct List *l);

//Remove tail node in list
void list_pop(struct List *l);

//Get pointer to specified index node
struct List_Node * list_get_ind(struct List *l, int get_ind);

//Remove Specific Index
void list_rem_ind(struct List *l, int rem_ind);

#endif