//
// Created by michaelpollind on 4/13/17.
//

#ifndef TRIE_NODE_H
#define TRIE_NODE_H

typedef struct Node Node;
typedef struct Entries Entries;

typedef struct Entries{
    char key;
    Node* next_node;
    struct Entries* next_entry;
};

typedef struct Node{
    Entries* entry;
    int end;
};

Node* create_node();
Node* get_node(Node* current, char key);
Node* node_try_next(Node* current, char key);

Entries* node_entry_match(char key,Node* node);
void _add_entry(char key,Node* node,Node* next);
Entries* node_root_entry(Node* n);
Entries* next_entry(Entries* e);

#endif //TRIE_NODE_H
