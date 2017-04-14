//
// Created by michaelpollind on 4/13/17.
//
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

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


void find_all_paritial_matches(Tree* tree,result* func)
{
    Node* root = tree->root;
    for(int i = 0; i < sizeof(char); ++i)
    {

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

}



