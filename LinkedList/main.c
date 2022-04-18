#include <stdio.h>

#include "list_node.h"
#include "linkedlist.h"

int main(){
    struct List l = create_list();
    int ind = 0;

    list_push_int(&l, 0);
    list_push_int(&l, 1);
    list_push_int(&l, 2);

    list_print(&l);
    printf("\nInput index to remove: ");
    scanf("%d", &ind);
    list_rem_ind(&l, ind);

    list_print(&l);


    /**printf("\nNode0: %d", *(int*)l.head->data);
    printf("\nNode1: %d", *(int*)l.head->next_node->data);
    printf("\nNode2: %d", *(int*)l.head->next_node->next_node->data);**/


    /**printf("\nSUS1");
    struct List_Node * test = ln_create_node((void*)x, sizeof(int), "int");
    x[0] = 3;
    printf("\nSUS1 GOOD");
    printf("\nSUS2");
    void * td = ln_get_data(test);
    printf("\nSUS2 GOOD");

    printf("\nCheck After Creation: %d", *(int*)td);
    printf("\nCheck After Creation: %p", test);
    printf("\nType After Creation: %s", ln_get_type(test));

    ln_destroy_node(test);
    td = ln_get_data(test);
    printf("\nCheck After Delete: %d", *(int*)td);
    printf("\nCheck After Delete: %p", test);
    printf("\nType After Delete: %s", ln_get_type(test));**/
    

}