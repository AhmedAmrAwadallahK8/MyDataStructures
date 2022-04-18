#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "list_node.h"

//Future additions
    //ln_print_node() is able to handle the following types
        //structs(generic)
    //Get function

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

//Get pointer to data
void *ln_get_data(struct List_Node *n){
    return n->data;
}

//Get type description
char *ln_get_type(struct List_Node *n){
    return n->type;
}

//Print contents of node
void ln_print_node(struct List_Node *n){
    void * data_ptr;
    char curr_type[20];

    strcpy(curr_type, ln_get_type(n));
    data_ptr = ln_get_data(n);
    //Node contains int type
    if(strcmp(curr_type,"int") == 0){
        int int_data = *(int*)data_ptr;
        printf("\nType: %s Data: %d", curr_type, int_data);
    }
    else if(strcmp(curr_type,"long") == 0){
        long long_data = *(long*)data_ptr;
        printf("\nType: %s Data: %ld", curr_type, long_data);
    }
    else if(strcmp(curr_type,"long long") == 0){
        long long ll_data = *(long long*)data_ptr;
        printf("\nType: %s Data: %lld", curr_type, ll_data);
    }
    else if(strcmp(curr_type,"float") == 0){
        float float_data = *(float*)data_ptr;
        printf("\nType: %s Data: %f", curr_type, float_data);
    }
    else if(strcmp(curr_type,"double") == 0){
        double double_data = *(double*)data_ptr;
        printf("\nType: %s Data: %f", curr_type, double_data);
    }
    else if(strcmp(curr_type,"long double") == 0){
        long double ld_data = *(long double*)data_ptr;
        printf("\nType: %s Data: %Lf", curr_type, ld_data);
    }
    else if(strcmp(curr_type, "bool") == 0){
        bool bool_data = *(bool*)data_ptr;
        printf("\nType: %s Data: %s", curr_type, bool_data?"true":"false");
    }
    else if(strcmp(curr_type, "char") == 0){
        char char_data = *(char*)data_ptr;
        printf("\nType: %s Data: %c", curr_type, char_data);
    }
    //Node contains character array type(string)
    else if(strcmp(curr_type,"char[]") == 0){
        char *str_data = (char*)data_ptr;
        printf("\nType: %s Data: %s", curr_type, str_data);
    }
    //Node contains type that hasn't been programmed with any print behavior
    else{
        printf("\nType: %s Data: Data printing for this type is unspecified", curr_type);
    }

}

//Free memory associated with node
void ln_free_node(struct List_Node *n){
    free(n->data);
    free(n);
}