#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list_node.h"
#include "linkedlist.h"

int main(){
    struct List l = create_list();
    struct List_Node * n = NULL;
    struct List_Node * h = NULL;
    struct List_Node * m = NULL;
    struct List_Node * t = NULL;
    int ind = 0;
    int *ptr = NULL;
    int mem_wipe_c = 0;

    list_push_int(&l, 0);
    list_push_int(&l, 1.);
    list_push_int(&l, 2);
    list_push_string(&l, "Hello World");
    list_push_char(&l, 'a');
    list_push_bool(&l, true);
    list_push_long(&l, 10);
    list_push_ll(&l, 100);
    list_push_float(&l, 10.0);
    list_push_double(&l, 100.0);
    list_push_ld(&l, 1000.0);

    list_print(&l);
    /**get ind testing code
    printf("\nInput index: ");
    scanf("%d", &ind);

    n = list_get_ind(&l, ind);

    ln_print_node(n);**/

    h = list_get_ind(&l, 0);
    m = list_get_ind(&l, 4);
    t = list_get_ind(&l, 10);

    printf("\nStorage before freeing memory of the head, node in the middle, and tail");
    ln_print_node(h);
    ln_print_node(m);
    ln_print_node(t);

    list_free_list(&l);
    printf("\n\nInput Memory Number to Wipe: ");
    scanf("%d", &mem_wipe_c);
    ptr = calloc(mem_wipe_c, sizeof(int));

    printf("\nStorage after freeing memory of the head, node in the middle, and tail");
    ln_print_node(h);
    ln_print_node(m);
    ln_print_node(t);

    
    free(ptr);
    printf("\n");
    list_print(&l);
    /** Index removal testing code
    printf("\nInput index: ");
    scanf("%d", &ind);

    list_rem_ind(&l, ind);

    ln_print_node(n);**/

    //Replacement Testing Code
    /**printf("\nHead Replacement test");
    list_replace_int(&l, 4, 0);
    list_print(&l);

    printf("\nMiddle Replacement test");
    list_replace_int(&l, 5, 1);
    list_print(&l);

    printf("\nTail Replacement test");
    list_replace_int(&l, 6, 10);
    list_print(&l);

    printf("\nString Replacement test");
    list_replace_string(&l, "Hello World", 2);
    list_print(&l);

    printf("\nChar Replacement test");
    list_replace_char(&l, 'a', 2);
    list_print(&l);

    printf("\nBool Replacement test");
    list_replace_bool(&l, true, 2);
    list_print(&l);

    printf("\nLong Replacement test");
    list_replace_long(&l, 10, 2);
    list_print(&l);

    printf("\nLong Long Replacement test");
    list_replace_ll(&l, 100, 2);
    list_print(&l);

    printf("\nFloat Replacement test");
    list_replace_float(&l, 10.0, 2);
    list_print(&l);

    printf("\nDouble Replacement test");
    list_replace_double(&l, 100.0, 2);
    list_print(&l);

    printf("\nLong Double Replacement test");
    list_replace_ld(&l, 1000.0, 2);
    list_print(&l);**/

    exit(EXIT_SUCCESS);
}