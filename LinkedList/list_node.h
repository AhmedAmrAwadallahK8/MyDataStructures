#ifndef LIST_NODE_H
#define LIST_NODE_H

struct List_Node{
    void *data;
    char type[20];
    struct List_Node *next_node;
};

struct List_Node * ln_create_node(void *data, size_t s, char ln_type[]);

void *ln_get_data(struct List_Node *n);

char *ln_get_type(struct List_Node *n);

void ln_free_node(struct List_Node *n);

#endif