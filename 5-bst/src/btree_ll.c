#include "btree_ll.h"


TreeNode* createNode(int data){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void destroyNode(TreeNode* node){
    if(node){
        destroyNode(node->left);
        destroyNode(node->right);   
        free(node);
    }
}


void printSorted(TreeNode* root){
    // TODO
}

TreeNode* insertNodeBST(TreeNode* root, int data){
    // TODO
    return NULL;
}

bool hasNode(TreeNode *root, int searchCandidate){
    // TODO
    return false;
}




