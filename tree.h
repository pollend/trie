//
// Created by michaelpollind on 4/13/17.
//

#ifndef TRIE_TREE_H
#define TRIE_TREE_H

#include "node.h"

typedef void (*result)(char* output);

typedef struct _tree{
    Node* root;
} Tree;

void addEntry(char* input,Tree* tree);
void find_all_paritial_matches(Tree* tree,char* match,result func);
Tree* load_file(char* file);

void _walk_node(result func,char* str_part,Node* n);


#endif //TRIE_TREE_H
