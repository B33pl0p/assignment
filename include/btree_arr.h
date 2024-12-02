#ifndef BINARY_TREE_H
#define BINARY_TREE_H



typedef struct {
    int *nodes; // Dynamic array of nodes
    int capacity; // Maximum capacity of the tree
    int size; // Current number of nodes in the tree
} BinaryTree;

// Constructor/Destructor
BinaryTree *createBinaryTree(int capacity);
void deleteBinaryTree(BinaryTree *tree);

// Access
void insertNode(BinaryTree *tree, int data);
void insertNodeBST(BinaryTree *tree, int index, int data);
int getNodeData(const BinaryTree *tree, int index);


// Print 
void printTree(const BinaryTree *tree, int index);
void printPostorder(const BinaryTree *tree, int index);
void printPreorder(const BinaryTree *tree, int index);
void printInorder(const BinaryTree *tree, int index);
void printLevelOrder(const BinaryTree *tree);

// Helper
int nodes2height(int nodes);
int nodes2leaves(int nodes);
int nodes2internal(int nodes);

int isValidIndex(const BinaryTree *tree, int index);
#endif // BINARY_TREE_H
