#ifndef BINARY_TREE_LL_H
#define BINARY_TREE_LL_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

typedef struct {
    TreeNode *root; // Pointer to the root node
    int size; // Current number of nodes in the tree
} BinaryTree;

// Function prototypes
TreeNode* createNode(int data);
void destroyNode(TreeNode* node);
TreeNode* insertNodeBST(TreeNode* root, int data);
void printSorted(TreeNode* root);
bool hasNode(TreeNode *root, int searchCandidate);


#endif // BINARY_TREE_H
