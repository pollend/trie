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

Node* create_node(char c);
Node* get_node(Node* current, char key);
Node* append_node(Node* current, char key,int end);

#endif //TRIE_NODE_H
