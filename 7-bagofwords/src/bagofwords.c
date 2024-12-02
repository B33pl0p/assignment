#include "bagofwords.h"

// Searches for a word in the BST. Returns the node if found, NULL otherwise.
node_t* bst_search(char* word, node_t* root) {
    if (root == NULL) {
        return NULL;
    }

    if (strcmp(word, root->word) == 0) {
        return root;
    }

    if (strcmp(word, root->word) < 0) {
        return bst_search(word, root->left);  // Search left
    } else {
        return bst_search(word, root->right); // Search right
    }
}

// Inserts a word into the BST. If the word already exists, increments its count.
node_t* bst_insert(char* word, node_t* root) {
    if (root == NULL) {
        node_t* new_node = malloc(sizeof(node_t));
        if (new_node == NULL) {
            fprintf(stderr, "Error allocating memory!\n");
            exit(EXIT_FAILURE);
        }
        strcpy(new_node->word, word);
        new_node->count = 1; // Initialize count to 1 for the new word
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if (strcmp(word, root->word) == 0) {
        root->count++;  // Increment count if word exists
        return root;
    }

    if (strcmp(word, root->word) < 0) {
        root->left = bst_insert(word, root->left); // Insert left
    } else {
        root->right = bst_insert(word, root->right); // Insert right
    }

    return root;
}

// Prints BST sorted (in-order traversal)
void bst_print(node_t* root) {
    if (root != NULL) {
        bst_print(root->left);
        node_print(root);
        bst_print(root->right);
    }
}

// Releases memory held by tree
void bst_destroy(node_t* root) {
    if (root != NULL) {
        bst_destroy(root->left);
        bst_destroy(root->right);
        free(root);
    }
}

// Prints the frequency of occurrence of a given word
void node_print(node_t* node) {
    printf("%s -- %d\n", node->word, node->count);
}
