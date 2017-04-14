//
// Created by michaelpollind on 4/13/17.
//
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void addEntry(char* input,Tree* tree)
{
    Node* current = tree->root;
    size_t length = strlen(input);
    for(size_t x = 0; x < length; x++)
    {
        current = node_try_next(current,input[x]);
    }
    current->end = 1;

}


void find_all_paritial_matches(Tree* tree,char* match,result func)
{
    Node* current = tree->root;
    size_t len = strlen(match);
    for(int i = 0; i < len; ++i)
    {
        current = get_node(current,match[i]);
        if(current == NULL) {
            printf("can't find matches \n");
            return;
        }
    }

    _walk_node(func,match,current);
}

void _walk_node(result func,char* str_part,Node* n)
{
    Entries* current_entry = n->entry;

    if(n->end)
        (*func)(str_part);

    while (1)
    {

        if(current_entry == NULL)
            break;

        char temp[strlen(str_part) + 2];
        strcpy(temp,str_part);
        temp[strlen(str_part)] = current_entry->key;
        temp[strlen(str_part)+1] = '\0';

        _walk_node(func,temp,current_entry->next_node);
        current_entry = current_entry->next_entry;
    }
}

Tree* load_file(char* file)
{
    Tree* t = malloc(sizeof(Tree));
    t->root = create_node();

    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(file, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        addEntry(line,t);
    }

    fclose(fp);
    if (line)
        free(line);
    return t;

}



