//
// Created by michaelpollind on 4/13/17.
//

#ifndef TRIE_NODE_H
#define TRIE_NODE_H

typedef struct _Node{
    Node* next[sizeof(char)];
    int end;
}Node;

Node* create_node(Node* current, char key);
Node* get_node(Node* current, char key);
Node* append_node(Node* current, char key,int end);

#endif //TRIE_NODE_H
