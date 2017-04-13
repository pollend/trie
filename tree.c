//
// Created by michaelpollind on 4/13/17.
//
#include "tree.h"

void addEntry(char* input,Tree* tree)
{
    Node* current = tree->root;
    int length = strlen(input);
    for(size_t x = 0; x < length; x++)
    {
        Node* temp = get_node(current,input[x]);
        if(temp == 0)
            current = append_node(current,input[x],-1);
        else
            current = temp;
    }
    current->end = 1;

}
void find_all_matching(result* func)
{
}



