#include <stdio.h>

#include "list_node.h"
//#include "linkedlist.h"

int main(){
    /**struct List l = create_list();
    add_list_node(&l, 0);
    add_list_node(&l, 1);
    add_list_node(&l, 2);

    printf("\nNode0: %d", l.head->data);
    printf("\nNode1: %d", l.head->next_node->data);
    printf("\nNode2: %d", l.head->next_node->next_node->data);**/

    struct List_Node * test = create_node((void*)2);
    void * td = get_data(test);

    printf("\nCheck After Creation: %d", *(int*)td);

    destroy_node(test);
    
    printf("\nCheck After Delete: %d", *(int*)td);
    

}