#ifndef BOW_H
#define BOW_H

// LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure for the binary search tree
struct Node {
    char word[100];  // Increase word size to handle longer words
    int count;       // Frequency of the word
    struct Node* left;
    struct Node* right;
};

typedef struct Node node_t;

// FUNCTION PROTOTYPES
void node_print(node_t* node);
void bst_print(node_t* root);
node_t* bst_insert(char* word, node_t* root);
node_t* bst_search(char* word, node_t* root);
void bst_destroy(node_t* root);

// Helper Function
void remove_punct_and_make_lower_case(char *p);

#endif /* BOW_H */
