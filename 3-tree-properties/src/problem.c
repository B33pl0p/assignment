#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "btree_arr.h"

// Calculate the height of the tree given the number of nodes
int nodes2height(int nodes) {
    assert(nodes > 0); // Ensure the number of nodes is positive
    return (int)(log2(nodes + 1) - 1); // Calculate height based on formula
}

// Calculate the number of internal nodes given the number of nodes
int nodes2internal(int nodes) {
    int height = nodes2height(nodes); // Get the height of the tree
    return (1 << height) - 1; // Internal nodes are 2^height - 1
}

// Calculate the number of leaves given the number of nodes
int nodes2leaves(int nodes) {
    int height = nodes2height(nodes); // Get the height of the tree
    return (1 << height); // Leaves are 2^height
}

// DO NOT EDIT MAIN FUNCTION
int main(int argc, char** argv) {
    assert(argc == 2); // Ensure proper number of arguments
    int n = atoi(argv[1]); // number_of_nodes
    assert(n > 0); // Ensure the number of nodes is positive

    // Calculate tree properties
    int height = nodes2height(n);
    int leaves = nodes2leaves(n);   
    int internal = nodes2internal(n);
    
    // Print the properties of the binary tree
    printf("Binary Tree Properties (Nodes=%d)\n", n);
    printf("%15s: %d\n", "Height", height);
    printf("%15s: %d\n", "Internal Nodes", internal);
    printf("%15s: %d\n", "Leaves", leaves);

    return 0;
}
