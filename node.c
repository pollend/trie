//
// Created by michaelpollind on 4/13/17.
//
#include "node.h"

Node* create_node()
{
    Node* n = calloc(1,sizeof(Node));
    n->end = 0;
    return  n;
}

Node* get_node(Node* current, char key)
{
    return current->next[key];
}

Node* append_node(Node* current, char key,int end)
{
    Node* n = create_node();
    current[key] = n;
    n->end = end;
    return  n;
}
