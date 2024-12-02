#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "btree_arr.h"

// Usage ./mysolution [traversal_type] [nodes]

// Postorder traversal
void printPostorder(const BinaryTree *tree, int index) {

}

// Preorder traversal
void printPreorder(const BinaryTree *tree, int index) {
}

// Inorder traversal
void printInorder(const BinaryTree *tree, int index) {
}

// Level Order traversal
void printLevelOrder(const BinaryTree *tree) {
}


// DO NOT EDIT MAIN FUNCTION 
int main(int argc, char** argv) {

    int traversal_type = atoi(argv[1]); // subproblem
    int n = atoi(argv[2]); // number_of_nodes
    

    BinaryTree *tree = createBinaryTree(n);
    for(int i = 0; i < n; i++){
        insertNode(tree, i * 10);
    }

    switch(traversal_type){
        case 0:
            printTree(tree, 0);
            break;
        case 1:
            printf("PREORDER: ");
            printPreorder(tree, 0);
            printf("\n");
            break;
        case 2:
            printf("INORDER: ");
            printInorder(tree, 0);
            printf("\n");
            break;
        case 3:
            printf("POSTORDER: ");
            printPostorder(tree, 0);
            printf("\n");
            break;
        case 4:
            printf("LEVELORDER: ");
            printLevelOrder(tree);
            printf("\n");
            break;
    }

    return 0;
}





