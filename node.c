//
// Created by michaelpollind on 4/13/17.
//
#include "node.h"
#include <stdlib.h>


Node* create_node(char c)
{
    Node* n = (Node*)calloc(1,sizeof(Node));
    return  n;
}

Node* get_node(Node* current, char key)
{
    return current->next;
}

Node* append_node(Node* current, char key,int end)
{
    Node* n = create_node();
    if(n->entries == NULL)
    {
        current->entry = calloc(1,sizeof(Entries));
        current->entry->key = key;
        current->entry->next_node = n;
    }
    else
    {

    }

    current->next[key] = n;
    n->end = end;
    return  n;
}
