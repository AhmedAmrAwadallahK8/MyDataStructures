#include <stdio.h>

#include "list_node.h"
//#include "linkedlist.h"

int main(){
    int x[1] = {2};
    /**struct List l = create_list();
    add_list_node(&l, 0);
    add_list_node(&l, 1);
    add_list_node(&l, 2);

    printf("\nNode0: %d", l.head->data);
    printf("\nNode1: %d", l.head->next_node->data);
    printf("\nNode2: %d", l.head->next_node->next_node->data);**/
    printf("\nSUS1");
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
    printf("\nType After Delete: %s", ln_get_type(test));
    

}