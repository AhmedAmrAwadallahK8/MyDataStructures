#include <stdio.h>

#include "list_node.h"
#include "linkedlist.h"

int main(){
    struct List l = create_list();
    struct List_Node * n = NULL;
    int ind = 0;

    list_push_int(&l, 0);
    list_push_int(&l, 1);
    list_push_int(&l, 2);

    list_print(&l);
    printf("\nInput index: ");
    scanf("%d", &ind);

    n = list_get_ind(&l, ind);

    ln_print_node(n);
}