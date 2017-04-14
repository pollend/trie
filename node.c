//
// Created by michaelpollind on 4/13/17.
//
#include "node.h"
#include <stdlib.h>
#include <printf.h>


Node* create_node()
{
    Node* n = (Node*)calloc(1,sizeof(Node));
    return  n;
}

Node* get_node(Node* current, char key)
{
    Entries* next = node_entry_match(key,current);
    if(next == NULL)
        return  NULL;
    return next->next_node;
}


void _add_entry(char key,Node* node,Node* next)
{
    Entries* temp =  node->entry;
    node->entry = calloc(1,sizeof(Entries));
    node->entry->key = key;
    node->entry->next_entry = temp;
    node->entry->next_node = next;
}



Entries* node_entry_match(char key,Node* node)
{
    if(node->entry == NULL)
        return  NULL;

    Entries* current_entry = node->entry;
    while (1)
    {
        if(current_entry == NULL)
            return NULL;
        if(current_entry->key == key)
            return current_entry;
        current_entry = current_entry->next_entry;
    }
}

Node* node_try_next(Node* current, char key)
{
    Entries* entry = node_entry_match(key,current);
    if(entry == NULL)
    {
        Node* c = create_node();
        _add_entry(key,current,c);
        c->end = 0;
        return c;
    }
    else
    {
        return entry->next_node;
    }
}

Entries* node_root_entry(Node* n)
{
    return  n->entry;
}
