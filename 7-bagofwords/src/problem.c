#include "bagofwords.h"

// Reads the file, processes each word, and inserts it into the BST
void file_reader(char *file) {
    char word[100];  // Buffer for reading words (increased size)

    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    int i = 0;
    node_t* root = NULL;

    while (fscanf(fp, "%99s", word) != EOF) {  // Read word
        remove_punct_and_make_lower_case(word); // Clean word
        root = bst_insert(word, root);          // Insert word into BST
    }

    fclose(fp);
    bst_print(root);  // Print the BST in alphabetical order
    bst_destroy(root);  // Clean up memory
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: ./mysolution [filename]\n");
        return EXIT_FAILURE;
    }
    file_reader(argv[1]);  // Process the file
    return 0;
}
