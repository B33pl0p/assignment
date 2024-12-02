#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "btree_ll.h"


// DO NOT EDIT MAIN FUNCTION 
int main(int argc, char** argv) {

    int traversal_type = atoi(argv[1]); // subproblem
  
    TreeNode *root;

    switch(traversal_type){
        case 0:
            root = createNode(10);
            root->left = createNode(5);
            root->right = createNode(15);
            root->right->left = createNode(12);
            root->right->right = createNode(20);
            printf("SORT:\n");
            printSorted(root);
            printf("\n");
            break;
        case 1:
            root = NULL;
            for(int i = 2; i < argc; i++){
                root = insertNodeBST(root, atoi(argv[i]));
            }
            printf("INSERT AND SORT:\n");
            printSorted(root);
            printf("\n");
            break;
        case 2:
            root = NULL;
            for(int i = 2; i < argc-1; i++){
                root = insertNodeBST(root, atoi(argv[i]));
            }
            printf("SEARCH:\n");
            int searchCandidate = atoi(argv[argc-1]);
            if(hasNode(root, searchCandidate)){
                printf("%d is in the tree\n", searchCandidate);
            } else {
                printf("%d is not in the tree\n", searchCandidate);
            }
            break;
    }

    return 0;
}





